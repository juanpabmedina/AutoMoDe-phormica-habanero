/*
 * File: CEpuckFsmBuilder.cpp
 *
 */

#include "AutoMoDeFsmBuilder.h"

namespace argos {
	
	
	AutoMoDeFsmBuilder::AutoMoDeFsmBuilder() {}
	
	AutoMoDeFsmBuilder::~AutoMoDeFsmBuilder() {}
	
	AutoMoDeFiniteStateMachine* AutoMoDeFsmBuilder::BuildFiniteStateMachine(std::string str_fsm_config) {
		std::istringstream iss(str_fsm_config);
		std::vector<std::string> tokens;
		copy(std::istream_iterator<std::string>(iss),
			std::istream_iterator<std::string>(),
			std::back_inserter(tokens));
		return BuildFiniteStateMachine(tokens);
	}
	
	AutoMoDeFiniteStateMachine* AutoMoDeFsmBuilder::BuildFiniteStateMachine(std::vector<std::string>& vec_fsm_config) {
		AutoMoDeFiniteStateMachine* cFiniteStateMachine = new AutoMoDeFiniteStateMachine();
		
		std::vector<std::string>::iterator it;
		UInt8 unNumberStates;
		try {
			it = std::find(vec_fsm_config.begin(), vec_fsm_config.end(), "--nstates");
			unNumberStates = atoi((*(it+1)).c_str());
			std::vector<std::string>::iterator first_state;
			std::vector<std::string>::iterator second_state;
			for (UInt8 i = 0; i < unNumberStates; i++) {
				std::ostringstream oss;
				oss << "--s" << i;
				first_state = std::find(vec_fsm_config.begin(), vec_fsm_config.end(), oss.str());
				if (i+1 < unNumberStates) {
					std::ostringstream oss;
					oss << "--s" << i+1;
					second_state = std::find(vec_fsm_config.begin(), vec_fsm_config.end(), oss.str());
				} else {
					second_state = vec_fsm_config.end();
				}
				std::vector<std::string> vecStateConfig(first_state, second_state);
				HandleState(cFiniteStateMachine, vecStateConfig);
			}
		}
		catch (std::exception e) {
			THROW_ARGOSEXCEPTION("Could not create the Finite State Machine: Error while parsing.");
		}
		
		return cFiniteStateMachine;
		
	}
	
	void AutoMoDeFsmBuilder::HandleState(AutoMoDeFiniteStateMachine* c_fsm, std::vector<std::string>& vec_fsm_state_config) {
		AutoMoDeBehaviour* cNewBehaviour;
		std::vector<std::string>::iterator it;
		// Extraction of the index of the behaviour in the FSM
		UInt8 unBehaviourIndex =  atoi((*vec_fsm_state_config.begin()).substr(3,4).c_str());
		// Extraction of the identifier of the behaviour
		UInt8 unBehaviourIdentifier =  atoi((*(vec_fsm_state_config.begin()+1)).c_str());
		
		// Creation of the Behaviour object
		switch(unBehaviourIdentifier) {
			case 0:
				cNewBehaviour = new AutoMoDeBehaviourExploration();
				break;
			case 1:
				cNewBehaviour = new AutoMoDeBehaviourStop();
				break;
			case 2:
				cNewBehaviour = new AutoMoDeBehaviourPhotoaxis();
				break;	
			case 3:
				cNewBehaviour = new AutoMoDeBehaviourAntiPhotoaxis();
				break;
			case 4:
				cNewBehaviour = new AutoMoDeBehaviourAttraction();
				break;
			case 5:
				cNewBehaviour = new AutoMoDeBehaviourRepulsion();
				break;
		}
		cNewBehaviour->SetIndex(unBehaviourIndex);
		cNewBehaviour->SetIdentifier(unBehaviourIdentifier);
		
		// Checking for parameters
		std::string vecPossibleParameters[] = {"rwm", "att", "rep"};
		UInt8 unNumberPossibleParameters = 3;  // Change that later...
		for (UInt8 i = 0; i < unNumberPossibleParameters; i++) {
			std::string strCurrentParameter = vecPossibleParameters[i];
			std::ostringstream oss;
			oss << "--" <<strCurrentParameter << unBehaviourIndex;
			it = std::find(vec_fsm_state_config.begin(), vec_fsm_state_config.end(), oss.str());
			if (it != vec_fsm_state_config.end()) {
				Real fCurrentParameterValue = strtod((*(it+1)).c_str(), NULL);
				cNewBehaviour->AddParameter(strCurrentParameter, fCurrentParameterValue);
			}
		}
				
		// Add the constructed Behaviour to the FSM
		c_fsm->AddBehaviour(cNewBehaviour);		
		
			
		//std::cout << " * * * State * * * " << std::endl;
		//for (std::vector<std::string>::iterator it = vec_fsm_state_config.begin(); it != vec_fsm_state_config.end(); it++) {
		//	std::cout << *it << " ";
		//}
		//std::cout << std::endl;
	
		/*
		 * Extract the transitions starting from the state and 
		 * pass them to the transition handler.
		 */
		std::ostringstream oss;
		oss << "--n" << unBehaviourIndex;
		it = std::find(vec_fsm_state_config.begin(), vec_fsm_state_config.end(), oss.str());
		UInt8 unNumberTransitions = atoi((*(it+1)).c_str());
		
		std::vector<std::string>::iterator first_transition;
		std::vector<std::string>::iterator second_transition;
		
		for (UInt8 i = 0; i < unNumberTransitions; i++) {
			std::ostringstream oss;
			oss << "--n" << unBehaviourIndex << "x" << i;
			first_transition = std::find(vec_fsm_state_config.begin(), vec_fsm_state_config.end(), oss.str());
			if (i+1 < unNumberTransitions) {
				std::ostringstream oss;
				oss << "--n" << unBehaviourIndex << "x" << i+1;
				second_transition = std::find(vec_fsm_state_config.begin(), vec_fsm_state_config.end(), oss.str());
			} else {
				second_transition = vec_fsm_state_config.end();
			}
			std::vector<std::string> vecTransitionConfig(first_transition, second_transition);
			HandleTransition(c_fsm, vecTransitionConfig, unBehaviourIndex, i);
		}
	}

