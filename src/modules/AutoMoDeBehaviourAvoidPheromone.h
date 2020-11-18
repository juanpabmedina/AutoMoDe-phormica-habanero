/**
  * @file <src/modules/AutoMoDeBehaviourRepulsionColor.h>
  *
  * @author Antoine Ligot - <aligot@ulb.ac.be>
  *
  * @package ARGoS3-AutoMoDe
  *
  * @license MIT License
  */

#ifndef AUTOMODE_BEHAVIOUR_AVOID_PHEROMONE_H
#define AUTOMODE_BEHAVIOUR_AVOID_PHEROMONE_H

#include "AutoMoDeBehaviour.h"

namespace argos {
    class AutoMoDeBehaviourAvoidPheromone: public AutoMoDeBehaviour {
		public:
            AutoMoDeBehaviourAvoidPheromone();
            AutoMoDeBehaviourAvoidPheromone(AutoMoDeBehaviourAvoidPheromone* pc_behaviour);
            virtual ~AutoMoDeBehaviourAvoidPheromone();

			virtual void ControlStep();
			virtual void Reset();
			virtual void ResumeStep();
			virtual void Init();

            virtual AutoMoDeBehaviourAvoidPheromone* Clone();

		private:
            // CColor m_cColorEmiterParameter;
            CColor m_cColorReceiverParameter;
            Real m_unRepulsionParameter;
            Real m_unFOVParameter;
            size_t m_bGroundLEDsParameter;
	};
}


#endif
