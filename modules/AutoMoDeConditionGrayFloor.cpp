/*
 * File: AutoMoDeConditionGrayFloor.cpp
 *
 */

 #include "AutoMoDeConditionGrayFloor.h"

 namespace argos {

	AutoMoDeConditionGrayFloor::AutoMoDeConditionGrayFloor() {
		m_strLabel = "GrayFloor";
	}

	AutoMoDeConditionGrayFloor::~AutoMoDeConditionGrayFloor() {}

	AutoMoDeConditionGrayFloor::AutoMoDeConditionGrayFloor(AutoMoDeConditionGrayFloor* pc_condition) {
		m_strLabel = pc_condition->GetLabel();
		m_unIndex = pc_condition->GetIndex();
		m_unIdentifier = pc_condition->GetIndex();
		m_unFromBehaviourIndex = pc_condition->GetOrigin();
		m_unToBehaviourIndex = pc_condition->GetExtremity();
		m_mapParameters = pc_condition->GetParameters();
	}

	AutoMoDeConditionGrayFloor* AutoMoDeConditionGrayFloor::Clone() {
		return new AutoMoDeConditionGrayFloor(*this);
	}

	bool AutoMoDeConditionGrayFloor::Verify() {
		return true;
	}
	
	void AutoMoDeConditionGrayFloor::Init() {
		if (m_mapParameters.find("p") != m_mapParameters.end()) {
			m_fProbability = m_mapParameters.find("p")->second;
		} else {
			THROW_ARGOSEXCEPTION("Missing Parameter: gray floor");
		}
	}


	void AutoMoDeConditionGrayFloor::Reset() {

	}

 }
