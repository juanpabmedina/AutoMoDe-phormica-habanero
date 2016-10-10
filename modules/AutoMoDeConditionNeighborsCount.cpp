/*
 * File: AutoMoDeConditionNeighborsCount.cpp
 *
 */

 #include "AutoMoDeConditionNeighborsCount.h"
 
 namespace argos {
	 
	AutoMoDeConditionNeighborsCount::AutoMoDeConditionNeighborsCount() {
		m_strLabel = "NeighborsCount";
	}
	
	AutoMoDeConditionNeighborsCount::~AutoMoDeConditionNeighborsCount() {}
		
	AutoMoDeConditionNeighborsCount::AutoMoDeConditionNeighborsCount(AutoMoDeConditionNeighborsCount* pc_condition) {
		m_strLabel = pc_condition->GetLabel();
		m_unIndex = pc_condition->GetIndex();
		m_unIdentifier = pc_condition->GetIndex();
		m_unFromBehaviourIndex = pc_condition->GetOrigin();
		m_unToBehaviourIndex = pc_condition->GetExtremity();
		m_mapParameters = pc_condition->GetParameters();
	}
		
	AutoMoDeConditionNeighborsCount* AutoMoDeConditionNeighborsCount::Clone() {
		return new AutoMoDeConditionNeighborsCount(*this);
	}
	
	bool AutoMoDeConditionNeighborsCount::Verify() {
		return true;
	}
	
	void AutoMoDeConditionNeighborsCount::Reset() {
		
	}
	 
 }
