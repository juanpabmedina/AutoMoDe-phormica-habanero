/*
 * File: AutoMoDeBehaviourAttraction.h
 *
 */
 
#ifndef AUTOMODE_BEHAVIOUR_ATTRACTION_H
#define AUTOMODE_BEHAVIOUR_ATTRACTION_H

#include "AutoMoDeBehaviour.h"

namespace argos {
	class AutoMoDeBehaviourAttraction: public AutoMoDeBehaviour {
		public: 
			AutoMoDeBehaviourAttraction();
			AutoMoDeBehaviourAttraction(AutoMoDeBehaviourAttraction* pc_behaviour);
			virtual ~AutoMoDeBehaviourAttraction();
			
			virtual void ControlStep(AutoMoDeRobotDAO* pc_robot_dao);
			virtual void Reset();
			virtual void ResumeStep();
			virtual void Init();
			
			virtual AutoMoDeBehaviourAttraction* Clone();
	};
}

#endif
