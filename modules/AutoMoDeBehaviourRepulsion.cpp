/*
 * File: AutoMoDeBehaviourRepulsion.cpp
 *
 */

#include "AutoMoDeBehaviourRepulsion.h"


namespace argos {

	/****************************************/
	/****************************************/

	AutoMoDeBehaviourRepulsion::AutoMoDeBehaviourRepulsion() {
		m_strLabel = "Repulsion";
	}

	/****************************************/
	/****************************************/

	AutoMoDeBehaviourRepulsion::AutoMoDeBehaviourRepulsion(AutoMoDeBehaviourRepulsion* pc_behaviour) {
		m_strLabel = pc_behaviour->GetLabel();
		m_bLocked = pc_behaviour->IsLocked();
		m_bOperational = pc_behaviour->IsOperational();
		m_unIndex = pc_behaviour->GetIndex();
		m_unIdentifier = pc_behaviour->GetIdentifier();
		m_mapParameters = pc_behaviour->GetParameters();
	}

	/****************************************/
	/****************************************/

	AutoMoDeBehaviourRepulsion::~AutoMoDeBehaviourRepulsion() {}

	/****************************************/
	/****************************************/

	AutoMoDeBehaviourRepulsion* AutoMoDeBehaviourRepulsion::Clone() {
		return new AutoMoDeBehaviourRepulsion(*this);
	}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourRepulsion::ControlStep() {
		//TODO
		m_bLocked = false;
	}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourRepulsion::Init() {
		if (m_mapParameters.find("rep") != m_mapParameters.end()) {
			m_unRepulsionParameter = m_mapParameters.find("rep")->second;
		} else {
			THROW_ARGOSEXCEPTION("Missing Parameter: repulsion");
		}
	}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourRepulsion::Reset() {
		//TODO
		m_bOperational = false;
		ResumeStep();
	}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourRepulsion::ResumeStep() {
		//TODO
		m_bOperational = true;
	}
}
