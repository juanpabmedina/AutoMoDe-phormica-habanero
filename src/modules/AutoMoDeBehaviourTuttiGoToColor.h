/**
  * @file <src/modules/AutoMoDeBehaviourAttractionColor.h>
  *
  * @author Antoine Ligot - <aligot@ulb.ac.be>
  *
  * @package ARGoS3-AutoMoDe
  *
  * @license MIT License
  */

#ifndef AUTOMODE_BEHAVIOUR_TUTTIGOTO_COLOR_H
#define AUTOMODE_BEHAVIOUR_TUTTIGOTO_COLOR_H

#include "AutoMoDeBehaviour.h"

namespace argos {
    class AutoMoDeBehaviourTuttiGoToColor: public AutoMoDeBehaviour {
		public:
            AutoMoDeBehaviourTuttiGoToColor();
            AutoMoDeBehaviourTuttiGoToColor(AutoMoDeBehaviourTuttiGoToColor* pc_behaviour);
            virtual ~AutoMoDeBehaviourTuttiGoToColor();

			virtual void ControlStep();
			virtual void Reset();
			virtual void ResumeStep();
			virtual void Init();

            virtual AutoMoDeBehaviourTuttiGoToColor* Clone();

        private:
            Real m_fDistanceWeightParameter;
            CColor m_cColorEmiterParameter;
            CColor m_cColorReceiverParameter;
            Real m_unAttractionParameter;
            Real m_unFOVParameter;
            size_t m_bGroundLEDsParameter;
	};
}

#endif
