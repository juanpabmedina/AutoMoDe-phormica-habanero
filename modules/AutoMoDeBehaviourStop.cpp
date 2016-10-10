/*
 * File: AutoMoDeBehaviourStop.cpp
 *
 */

#include "AutoMoDeBehaviourStop.h"


namespace argos { 

	AutoMoDeBehaviourStop::AutoMoDeBehaviourStop() {
		m_strLabel = "Stop";
	}
	
	AutoMoDeBehaviourStop::AutoMoDeBehaviourStop(AutoMoDeBehaviourStop* pc_behaviour) {
		m_strLabel = pc_behaviour->GetLabel();
		m_bLocked = pc_behaviour->IsLocked();
		m_bOperational = pc_behaviour->IsOperational();
		m_unIndex = pc_behaviour->GetIndex();
		m_unIdentifier = pc_behaviour->GetIdentifier();
		m_mapParameters = pc_behaviour->GetParameters();
	}
	
	AutoMoDeBehaviourStop::~AutoMoDeBehaviourStop() {}
	
	AutoMoDeBehaviourStop* AutoMoDeBehaviourStop::Clone() {
		return new AutoMoDeBehaviourStop(*this);
	}
	
	void AutoMoDeBehaviourStop::ControlStep(AutoMoDeRobotDAO* pc_robot_dao) {
		//TODO
		m_bLocked = false;
	}
	
	void AutoMoDeBehaviourStop::Reset() {
		//TODO
		m_bOperational = false;
	}
	
	void AutoMoDeBehaviourStop::ResumeStep() {
		//TODO
		m_bOperational = true;
	}
}
