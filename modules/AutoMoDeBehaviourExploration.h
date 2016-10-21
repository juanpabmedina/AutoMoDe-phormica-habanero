/*
 * File: AutoMoDeBehaviourExploration.h
 *
 */
 
#ifndef AUTOMODE_BEHAVIOUR_EXPLORATION_H
#define AUTOMODE_BEHAVIOUR_EXPLORATION_H

#include "AutoMoDeBehaviour.h"

namespace argos {
	class AutoMoDeBehaviourExploration: public AutoMoDeBehaviour {
		public: 
			AutoMoDeBehaviourExploration();
			AutoMoDeBehaviourExploration(AutoMoDeBehaviourExploration* pc_behaviour);
			virtual ~AutoMoDeBehaviourExploration();
			
			virtual void ControlStep(AutoMoDeRobotDAO* pc_robot_dao);
			virtual void Reset();
			virtual void ResumeStep();
			
			virtual AutoMoDeBehaviourExploration* Clone();
			
			void Init();
			
		private:
			SInt32 m_unTurnSteps;
			
			enum ExplorationState {
				RANDOM_WALK,
				OBSTACLE_AVOIDANCE
			};
			
			enum TurnDirection {
				LEFT,
				RIGHT
			};
			
			ExplorationState m_eExplorationState;
			TurnDirection m_eTurnDirection;
			
			Real m_fWheelSpeed;
			Real m_fProximityThreshold;
			CRange<UInt32> m_cRandomStepsRange;
			
			bool IsObstacleInFront(CCI_EPuckProximitySensor::TReadings s_prox_input);
	};
}

#endif
