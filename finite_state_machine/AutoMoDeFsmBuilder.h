/**
 * @file AutoMoDeFsmBuilder.h
 *
 * @brief This class is used to parse the configuration of
 * the stochastic finite state machine and instanciate the 
 * different modules (behaviours and conditions). These modules
 * are added to the AutoMoDeFiniStateMachine created.
 */

#ifndef AUTOMODE_FSM_BUILDER_H
#define AUTOMODE_FSM_BUILDER_H

#include "AutoMoDeFiniteStateMachine.h"

#include <argos3/core/utility/logging/argos_log.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <iterator>
#include <stdlib.h>

namespace argos {
	class AutoMoDeFsmBuilder {
		public:
			AutoMoDeFsmBuilder();
			
			/**
			 * Creates an AutoMoDeFiniteStateMachine based on a configuration as a vector of strings.
			 * This method should be called when the FSM is created from the main.cpp.  
			 */
			AutoMoDeFiniteStateMachine* BuildFiniteStateMachine(std::vector<std::string>& vec_fsm_config);
			
			/**
			 * Creates an AutoMoDeFiniteStateMachine based on a configuration as a string.
			 * This method should be called when the FSM is created from the AutoMoDeController.cpp.  
			 */
			AutoMoDeFiniteStateMachine* BuildFiniteStateMachine(std::string str_fsm_config);
			
			virtual ~AutoMoDeFsmBuilder();
		
		private:
			/**
			 * Creates a AutoMoDeBehaviour from a state configuration and add it to the 
			 * AutoMoDeFiniStateMachine in construction. 
			 * Strips the different transitions and calls HandleTransition for their creation.
			 */
			void HandleState(AutoMoDeFiniteStateMachine* c_fsm, std::vector<std::string>& vec_fsm_state_config);
			
			/**
			 * Creates a AutoMoDeCondition from a transition configuration and add it to the 
			 * AutoMoDeFiniStateMachine in construction. 
			 */
			void HandleTransition(AutoMoDeFiniteStateMachine* c_fsm, std::vector<std::string>& vec_fsm_transition_config, 
									UInt8 un_initial_state_index, UInt8 un_condition_index);
	};
}

#endif
