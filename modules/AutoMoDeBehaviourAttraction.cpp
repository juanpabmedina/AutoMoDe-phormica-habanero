/*
 * File: AutoMoDeBehaviourAttraction.cpp
 *
 */

#include "AutoMoDeBehaviourAttraction.h"


namespace argos { 
	
	/****************************************/
	/****************************************/

	AutoMoDeBehaviourAttraction::AutoMoDeBehaviourAttraction() {
		m_strLabel = "Attraction";
	}
	
	/****************************************/
	/****************************************/
	
	AutoMoDeBehaviourAttraction::AutoMoDeBehaviourAttraction(AutoMoDeBehaviourAttraction* pc_behaviour) {
		m_strLabel = pc_behaviour->GetLabel();
		m_bLocked = pc_behaviour->IsLocked();
		m_bOperational = pc_behaviour->IsOperational();
		m_unIndex = pc_behaviour->GetIndex();
		m_unIdentifier = pc_behaviour->GetIdentifier();
		m_mapParameters = pc_behaviour->GetParameters();
	}
	
	/****************************************/
	/****************************************/
	
	AutoMoDeBehaviourAttraction::~AutoMoDeBehaviourAttraction() {}
	
	/****************************************/
	/****************************************/
	
	AutoMoDeBehaviourAttraction* AutoMoDeBehaviourAttraction::Clone() {
		return new AutoMoDeBehaviourAttraction(*this);
	}
	
	/****************************************/
	/****************************************/
	
	void AutoMoDeBehaviourAttraction::ControlStep(AutoMoDeRobotDAO* pc_robot_dao) {
		//TODO
		m_bLocked = false;
	}
	
	/****************************************/
	/****************************************/
	
	void AutoMoDeBehaviourAttraction::Init() {}
	
	/****************************************/
	/****************************************/
	
	void AutoMoDeBehaviourAttraction::Reset() {
		//TODO
		m_bOperational = false;
		ResumeStep();
	}
	
	/****************************************/
	/****************************************/
	
	void AutoMoDeBehaviourAttraction::ResumeStep() {
		//TODO
		m_bOperational = true;
	}
}
