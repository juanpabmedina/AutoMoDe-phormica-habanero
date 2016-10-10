/*
 * File: AutoMoDeConditionBlackFloor.cpp
 *
 */
 
 #include "AutoMoDeConditionBlackFloor.h"
 
 namespace argos {
	 
	AutoMoDeConditionBlackFloor::AutoMoDeConditionBlackFloor() {
		m_strLabel = "BlackFloor";
	}
	
	AutoMoDeConditionBlackFloor::~AutoMoDeConditionBlackFloor() {}
	
	AutoMoDeConditionBlackFloor::AutoMoDeConditionBlackFloor(AutoMoDeConditionBlackFloor* pc_condition) {
		m_strLabel = pc_condition->GetLabel();
		m_unIndex = pc_condition->GetIndex();
		m_unIdentifier = pc_condition->GetIndex();
		m_unFromBehaviourIndex = pc_condition->GetOrigin();
		m_unToBehaviourIndex = pc_condition->GetExtremity();
		m_mapParameters = pc_condition->GetParameters();
	}
	
	AutoMoDeConditionBlackFloor* AutoMoDeConditionBlackFloor::Clone() {
		return new AutoMoDeConditionBlackFloor(*this);
	}
	
	bool AutoMoDeConditionBlackFloor::Verify() {
		return true;
	}
	
	void AutoMoDeConditionBlackFloor::Reset() {
		
	}
	 
 }
