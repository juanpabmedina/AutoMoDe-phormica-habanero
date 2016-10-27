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
		CCI_EPuckRangeAndBearingSensor::TPackets sLastPackets = m_pcRobotDAO->GetRangeAndBearingMessages();
		CCI_EPuckRangeAndBearingSensor::TPackets::iterator it;
		CVector2 sRabVectorSum(0,CRadians::ZERO);
		CVector2 sProxVectorSum(0,CRadians::ZERO);
		CVector2 sResultVector(0,CRadians::ZERO);

		for (it = sLastPackets.begin(); it != sLastPackets.end(); it++) {
			if ((*it)->Data[0] != (UInt8) m_pcRobotDAO->GetRobotIdentifier()) {
				sRabVectorSum += CVector2(m_unRepulsionParameter / (1+(*it)->Range),(*it)->Bearing.SignedNormalize()); //TODO FIXME : Range+1 beacsue range can be 0
			}
		}
		sProxVectorSum = SumProximityReadings(m_pcRobotDAO->GetProximityInput());
		sResultVector = sRabVectorSum - 5*sProxVectorSum;
		if (sResultVector.Length() < 0.1) {
			sResultVector = CVector2(1, CRadians::ZERO);
		}

		//m_pcRobotDAO->SetWheelsVelocity(ComputeWheelsVelocityFromVector(-sResultVector));
		m_bLocked = false;
	}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourRepulsion::Init() {
		std::map<std::string, Real>::iterator it = m_mapParameters.find("rep");
		if (it != m_mapParameters.end()) {
			m_unRepulsionParameter = it->second;
		} else {
			LOGERR << "[FATAL] Missing parameter for the following behaviour:" << m_strLabel << std::endl;
			THROW_ARGOSEXCEPTION("Missing Parameter");
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
