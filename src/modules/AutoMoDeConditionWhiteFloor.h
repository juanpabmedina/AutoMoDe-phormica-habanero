/*
 * File: AutoMoDeConditionWhiteFloor.h
 *
 */

#ifndef AUTOMODE_CONDITION_WHITE_FLOOR_H
#define AUTOMODE_CONDITION_WHITE_FLOOR_H

#include "AutoMoDeCondition.h"

namespace argos {
	class AutoMoDeConditionWhiteFloor: public AutoMoDeCondition {
		public:
			AutoMoDeConditionWhiteFloor();
			virtual ~AutoMoDeConditionWhiteFloor();

			AutoMoDeConditionWhiteFloor(AutoMoDeConditionWhiteFloor* pc_condition);
			virtual AutoMoDeConditionWhiteFloor* Clone();

			virtual bool Verify();
			virtual void Reset();
			virtual void Init();
			
		private:
			Real m_fGroundThreshold;
			Real m_fProbability;
	};
}

#endif
