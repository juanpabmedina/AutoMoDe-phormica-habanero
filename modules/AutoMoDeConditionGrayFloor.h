/*
 * File: AutoMoDeConditionGrayFloor.h
 *
 */

#ifndef AUTOMODE_CONDITION_GRAY_FLOOR_H
#define AUTOMODE_CONDITION_GRAY_FLOOR_H

#include "AutoMoDeCondition.h"

namespace argos {
	class AutoMoDeConditionGrayFloor: public AutoMoDeCondition {
		public:
			AutoMoDeConditionGrayFloor();
			virtual ~AutoMoDeConditionGrayFloor();

			AutoMoDeConditionGrayFloor(AutoMoDeConditionGrayFloor* pc_condition);
			virtual AutoMoDeConditionGrayFloor* Clone();

			virtual bool Verify(AutoMoDeRobotDAO* pc_robot_dao);
			virtual void Reset();
	};
}

#endif
