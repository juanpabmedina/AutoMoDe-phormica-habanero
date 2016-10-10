/*
 * File: AutoMoDeBehaviourRepulsion.cpp
 *
 */

#include "AutoMoDeBehaviourRepulsion.h"


namespace argos { 

	AutoMoDeBehaviourRepulsion::AutoMoDeBehaviourRepulsion() {
		m_strLabel = "Repulsion";
	}
	
	AutoMoDeBehaviourRepulsion::AutoMoDeBehaviourRepulsion(AutoMoDeBehaviourRepulsion* pc_behaviour) {
		m_strLabel = pc_behaviour->GetLabel();
		m_bLocked = pc_behaviour->IsLocked();
		m_bOperational = pc_behaviour->IsOperational();
		m_unIndex = pc_behaviour->GetIndex();
		m_unIdentifier = pc_behaviour->GetIdentifier();
		m_mapParameters = pc_behaviour->GetParameters();
	}
	
	AutoMoDeBehaviourRepulsion::~AutoMoDeBehaviourRepulsion() {}
	
	AutoMoDeBehaviourRepulsion* AutoMoDeBehaviourRepulsion::Clone() {
		return new AutoMoDeBehaviourRepulsion(*this);
	}
	
	void AutoMoDeBehaviourRepulsion::ControlStep(AutoMoDeRobotDAO* pc_robot_dao) {
		//TODO
		m_bLocked = false;
	}
	
	void AutoMoDeBehaviourRepulsion::Reset() {
		//TODO
		m_bOperational = false;
	}
	
	void AutoMoDeBehaviourRepulsion::ResumeStep() {
		//TODO
		m_bOperational = true;
	}
}
