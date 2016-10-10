/*
 * File: AutoMoDeBehaviourPhotoaxis.cpp
 *
 */

#include "AutoMoDeBehaviourPhotoaxis.h"


namespace argos { 

	AutoMoDeBehaviourPhotoaxis::AutoMoDeBehaviourPhotoaxis() {
		m_strLabel = "Photoaxis";
	}
	
	AutoMoDeBehaviourPhotoaxis::AutoMoDeBehaviourPhotoaxis(AutoMoDeBehaviourPhotoaxis* pc_behaviour) {
		m_strLabel = pc_behaviour->GetLabel();
		m_bLocked = pc_behaviour->IsLocked();
		m_bOperational = pc_behaviour->IsOperational();
		m_unIndex = pc_behaviour->GetIndex();
		m_unIdentifier = pc_behaviour->GetIdentifier();
		m_mapParameters = pc_behaviour->GetParameters();
	}
	
	AutoMoDeBehaviourPhotoaxis::~AutoMoDeBehaviourPhotoaxis() {}
	
	AutoMoDeBehaviourPhotoaxis* AutoMoDeBehaviourPhotoaxis::Clone() {
		return new AutoMoDeBehaviourPhotoaxis(*this);
	}
	
	void AutoMoDeBehaviourPhotoaxis::ControlStep(AutoMoDeRobotDAO* pc_robot_dao) {
		//TODO
		m_bLocked = false;
	}
	
	void AutoMoDeBehaviourPhotoaxis::Reset() {
		//TODO
		m_bOperational = false;
	}
	
	void AutoMoDeBehaviourPhotoaxis::ResumeStep() {
		//TODO
		m_bOperational = true;
	}
}
