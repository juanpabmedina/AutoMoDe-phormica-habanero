/*
 * File: AutoMoDeBehaviourExploration.cpp
 *
 */

#include "AutoMoDeBehaviourExploration.h"


namespace argos { 

	AutoMoDeBehaviourExploration::AutoMoDeBehaviourExploration() {
		m_strLabel = "Exploration";
	}
	
	AutoMoDeBehaviourExploration::AutoMoDeBehaviourExploration(AutoMoDeBehaviourExploration* pc_behaviour) {
		m_strLabel = pc_behaviour->GetLabel();
		m_bLocked = pc_behaviour->IsLocked();
		m_bOperational = pc_behaviour->IsOperational();
		m_unIndex = pc_behaviour->GetIndex();
		m_unIdentifier = pc_behaviour->GetIdentifier();
		m_mapParameters = pc_behaviour->GetParameters();
	}
	
	AutoMoDeBehaviourExploration::~AutoMoDeBehaviourExploration() {}
	
	AutoMoDeBehaviourExploration* AutoMoDeBehaviourExploration::Clone() {
		return new AutoMoDeBehaviourExploration(*this);
	}
	
	void AutoMoDeBehaviourExploration::ControlStep(AutoMoDeRobotDAO* pc_robot_dao) {
		//TODO
		m_bLocked = false;
	}
	
	void AutoMoDeBehaviourExploration::Reset() {
		//TODO
		m_bOperational = false;
	}
	
	void AutoMoDeBehaviourExploration::ResumeStep() {
		//TODO
		m_bOperational = true;
	}
}
