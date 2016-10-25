/*
 * File: AutoMoDeConditionInvertedNeighborsCount.cpp
 *
 */

 #include "AutoMoDeConditionInvertedNeighborsCount.h"

 namespace argos {

	AutoMoDeConditionInvertedNeighborsCount::AutoMoDeConditionInvertedNeighborsCount() {
		m_strLabel = "InvertedNeighborsCount";
	}

	AutoMoDeConditionInvertedNeighborsCount::~AutoMoDeConditionInvertedNeighborsCount() {}

	AutoMoDeConditionInvertedNeighborsCount::AutoMoDeConditionInvertedNeighborsCount(AutoMoDeConditionInvertedNeighborsCount* pc_condition) {
		m_strLabel = pc_condition->GetLabel();
		m_unIndex = pc_condition->GetIndex();
		m_unIdentifier = pc_condition->GetIndex();
		m_unFromBehaviourIndex = pc_condition->GetOrigin();
		m_unToBehaviourIndex = pc_condition->GetExtremity();
		m_mapParameters = pc_condition->GetParameters();
	}

	AutoMoDeConditionInvertedNeighborsCount* AutoMoDeConditionInvertedNeighborsCount::Clone() {
		return new AutoMoDeConditionInvertedNeighborsCount(*this);
	}

	bool AutoMoDeConditionInvertedNeighborsCount::Verify(AutoMoDeRobotDAO* pc_robot_dao) {
		return true;
	}

	void AutoMoDeConditionInvertedNeighborsCount::Reset() {

	}

 }
