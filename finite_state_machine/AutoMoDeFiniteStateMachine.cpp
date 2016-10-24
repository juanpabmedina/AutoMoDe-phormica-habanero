/*
 * File: CEpuckFiniteStateMachine.cpp
 *
 */

#include "AutoMoDeFiniteStateMachine.h"

namespace argos {
	
	
	AutoMoDeFiniteStateMachine::AutoMoDeFiniteStateMachine() {
		m_unCurrentBehaviourIndex = 0;
		m_bEnteringNewState = true;
		m_bMaintainHistory = false;
		m_unTimeStep = 0;
	}
	
	AutoMoDeFiniteStateMachine::~AutoMoDeFiniteStateMachine() {}
	
	AutoMoDeFiniteStateMachine::AutoMoDeFiniteStateMachine(AutoMoDeFiniteStateMachine* pc_fsm) {
		m_unCurrentBehaviourIndex = pc_fsm->GetCurrentBehaviourIndex();
		m_bEnteringNewState = pc_fsm->GetEnteringNewStateFlag();
		m_bMaintainHistory = pc_fsm->GetMaintainHistoryFlag();
		m_unTimeStep = pc_fsm->GetTimeStep();
		
		std::vector<AutoMoDeBehaviour*> vecBehaviours = pc_fsm->GetBehaviours();
		m_vecBehaviours.clear();
		for (std::vector<AutoMoDeBehaviour*>::iterator it = vecBehaviours.begin(); it != vecBehaviours.end(); ++it) {
			m_vecBehaviours.push_back((*it)->Clone());
		}
		m_pcCurrentBehaviour = m_vecBehaviours.at(m_unCurrentBehaviourIndex);
		
		std::vector<AutoMoDeCondition*> vecConditions = pc_fsm->GetConditions();
		m_vecConditions.clear();
		for (std::vector<AutoMoDeCondition*>::iterator it = vecConditions.begin(); it != vecConditions.end(); ++it) {
			m_vecConditions.push_back((*it)->Clone());
		}
		m_pcHistory = new AutoMoDeFsmHistory(pc_fsm->GetHistory());
	}
	
	void AutoMoDeFiniteStateMachine::ControlStep(AutoMoDeRobotDAO* pc_robot_dao){ 
		/*
		 * 1. Execute current behaviour
		 * 2. Check for conditions if current behaviour allows it
		 * 3. Update current behaviour if one condition passed
		 * 4. Add entry to history if enabled 
		 * 5. Update internal variables 
		 */
		 
		/*
		 * 1. Dealing with behaviours
		 */
		if (m_bEnteringNewState) {
			m_pcCurrentBehaviour->Reset();
		} 
		
		if (m_pcCurrentBehaviour->IsOperational()) {
			m_pcCurrentBehaviour->ControlStep(pc_robot_dao);
		} else {
			m_pcCurrentBehaviour->ResumeStep();
		}
		
		/*
		 * 2. Dealing with conditions
		 */
		m_mapConditionsChecked.clear();
		if (!m_pcCurrentBehaviour->IsLocked()) {
			if (m_bEnteringNewState) { 
				m_vecCurrentConditions = GetOutgoingConditions();
				m_bEnteringNewState = false;
			}
			else {
				std::random_shuffle(m_vecCurrentConditions.begin(), m_vecCurrentConditions.begin());
				for (std::vector<AutoMoDeCondition*>::iterator it = m_vecCurrentConditions.begin(); it != m_vecCurrentConditions.end(); it++) {
					/*
					 * 3. Update current behaviour
					 */
					if ((*it)->Verify()) {
						m_mapConditionsChecked.insert(std::pair<AutoMoDeCondition*, bool>((*it), true));
						m_unCurrentBehaviourIndex = (*it)->GetExtremity();
						m_pcCurrentBehaviour = m_vecBehaviours.at(m_unCurrentBehaviourIndex);
						m_bEnteringNewState = true;
						break;
					} else {
						m_mapConditionsChecked.insert(std::pair<AutoMoDeCondition*, bool>((*it), false));
					}
				}
			}
		}
		
		/*
		 * 4. Dealing with history
		 */
		if (m_bMaintainHistory) {
			m_pcHistory->AddTimeStep(m_unTimeStep, m_pcCurrentBehaviour, m_mapConditionsChecked);
		}
		
		/*
		 * 5. Dealing with variables
		 */
		m_unTimeStep += 1;
	}
	
	void AutoMoDeFiniteStateMachine::Init() {
		m_pcCurrentBehaviour = m_vecBehaviours.at(m_unCurrentBehaviourIndex);
	}
	
	void AutoMoDeFiniteStateMachine::Reset() {
		LOG << "FSM Reset" << std::endl;
		m_unCurrentBehaviourIndex = 0;
		m_pcCurrentBehaviour = m_vecBehaviours.at(m_unCurrentBehaviourIndex);
		std::vector<AutoMoDeCondition*>::iterator itC;
		for (itC = m_vecConditions.begin(); itC != m_vecConditions.end(); ++itC) {
			(*itC)->Reset();
		}
		std::vector<AutoMoDeBehaviour*>::iterator itB;
		for (itB = m_vecBehaviours.begin(); itB != m_vecBehaviours.end(); ++itB) {
			(*itB)->Reset();
		}
	}
	
