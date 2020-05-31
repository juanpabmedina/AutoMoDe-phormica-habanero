/**
  * @file <src/modules/AutoMoDeBehaviourWaggle.h>
  *
  * @author Antoine Ligot - <aligot@ulb.ac.be>
  *
  * @package ARGoS3-AutoMoDe
  *
  * @license MIT License
  */


#ifndef AUTOMODE_BEHAVIOUR_WAGGLE_H
#define AUTOMODE_BEHAVIOUR_WAGGLE_H

#include "AutoMoDeBehaviour.h"

namespace argos {
	class AutoMoDeBehaviourWaggle: public AutoMoDeBehaviour {
		public:
			AutoMoDeBehaviourWaggle();
			AutoMoDeBehaviourWaggle(AutoMoDeBehaviourWaggle* pc_behaviour);
			virtual ~AutoMoDeBehaviourWaggle();

			virtual void ControlStep();
			virtual void Reset();
			virtual void ResumeStep();
			virtual void Init();


			virtual AutoMoDeBehaviourWaggle* Clone();

        private:
            CColor m_cColorEmiterParameter;
						size_t m_bGroundLEDsParameter;
						bool m_bRotationDirectionParameter;
	};
}


#endif
