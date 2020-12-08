/**
  * @file <src/modules/AutoMoDeBehaviourRepulsion.cpp>
  *
  * @author Antoine Ligot - <aligot@ulb.ac.be>
  *
  * @package ARGoS3-AutoMoDe
  *
  * @license MIT License
  */

#include "AutoMoDeBehaviourAvoidPheromone.h"


namespace argos {

	/****************************************/
	/****************************************/

    AutoMoDeBehaviourAvoidPheromone::AutoMoDeBehaviourAvoidPheromone() {
        m_strLabel = "AvoidPheromone";
	}

	/****************************************/
	/****************************************/

    AutoMoDeBehaviourAvoidPheromone::AutoMoDeBehaviourAvoidPheromone(AutoMoDeBehaviourAvoidPheromone* pc_behaviour) {
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

    AutoMoDeBehaviourAvoidPheromone::~AutoMoDeBehaviourAvoidPheromone() {}

	/****************************************/
	/****************************************/

    AutoMoDeBehaviourAvoidPheromone* AutoMoDeBehaviourAvoidPheromone::Clone() {
        return new AutoMoDeBehaviourAvoidPheromone(this);
	}

	/****************************************/
	/****************************************/

    void AutoMoDeBehaviourAvoidPheromone::ControlStep() {
        CCI_EPuckOmnidirectionalCameraSensor::SReadings sReadings = m_pcRobotDAO->GetCameraInput();
        CCI_EPuckOmnidirectionalCameraSensor::TBlobList::iterator it;
        CVector2 sColVectorSum(0,CRadians::ZERO);
		CVector2 sProxVectorSum(0,CRadians::ZERO);
		CVector2 sResultVector(0,CRadians::ZERO);

        for (it = sReadings.BlobList.begin(); it != sReadings.BlobList.end(); it++) {
            if ((*it)->Color == m_cColorReceiverParameter  && (*it)->Distance >= 4.5) {
                if ((*it)->Angle.SignedNormalize().GetValue() >= 0 && (*it)->Angle.SignedNormalize().GetValue() <= m_unFOVParameter) {
                    sColVectorSum += CVector2(1 / (((*it)->Distance) + 1), (*it)->Angle);
                }
                else if ((*it)->Angle.SignedNormalize().GetValue() < 0 && (*it)->Angle.SignedNormalize().GetValue() >= -m_unFOVParameter) {
                    sColVectorSum += CVector2(1 / (((*it)->Distance) + 1), (*it)->Angle);
                }
            }
		}

        sProxVectorSum = CVector2(m_pcRobotDAO->GetProximityReading().Value, m_pcRobotDAO->GetProximityReading().Angle);

        if (sColVectorSum.Length() != 0)
            sResultVector = -CVector2(m_unRepulsionParameter, sColVectorSum.Angle().SignedNormalize()) - 5*sProxVectorSum;
        else
            sResultVector = CVector2(m_unRepulsionParameter, sColVectorSum.Angle().SignedNormalize()) - 5*sProxVectorSum;

		m_pcRobotDAO->SetWheelsVelocity(ComputeWheelsVelocityFromVector(sResultVector));
        // m_pcRobotDAO->SetLEDsColor(m_cColorEmiterParameter);
        m_pcRobotDAO->SetGroundLEDsState(m_bGroundLEDsParameter);

		m_bLocked = false;
	}

	/****************************************/
	/****************************************/

    void AutoMoDeBehaviourAvoidPheromone::Init() {
        std::map<std::string, Real>::iterator it = m_mapParameters.find("vel");
		if (it != m_mapParameters.end()) {
			m_unRepulsionParameter = it->second;
		} else {
			LOGERR << "[FATAL] Missing parameter for the following behaviour:" << m_strLabel << std::endl;
			THROW_ARGOSEXCEPTION("Missing Parameter");
		}
        // it = m_mapParameters.find("cle");
        // if (it != m_mapParameters.end()) {
        //     m_cColorEmiterParameter = GetColorParameter(it->second, true);
        // } else {
        //     LOGERR << "[FATAL] Missing parameter for the following behaviour:" << m_strLabel << std::endl;
        //     THROW_ARGOSEXCEPTION("Missing Parameter");
        // }
        // it = m_mapParameters.find("clr");
        // if (it != m_mapParameters.end()) {
        //     m_cColorReceiverParameter = GetColorParameter(it->second, false);
              m_cColorReceiverParameter = GetColorParameter(5, false); //Magenta color
        // } else {
        //     LOGERR << "[FATAL] Missing parameter for the following behaviour:" << m_strLabel << std::endl;
        //     THROW_ARGOSEXCEPTION("Missing Parameter");
        // }
        it = m_mapParameters.find("phe");
        if (it != m_mapParameters.end()) {
            m_bGroundLEDsParameter = (size_t)(it->second);
        } else {
            LOGERR << "[FATAL] Missing parameter for the following behaviour:" << m_strLabel << std::endl;
            THROW_ARGOSEXCEPTION("Missing Parameter");
        }
        it = m_mapParameters.find("fov");
        if (it != m_mapParameters.end()) {
            m_unFOVParameter = (it->second);
        } else {
            LOGERR << "[FATAL] Missing parameter for the following behaviour:" << m_strLabel << std::endl;
            THROW_ARGOSEXCEPTION("Missing Parameter");
        }
	}

	/****************************************/
	/****************************************/

    void AutoMoDeBehaviourAvoidPheromone::Reset() {
		m_bOperational = false;
		ResumeStep();
	}

	/****************************************/
	/****************************************/

    void AutoMoDeBehaviourAvoidPheromone::ResumeStep() {
		m_bOperational = true;
	}
}