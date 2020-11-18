/**
  * @file <src/modules/AutoMoDeConditionColor.h>
  *
  * @author Antoine Ligot - <aligot@ulb.ac.be>
  *
  * @package ARGoS3-AutoMoDe
  *
  * @license MIT License
  */

#ifndef AUTOMODE_CONDITION_PHEROMONE_DETECTED_H
#define AUTOMODE_CONDITION_PHEROMONE_DETECTED_H

#include "AutoMoDeCondition.h"

namespace argos {
    class AutoMoDeConditionPheromoneDetected: public AutoMoDeCondition {
		public:
            AutoMoDeConditionPheromoneDetected();
            virtual ~AutoMoDeConditionPheromoneDetected();

            AutoMoDeConditionPheromoneDetected(AutoMoDeConditionPheromoneDetected* pc_condition);
            virtual AutoMoDeConditionPheromoneDetected* Clone();

			virtual bool Verify();
			virtual void Reset();
			virtual void Init();

		private:
            CColor m_cColorParameter;
			      Real m_fProbability;
            Real m_fDistance;
            Real m_unFOVParameter;
	};
}

#endif
