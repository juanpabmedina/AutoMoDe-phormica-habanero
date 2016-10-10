/*
 * File: AutoMoDeFsmBuilder.h
 *
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
			
			AutoMoDeFiniteStateMachine* BuildFiniteStateMachine(std::vector<std::string>& vec_fsm_config);
			AutoMoDeFiniteStateMachine* BuildFiniteStateMachine(std::string str_fsm_config);
			
			virtual ~AutoMoDeFsmBuilder();
		
		private:
			void HandleState(AutoMoDeFiniteStateMachine* c_fsm, std::vector<std::string>& vec_fsm_state_config);
			void HandleTransition(AutoMoDeFiniteStateMachine* c_fsm, std::vector<std::string>& vec_fsm_transition_config, 
									UInt8 un_initial_state_index, UInt8 un_condition_index);
	};
}

#endif
