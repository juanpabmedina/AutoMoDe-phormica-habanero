/**
  * @file <src/modules/AutoMoDeBehaviourRepulsionColor.h>
  *
  * @author Antoine Ligot - <aligot@ulb.ac.be>
  *
  * @package ARGoS3-AutoMoDe
  *
  * @license MIT License
  */

#ifndef AUTOMODE_BEHAVIOUR_TUTTIGOAWAY_COLOR_H
#define AUTOMODE_BEHAVIOUR_TUTTIGOAWAY_COLOR_H

#include "AutoMoDeBehaviour.h"

namespace argos {
    class AutoMoDeBehaviourTuttiGoAwayColor: public AutoMoDeBehaviour {
		public:
            AutoMoDeBehaviourTuttiGoAwayColor();
            AutoMoDeBehaviourTuttiGoAwayColor(AutoMoDeBehaviourTuttiGoAwayColor* pc_behaviour);
            virtual ~AutoMoDeBehaviourTuttiGoAwayColor();

			virtual void ControlStep();
			virtual void Reset();
			virtual void ResumeStep();
			virtual void Init();

            virtual AutoMoDeBehaviourTuttiGoAwayColor* Clone();

		private:
            CColor m_cColorEmiterParameter;
            CColor m_cColorReceiverParameter;
            Real m_unRepulsionParameter;
            Real m_unFOVParameter;
            size_t m_bGroundLEDsParameter;
	};
}


#endif
