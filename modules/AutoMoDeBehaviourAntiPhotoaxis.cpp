/*
 * File: AutoMoDeBehaviourAntiPhotoaxis.cpp
 *
 */

#include "AutoMoDeBehaviourAntiPhotoaxis.h"


namespace argos { 
	
	/****************************************/
	/****************************************/
	
	AutoMoDeBehaviourAntiPhotoaxis::AutoMoDeBehaviourAntiPhotoaxis() {
		m_strLabel = "Anti-Photoaxis";
	}
	
	/****************************************/
	/****************************************/
		
	AutoMoDeBehaviourAntiPhotoaxis::AutoMoDeBehaviourAntiPhotoaxis(AutoMoDeBehaviourAntiPhotoaxis* pc_behaviour) {
		m_strLabel = pc_behaviour->GetLabel();
		m_bLocked = pc_behaviour->IsLocked();
		m_bOperational = pc_behaviour->IsOperational();
		m_unIndex = pc_behaviour->GetIndex();
		m_unIdentifier = pc_behaviour->GetIdentifier();
		m_mapParameters = pc_behaviour->GetParameters();
	}
	
	/****************************************/
	/****************************************/
	
	AutoMoDeBehaviourAntiPhotoaxis::~AutoMoDeBehaviourAntiPhotoaxis() {}
	
	/****************************************/
	/****************************************/
	
	AutoMoDeBehaviourAntiPhotoaxis* AutoMoDeBehaviourAntiPhotoaxis::Clone() {
		return new AutoMoDeBehaviourAntiPhotoaxis(*this);
	}
	
	/****************************************/
	/****************************************/
	
	void AutoMoDeBehaviourAntiPhotoaxis::ControlStep(AutoMoDeRobotDAO* pc_robot_dao) {
		//TODO
		m_bLocked = false;
	}
	
	/****************************************/
	/****************************************/
	
	void AutoMoDeBehaviourAntiPhotoaxis::Init() {}
	
	/****************************************/
	/****************************************/
	
	void AutoMoDeBehaviourAntiPhotoaxis::Reset() {
		m_bOperational = false;
		ResumeStep();
	}
	
	/****************************************/
	/****************************************/
	
	void AutoMoDeBehaviourAntiPhotoaxis::ResumeStep() {
		//TODO
		m_bOperational = true;
	}
}
