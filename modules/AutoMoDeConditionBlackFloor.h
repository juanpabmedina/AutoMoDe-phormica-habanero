/*
 * File: AutoMoDeConditionBlackFloor.h
 *
 */

#ifndef AUTOMODE_CONDITION_BLACK_FLOOR_H
#define AUTOMODE_CONDITION_BLACK_FLOOR_H

#include "AutoMoDeCondition.h"

namespace argos {
	class AutoMoDeConditionBlackFloor: public AutoMoDeCondition {
		public:
			AutoMoDeConditionBlackFloor();
			virtual ~AutoMoDeConditionBlackFloor();

			AutoMoDeConditionBlackFloor(AutoMoDeConditionBlackFloor* pc_condition);
			virtual AutoMoDeConditionBlackFloor* Clone();

			virtual bool Verify(AutoMoDeRobotDAO* pc_robot_dao);
			virtual void Reset();

		private:
			Real m_fGroundThreshold;
	};
}

#endif
