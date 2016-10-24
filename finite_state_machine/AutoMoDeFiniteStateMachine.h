/**
 * @file AutoMoDeFiniteStateMachine.h
 *
 * @brief This class represents the stochastic finite state
 * machine that controls the robot. It contains all the modules
 * (behaviours and conditions) and is responsible for the transitions
 * between them.
 */

#ifndef AUTOMODE_FINITE_STATE_MACHINE_H
#define AUTOMODE_FINITE_STATE_MACHINE_H

#include "AutoMoDeRobotDAO.h"
#include "AutoMoDeFsmHistory.h"
#include "../modules/AutoMoDeBehaviour.h"
#include "../modules/AutoMoDeBehaviourAttraction.h"
#include "../modules/AutoMoDeBehaviourAntiPhotoaxis.h"
#include "../modules/AutoMoDeBehaviourExploration.h"
#include "../modules/AutoMoDeBehaviourPhotoaxis.h"
#include "../modules/AutoMoDeBehaviourRepulsion.h"
#include "../modules/AutoMoDeBehaviourStop.h"
#include "../modules/AutoMoDeCondition.h"
#include "../modules/AutoMoDeConditionBlackFloor.h"
#include "../modules/AutoMoDeConditionGrayFloor.h"
#include "../modules/AutoMoDeConditionWhiteFloor.h"
#include "../modules/AutoMoDeConditionFixedProbability.h"
#include "../modules/AutoMoDeConditionNeighborsCount.h"
#include "../modules/AutoMoDeConditionInvertedNeighborsCount.h"

#include <string>
#include <algorithm>

namespace argos {
	class AutoMoDeFiniteStateMachine {
		public:
			AutoMoDeFiniteStateMachine();
			virtual ~AutoMoDeFiniteStateMachine();
			AutoMoDeFiniteStateMachine(AutoMoDeFiniteStateMachine* pc_fsm);
			
			void AddCondition(AutoMoDeCondition* pc_new_condition);
			void AddBehaviour(AutoMoDeBehaviour* pc_new_behaviour);
			
			void ControlStep(AutoMoDeRobotDAO* pc_robot_dao);
			void Init();
			void Reset();
			
			/**
			 * Creates an URL containing a DOT description of the finite state machine.
			 */
			std::string GetReadableFormat();
			
			/**
			 * Creates a AutoMoDeFsmHistory.
			 */
			void MaintainHistory();
			
			UInt8 GetCurrentBehaviourIndex();
			bool GetMaintainHistoryFlag();
			bool GetEnteringNewStateFlag();
			UInt32 GetTimeStep();
			
			std::vector<AutoMoDeBehaviour*> GetBehaviours();
			std::vector<AutoMoDeCondition*> GetConditions();
			
			AutoMoDeFsmHistory* GetHistory();
			
		private:
			void CheckConditions(AutoMoDeRobotDAO* pc_robot_state);  
			std::vector<AutoMoDeCondition*> GetOutgoingConditions(); 
			
			std::string FillWithInitialState();
			std::string FillWithNonInitialStates();
			std::string FillWithConditions();
		
			std::vector<AutoMoDeBehaviour*> m_vecBehaviours;
			std::vector<AutoMoDeCondition*> m_vecConditions;
			
			AutoMoDeBehaviour* m_pcCurrentBehaviour;
			std::vector<AutoMoDeCondition*> m_vecCurrentConditions;
			
			AutoMoDeFsmHistory* m_pcHistory;
			
			UInt8 m_unCurrentBehaviourIndex;
			bool m_bMaintainHistory;
			bool m_bEnteringNewState;	
			UInt32 m_unTimeStep;
			
			std::map<AutoMoDeCondition*, bool> m_mapConditionsChecked;
	};
}

#endif
