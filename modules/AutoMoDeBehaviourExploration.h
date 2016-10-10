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
	};
}

#endif
