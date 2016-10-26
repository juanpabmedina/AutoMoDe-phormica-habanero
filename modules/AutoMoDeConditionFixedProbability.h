/*
 * File: AutoMoDeConditionFixedProbability.h
 *
 */

#ifndef AUTOMODE_CONDITION_FIXED_PROBABILITY_H
#define AUTOMODE_CONDITION_FIXED_PROBABILITY_H

#include "AutoMoDeCondition.h"

namespace argos {
	class AutoMoDeConditionFixedProbability: public AutoMoDeCondition {
		public:
			AutoMoDeConditionFixedProbability();
			virtual ~AutoMoDeConditionFixedProbability();

			AutoMoDeConditionFixedProbability(AutoMoDeConditionFixedProbability* pc_condition);
			virtual AutoMoDeConditionFixedProbability* Clone();

			virtual bool Verify();
			virtual void Reset();
			virtual void Init();
	};
}

#endif