	void AutoMoDeFsmBuilder::HandleTransition(AutoMoDeFiniteStateMachine* c_fsm, std::vector<std::string>& vec_fsm_transition_config, UInt8 un_initial_state_index, UInt8 un_condition_index) {
		//std::cout << " * * * Transition * * * " << std::endl;
		//for (std::vector<std::string>::iterator i = vec_fsm_transition_config.begin(); i != vec_fsm_transition_config.end(); i++) {
		//	std::cout << *i << " ";
		//}
		//std::cout << std::endl;
		
		AutoMoDeCondition* cNewCondition;
		
		std::stringstream ss;
		ss << "--n" << un_initial_state_index << "x" << un_condition_index;
		std::vector<std::string>::iterator it;
		it = std::find(vec_fsm_transition_config.begin(), vec_fsm_transition_config.end(), ss.str());
		
		UInt8 unToBehaviour = atoi((*(it+1)).c_str());
		
		ss.str(std::string());
		ss << "--c" << un_initial_state_index << "x" << un_condition_index;
		it = std::find(vec_fsm_transition_config.begin(), vec_fsm_transition_config.end(), ss.str());
		
		UInt8 unConditionIdentifier = atoi((*(it+1)).c_str());
		
		switch(unConditionIdentifier) {
			case 0:
				cNewCondition = new AutoMoDeConditionBlackFloor();
				break;
			case 1:
				cNewCondition = new AutoMoDeConditionGrayFloor();
				break;
			case 2:
				cNewCondition = new AutoMoDeConditionWhiteFloor();
				break;
			case 3:
				cNewCondition = new AutoMoDeConditionNeighborsCount();
				break;
			case 4:
				cNewCondition = new AutoMoDeConditionInvertedNeighborsCount();
				break;
			case 5:
				cNewCondition = new AutoMoDeConditionFixedProbability();
				break;
		}
		
		cNewCondition->SetOriginAndExtremity(un_initial_state_index, unToBehaviour);
		cNewCondition->SetIndex(un_condition_index);
		cNewCondition->SetIdentifier(unConditionIdentifier);
		
				
		// Checking for parameters
		std::string vecPossibleParameters[] = {"p", "w"};
		UInt8 unNumberPossibleParameters = 2;  // Change that later...
		for (UInt8 i = 0; i < unNumberPossibleParameters; i++) {
			std::string strCurrentParameter = vecPossibleParameters[i];
			ss.str(std::string());
			ss << "--" << strCurrentParameter << un_initial_state_index << "x" << un_condition_index;
			it = std::find(vec_fsm_transition_config.begin(), vec_fsm_transition_config.end(), ss.str());
			if (it != vec_fsm_transition_config.end()) {
				Real fCurrentParameterValue = strtod((*(it+1)).c_str(), NULL);
				cNewCondition->AddParameter(strCurrentParameter, fCurrentParameterValue);
			}
		}
		
		c_fsm->AddCondition(cNewCondition);
		
	}

}