	std::vector<AutoMoDeCondition*> AutoMoDeFiniteStateMachine::GetOutgoingConditions() {
		std::vector<AutoMoDeCondition*>::iterator it;
		std::vector<AutoMoDeCondition*> vecResult;
		UInt8 unConditionOrigin;
		
		for (it = m_vecConditions.begin(); it != m_vecConditions.end(); ++it) {
			unConditionOrigin = (*it)->GetOrigin();
			if (unConditionOrigin == m_unCurrentBehaviourIndex) {
				vecResult.push_back(*it);
			}
		}
		
		return vecResult;
	}
	
	std::string AutoMoDeFiniteStateMachine::GetReadableFormat(){
		std::stringstream ssUrl;
		ssUrl << "http://chart.googleapis.com/chart?cht=gv:dot&chl=digraph finite_state_machine{rankir=LR;" ;
		ssUrl << FillWithInitialState();
		ssUrl << FillWithNonInitialStates();
		ssUrl << FillWithConditions();
		ssUrl << "}" ;
		std::string strUrl = ssUrl.str();
		std::replace(strUrl.begin(), strUrl.end(), ' ', '+');
		return strUrl;
	}
	
	void AutoMoDeFiniteStateMachine::MaintainHistory() {
		m_bMaintainHistory = true;
		m_pcHistory = new AutoMoDeFsmHistory("./fsm_history/fsm_history.txt");
	}
	
	void AutoMoDeFiniteStateMachine::AddCondition(AutoMoDeCondition* pc_new_condition){
		m_vecConditions.push_back(pc_new_condition);
	}
	
	void AutoMoDeFiniteStateMachine::AddBehaviour(AutoMoDeBehaviour* pc_new_behaviour){
		m_vecBehaviours.push_back(pc_new_behaviour);
	}
	
	std::string AutoMoDeFiniteStateMachine::FillWithInitialState() {
		std::stringstream ssUrl;
		ssUrl << "node [shape = doublecircle]; " ;
		std::vector<AutoMoDeBehaviour*>::iterator it;
		for (it = m_vecBehaviours.begin(); it != m_vecBehaviours.end(); it++) {
			if ((*it)->GetIndex() == 0) {
				ssUrl << "S0 [label=\"" << (*it)->GetUrlDescription() << "\"; color=blue];" ;
				break;
			}
		}
		return ssUrl.str();
	}
	
	std::string AutoMoDeFiniteStateMachine::FillWithNonInitialStates() {
		std::stringstream ssUrl;
		ssUrl << "node [shape = circle];" ;
		std::vector<AutoMoDeBehaviour*>::iterator it;
		for (it = m_vecBehaviours.begin(); it != m_vecBehaviours.end(); it++) {
			if ((*it)->GetIndex() != 0) {
				ssUrl << "S" << (*it)->GetIndex() << " [label=\"" << (*it)->GetUrlDescription() << "\"; color=blue]" ;
			}
		}
		ssUrl << ";"; 
		return ssUrl.str();
	}
	
	std::string AutoMoDeFiniteStateMachine::FillWithConditions() {
		std::stringstream ssUrl;
		std::vector<AutoMoDeCondition*>::iterator it;
		
		// Creation of conditions
		ssUrl << "node [shape = diamond];" ;
		for (it = m_vecConditions.begin(); it != m_vecConditions.end(); it++) {
			ssUrl << "C" << (*it)->GetOrigin() << "x" << (*it)->GetIndex() << " [label=\"" << (*it)->GetUrlDescription() << "\"; color=green];" ;
		}
		
		// Creation of transitions between behaviours and conditions
		for (it = m_vecConditions.begin(); it != m_vecConditions.end(); it++) {
			ssUrl << "S" << (*it)->GetOrigin() << " -> C" << (*it)->GetOrigin() << "x" << (*it)->GetIndex() << ";" ;
			ssUrl << "C" << (*it)->GetOrigin() << "x" << (*it)->GetIndex() << " -> S" << (*it)->GetExtremity() << ";" ;
		}

		return ssUrl.str();
	}
	
	UInt8 AutoMoDeFiniteStateMachine::GetCurrentBehaviourIndex() {
		return m_unCurrentBehaviourIndex;
	}
	
	bool AutoMoDeFiniteStateMachine::GetMaintainHistoryFlag() {
		return m_bMaintainHistory;
	}
	
	bool AutoMoDeFiniteStateMachine::GetEnteringNewStateFlag() {
		return m_bEnteringNewState;
	}
	
	UInt32 AutoMoDeFiniteStateMachine::GetTimeStep() {
		return m_unTimeStep;
	}
	
	std::vector<AutoMoDeBehaviour*> AutoMoDeFiniteStateMachine::GetBehaviours() {
		return m_vecBehaviours;
	}
	
	std::vector<AutoMoDeCondition*> AutoMoDeFiniteStateMachine::GetConditions() {
		return m_vecConditions;
	}
	
	AutoMoDeFsmHistory* AutoMoDeFiniteStateMachine::GetHistory() {
		return m_pcHistory;
	}
}
