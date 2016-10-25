/*
 * File: AutoMoDeConditionWhiteFloor.cpp
 *
 */

 #include "AutoMoDeConditionWhiteFloor.h"

 namespace argos {

	AutoMoDeConditionWhiteFloor::AutoMoDeConditionWhiteFloor() {
		m_strLabel = "WhiteFloor";
	}

	AutoMoDeConditionWhiteFloor::~AutoMoDeConditionWhiteFloor() {}

	bool AutoMoDeConditionWhiteFloor::Verify(AutoMoDeRobotDAO* pc_robot_dao) {
		return true;
	}

	AutoMoDeConditionWhiteFloor::AutoMoDeConditionWhiteFloor(AutoMoDeConditionWhiteFloor* pc_condition) {
		m_strLabel = pc_condition->GetLabel();
		m_unIndex = pc_condition->GetIndex();
		m_unIdentifier = pc_condition->GetIndex();
		m_unFromBehaviourIndex = pc_condition->GetOrigin();
		m_unToBehaviourIndex = pc_condition->GetExtremity();
		m_mapParameters = pc_condition->GetParameters();
	}

	AutoMoDeConditionWhiteFloor* AutoMoDeConditionWhiteFloor::Clone() {
		return new AutoMoDeConditionWhiteFloor(*this);
	}

	void AutoMoDeConditionWhiteFloor::Reset() {

	}

 }
