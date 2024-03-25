/**
  * @file <src/modules/AutoMoDeBehaviourTuttiStop.h>
  *
  * @author Antoine Ligot - <aligot@ulb.ac.be>
  *
  * @package ARGoS3-AutoMoDe
  *
  * @license MIT License
  */


#ifndef AUTOMODE_BEHAVIOUR_TUTTISTOP_H
#define AUTOMODE_BEHAVIOUR_TUTTISTOP_H

#include "AutoMoDeBehaviour.h"

namespace argos {
	class AutoMoDeBehaviourTuttiStop: public AutoMoDeBehaviour {
		public:
			AutoMoDeBehaviourTuttiStop();
			AutoMoDeBehaviourTuttiStop(AutoMoDeBehaviourTuttiStop* pc_behaviour);
			virtual ~AutoMoDeBehaviourTuttiStop();

			virtual void ControlStep();
			virtual void Reset();
			virtual void ResumeStep();
			virtual void Init();


			virtual AutoMoDeBehaviourTuttiStop* Clone();

        private:
            CColor m_cColorEmiterParameter;
						size_t m_bGroundLEDsParameter;
	};
}


#endif
