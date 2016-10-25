/*
 * File: AutoMoDeConditionInvertedNeighborsCount.h
 *
 */

#ifndef AUTOMODE_CONDITION_INVERTED_NEIGHBORS_COUNT_H
#define AUTOMODE_CONDITION_INVERTED_NEIGHBORS_COUNT_H

#include "AutoMoDeCondition.h"

namespace argos {
	class AutoMoDeConditionInvertedNeighborsCount: public AutoMoDeCondition {
		public:
			AutoMoDeConditionInvertedNeighborsCount();
			virtual ~AutoMoDeConditionInvertedNeighborsCount();

			AutoMoDeConditionInvertedNeighborsCount(AutoMoDeConditionInvertedNeighborsCount* pc_condition);
			virtual AutoMoDeConditionInvertedNeighborsCount* Clone();

			virtual bool Verify(AutoMoDeRobotDAO* pc_robot_dao);
			virtual void Reset();
	};
}

#endif
