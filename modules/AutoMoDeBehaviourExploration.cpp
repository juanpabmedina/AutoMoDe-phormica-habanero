/*
 * File: AutoMoDeBehaviourExploration.cpp
 *
 */

#include "AutoMoDeBehaviourExploration.h"


namespace argos {

	/****************************************/
	/****************************************/

	AutoMoDeBehaviourExploration::AutoMoDeBehaviourExploration() {
		m_strLabel = "Exploration";
		Init();
	}

	/****************************************/
	/****************************************/

	AutoMoDeBehaviourExploration::AutoMoDeBehaviourExploration(AutoMoDeBehaviourExploration* pc_behaviour) {
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

	AutoMoDeBehaviourExploration::~AutoMoDeBehaviourExploration() {}

	/****************************************/
	/****************************************/

	AutoMoDeBehaviourExploration* AutoMoDeBehaviourExploration::Clone() {
		return new AutoMoDeBehaviourExploration(*this);
	}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourExploration::Init() {
		m_unTurnSteps = 0;
		m_eExplorationState = RANDOM_WALK;
		m_fWheelSpeed = 10;
		m_fProximityThreshold = 0.1;
		m_bLocked = false;
		if (m_mapParameters.find("rwm") != m_mapParameters.end()) {
			m_cRandomStepsRange.SetMax(m_mapParameters.find("rwm")->second);
		} else {
			THROW_ARGOSEXCEPTION("Missing Parameter: exploration");
		}
	}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourExploration::ControlStep() {
		switch (m_eExplorationState) {
			case RANDOM_WALK: {
				m_pcRobotDAO->SetWheelsVelocity(m_fWheelSpeed, m_fWheelSpeed);
				if (IsObstacleInFront(m_pcRobotDAO->GetProximityInput())) {
					m_eExplorationState = OBSTACLE_AVOIDANCE;
					m_unTurnSteps = (m_pcRobotDAO->GetRandomNumberGenerator())->Uniform(m_cRandomStepsRange);
					CRadians cAngle = SumProximityReadings(m_pcRobotDAO->GetProximityInput()).Angle().SignedNormalize();
					if (cAngle.GetValue() < 0) {
						m_eTurnDirection = RIGHT;
					} else {
						m_eTurnDirection = LEFT;
					}
				}
				break;
			}
			case OBSTACLE_AVOIDANCE: {
				m_unTurnSteps -= 1;
				switch (m_eTurnDirection) {
					case LEFT: {
						m_pcRobotDAO->SetWheelsVelocity(m_fWheelSpeed, -m_fWheelSpeed);
						break;
					}
					case RIGHT: {
						m_pcRobotDAO->SetWheelsVelocity(-m_fWheelSpeed, m_fWheelSpeed);
						break;
					}
				}
				if (m_unTurnSteps <= 0) {
					m_eExplorationState = RANDOM_WALK;
				}
				break;
			}
		}
		m_bLocked = false;
	}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourExploration::Reset() {
		m_bOperational = false;
		Init();
		ResumeStep();
	}

	/****************************************/
	/****************************************/

	void AutoMoDeBehaviourExploration::ResumeStep() {
		m_bOperational = true;
	}

	/****************************************/
	/****************************************/

	bool AutoMoDeBehaviourExploration::IsObstacleInFront(CCI_EPuckProximitySensor::TReadings s_prox_input) {
		if (s_prox_input[0].Value >= m_fProximityThreshold ||
				s_prox_input[1].Value >= m_fProximityThreshold ||
				s_prox_input[6].Value >= m_fProximityThreshold ||
				s_prox_input[7].Value >= m_fProximityThreshold) {
			return true;
		}
		return false;
	}
}
