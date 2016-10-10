/*
 * File: AutoMoDeBehaviourAntiPhotoaxis.h
 *
 */
 
#ifndef AUTOMODE_BEHAVIOUR_ANTI_PHOTOAXIS_H
#define AUTOMODE_BEHAVIOUR_ANTI_PHOTOAXIS_H

#include "AutoMoDeBehaviour.h"

namespace argos {
	class AutoMoDeBehaviourAntiPhotoaxis: public AutoMoDeBehaviour {
		public: 
			AutoMoDeBehaviourAntiPhotoaxis();
			AutoMoDeBehaviourAntiPhotoaxis(AutoMoDeBehaviourAntiPhotoaxis* pc_behaviour);
			virtual ~AutoMoDeBehaviourAntiPhotoaxis();
			
			virtual void ControlStep(AutoMoDeRobotDAO* pc_robot_dao);
			virtual void Reset();
			virtual void ResumeStep();
			
			virtual AutoMoDeBehaviourAntiPhotoaxis* Clone();
	};
}

#endif
