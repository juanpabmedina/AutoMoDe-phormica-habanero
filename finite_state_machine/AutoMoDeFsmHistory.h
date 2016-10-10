/*
 * File: AutoMoDeFsmHistory.h
 *
 */

#ifndef AUTOMODE_FSM_HISTORY_H
#define AUTOMODE_FSM_HISTORY_H

#include "../modules/AutoMoDeBehaviour.h"
#include "../modules/AutoMoDeCondition.h"

#include <argos3/core/utility/logging/argos_log.h>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

namespace argos {
	class AutoMoDeFsmHistory {
		public:
			AutoMoDeFsmHistory();
			AutoMoDeFsmHistory(std::string str_path);
			AutoMoDeFsmHistory(AutoMoDeFsmHistory* pc_fsm_history);
			
			virtual ~AutoMoDeFsmHistory();
		
			void AddTimeStep(UInt8 un_time_step, AutoMoDeBehaviour* pc_current_state, std::map<AutoMoDeCondition*, bool> map_transition_status);
			void AddTimeStep(UInt8 un_time_step, AutoMoDeBehaviour* pc_current_state);
			
			void OpenFile();
			const std::string GetPath();
			
		private:
			std::string m_strPath;
			std::ofstream m_ofHistoryFile;
	};
}

#endif
