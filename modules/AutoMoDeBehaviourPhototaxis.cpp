/*
 * File: AutoMoDeBehaviourPhototaxis.cpp
 *
 */

#include "AutoMoDeBehaviourPhototaxis.h"


namespace argos {

	/****************************************/
	/****************************************/

	AutoMoDeBehaviourPhototaxis::AutoMoDeBehaviourPhototaxis() {
		m_strLabel = "Phototaxis";
	}

	/****************************************/
	/****************************************/

	AutoMoDeBehaviourPhototaxis::AutoMoDeBehaviourPhototaxis(AutoMoDeBehaviourPhotoaxis* pc_behaviour) {
		m_strLabel = pc_behaviour->GetLabel();
		m_bLocked = pc_behaviour->IsLocked();
		m_bOperational = pc_behaviour->IsOperational();
		m_unIndex = pc_behaviour->GetIndex();
		m_unIdentifier = pc_behaviour->GetIdentifier();
		m_mapParameters = pc_behaviour->GetParameters();
	}

	/****************************************/
	/****************************************/

	AutoMoDeBehaviourPhototaxis::~AutoMoDeBehaviourPhototaxis() {}

	/****************************************/
	/****************************************/

	AutoMoDeBehaviourPhototaxis* AutoMoDeBehaviourPhototaxis::Clone() {
		return new AutoMoDeBehaviourPhotoaxis(*this);
	}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourPhototaxis::ControlStep() {
		CCI_EPuckLightSensor::TReadings sReadings = m_pcRobotDAO->GetLightInput();
	 	CCI_EPuckLightSensor::TReadings::iterator it;
		CVector2 sLightVectorSum(0,CRadians::ZERO);
		CVector2 sProxVectorSum(0,CRadians::ZERO);
		CVector2 sResultVector(0,CRadians::ZERO);

		for (it = sReadings.begin(); it != sReadings.end(); it++) {
			sLightVectorSum += CVector2(it->Value,it->Angle.SignedNormalize()); //TODO FIXME : Range+1 beacsue range can be 0
			LOG << it->Value << " ";
		}
		LOG << std::endl;

		sProxVectorSum = SumProximityReadings(m_pcRobotDAO->GetProximityInput());
		sResultVector = sLightVectorSum - 5*sProxVectorSum;

		if (sResultVector.Length() < 0.1) {
			sResultVector = CVector2(1, CRadians::ZERO);
		}
		m_pcRobotDAO->SetWheelsVelocity(ComputeWheelsVelocityFromVector(sResultVector));
		
		m_bLocked = false;
	}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourPhototaxis::Init() {}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourPhototaxis::Reset() {
		//TODO
		m_bOperational = false;
		ResumeStep();
	}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourPhototaxis::ResumeStep() {
		//TODO
		m_bOperational = true;
	}
}
