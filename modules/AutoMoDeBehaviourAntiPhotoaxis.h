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

			virtual void ControlStep();
			virtual void Reset();
			virtual void ResumeStep();
			virtual void Init();

			virtual AutoMoDeBehaviourAntiPhotoaxis* Clone();
	};
}

#endif
