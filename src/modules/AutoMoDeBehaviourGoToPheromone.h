/**
  * @file <src/modules/AutoMoDeBehaviourAttractionColor.h>
  *
  * @author Antoine Ligot - <aligot@ulb.ac.be>
  *
  * @package ARGoS3-AutoMoDe
  *
  * @license MIT License
  */

#ifndef AUTOMODE_BEHAVIOUR_GOTO_PHEROMONE_H
#define AUTOMODE_BEHAVIOUR_GOTO_PHEROMONE_H

#include "AutoMoDeBehaviour.h"

namespace argos {
    class AutoMoDeBehaviourGoToPheromone: public AutoMoDeBehaviour {
		public:
            AutoMoDeBehaviourGoToPheromone();
            AutoMoDeBehaviourGoToPheromone(AutoMoDeBehaviourGoToPheromone* pc_behaviour);
            virtual ~AutoMoDeBehaviourGoToPheromone();

			virtual void ControlStep();
			virtual void Reset();
			virtual void ResumeStep();
			virtual void Init();

            virtual AutoMoDeBehaviourGoToPheromone* Clone();

        private:
            Real m_fDistanceWeightParameter;
            // CColor m_cColorEmiterParameter;
            CColor m_cColorReceiverParameter;
            Real m_unAttractionParameter;
            Real m_unFOVParameter;
            size_t m_bGroundLEDsParameter;
	};
}

#endif
