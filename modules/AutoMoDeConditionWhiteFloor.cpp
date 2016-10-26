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

	bool AutoMoDeConditionWhiteFloor::Verify() {
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
	
	void AutoMoDeConditionWhiteFloor::Init() {
		if (m_mapParameters.find("p") != m_mapParameters.end()) {
			m_fProbability = m_mapParameters.find("p")->second;
		} else {
			THROW_ARGOSEXCEPTION("Missing Parameter: white floor");
		}
	}

	void AutoMoDeConditionWhiteFloor::Reset() {

	}

 }
