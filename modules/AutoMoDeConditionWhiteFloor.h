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

			virtual bool Verify(AutoMoDeRobotDAO* pc_robot_dao);
			virtual void Reset();
	};
}

#endif
