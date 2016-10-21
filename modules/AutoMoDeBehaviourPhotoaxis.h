/*
 * File: AutoMoDeBehaviourPhotoaxis.h
 *
 */
 
#ifndef AUTOMODE_BEHAVIOUR_PHOTOAXIS_H
#define AUTOMODE_BEHAVIOUR_PHOTOAXIS_H

#include "AutoMoDeBehaviour.h"

namespace argos {
	class AutoMoDeBehaviourPhotoaxis: public AutoMoDeBehaviour {
		public: 
			AutoMoDeBehaviourPhotoaxis();
			AutoMoDeBehaviourPhotoaxis(AutoMoDeBehaviourPhotoaxis* pc_behaviour);
			virtual ~AutoMoDeBehaviourPhotoaxis();
			
			virtual void ControlStep(AutoMoDeRobotDAO* pc_robot_dao);
			virtual void Reset();
			virtual void ResumeStep();
			
			virtual AutoMoDeBehaviourPhotoaxis* Clone();
	};
}

#endif