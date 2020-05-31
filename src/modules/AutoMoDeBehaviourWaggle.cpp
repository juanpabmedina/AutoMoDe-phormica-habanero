/**
  * @file <src/modules/AutoMoDeBehaviourWaggle.cpp>
  *
  * @author Antoine Ligot - <aligot@ulb.ac.be>
  *
  * @package ARGoS3-AutoMoDe
  *
  * @license MIT License
  */

#include "AutoMoDeBehaviourWaggle.h"


namespace argos {

	/****************************************/
	/****************************************/

	AutoMoDeBehaviourWaggle::AutoMoDeBehaviourWaggle() {
		m_strLabel = "Waggle";
	}

	/****************************************/
	/****************************************/

	AutoMoDeBehaviourWaggle::AutoMoDeBehaviourWaggle(AutoMoDeBehaviourWaggle* pc_behaviour) {
		m_strLabel = pc_behaviour->GetLabel();
		m_bLocked = pc_behaviour->IsLocked();
		m_bOperational = pc_behaviour->IsOperational();
		m_unIndex = pc_behaviour->GetIndex();
		m_unIdentifier = pc_behaviour->GetIdentifier();
		m_mapParameters = pc_behaviour->GetParameters();
		Init();
	}

	/****************************************/
	/****************************************/

	AutoMoDeBehaviourWaggle::~AutoMoDeBehaviourWaggle() {}

	/****************************************/
	/****************************************/

	AutoMoDeBehaviourWaggle* AutoMoDeBehaviourWaggle::Clone() {
		return new AutoMoDeBehaviourWaggle(this);
	}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourWaggle::ControlStep() {

		if(m_bRotationDirectionParameter){
		  m_pcRobotDAO->SetWheelsVelocity(m_pcRobotDAO->GetMaxVelocity(),-m_pcRobotDAO->GetMaxVelocity());
			}
		else {
		  m_pcRobotDAO->SetWheelsVelocity(-m_pcRobotDAO->GetMaxVelocity(),m_pcRobotDAO->GetMaxVelocity());
		  }

		m_pcRobotDAO->SetLEDsColor(m_cColorEmiterParameter);
		m_pcRobotDAO->SetGroundLEDsState(m_bGroundLEDsParameter);
		m_bLocked = false;
	}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourWaggle::Init() {

				m_bRotationDirectionParameter = true;

        std::map<std::string, Real>::iterator it = m_mapParameters.find("cle");
        if (it != m_mapParameters.end()) {
            m_cColorEmiterParameter = GetColorParameter(it->second, true);
        } else {
            LOGERR << "[FATAL] Missing parameter for the following behaviour:" << m_strLabel << std::endl;
            THROW_ARGOSEXCEPTION("Missing Parameter");
        }
				it = m_mapParameters.find("phe");
        if (it != m_mapParameters.end()) {
            m_bGroundLEDsParameter = (size_t)(it->second);
        } else {
            LOGERR << "[FATAL] Missing parameter for the following behaviour:" << m_strLabel << std::endl;
            THROW_ARGOSEXCEPTION("Missing Parameter");
        }
	}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourWaggle::Reset() {
		m_bOperational = false;
		ResumeStep();
	}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourWaggle::ResumeStep() {
		m_bOperational = true;
	}
}
