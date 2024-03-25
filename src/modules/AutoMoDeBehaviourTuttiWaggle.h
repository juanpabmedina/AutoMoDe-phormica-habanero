/**
  * @file <src/modules/AutoMoDeBehaviourTuttiWaggle.h>
  *
  * @author Antoine Ligot - <aligot@ulb.ac.be>
  *
  * @package ARGoS3-AutoMoDe
  *
  * @license MIT License
  */


#ifndef AUTOMODE_BEHAVIOUR_TUTTIWAGGLE_H
#define AUTOMODE_BEHAVIOUR_TUTTIWAGGLE_H

#include "AutoMoDeBehaviour.h"

namespace argos {
	class AutoMoDeBehaviourTuttiWaggle: public AutoMoDeBehaviour {
		public:
			AutoMoDeBehaviourTuttiWaggle();
			AutoMoDeBehaviourTuttiWaggle(AutoMoDeBehaviourTuttiWaggle* pc_behaviour);
			virtual ~AutoMoDeBehaviourTuttiWaggle();

			virtual void ControlStep();
			virtual void Reset();
			virtual void ResumeStep();
			virtual void Init();


			virtual AutoMoDeBehaviourTuttiWaggle* Clone();

        private:
            CColor m_cColorEmiterParameter;
						size_t m_bGroundLEDsParameter;
						bool m_bRotationDirectionParameter;
	};
}


#endif
