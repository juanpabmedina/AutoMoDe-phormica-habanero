/*
 * File: AutoMoDeController.cpp
 *
 */

#include "AutoMoDeController.h"

namespace argos {

	/****************************************/
	/****************************************/

	AutoMoDeController::AutoMoDeController() {
		m_pcRobotState = new AutoMoDeRobotDAO();
		m_unTimeStep = 0;
		m_strFsmConfiguration = "";
		m_bMaintainHistory = false;
		m_bPrintReadableFsm = false;
	}

	/****************************************/
	/****************************************/

	AutoMoDeController::~AutoMoDeController() {

	}

	/****************************************/
	/****************************************/

	void AutoMoDeController::Init(TConfigurationNode& t_node) {
		// Parsing parameters
		try {
			GetNodeAttributeOrDefault(t_node, "fsm-config", m_strFsmConfiguration, m_strFsmConfiguration);
			GetNodeAttributeOrDefault(t_node, "history", m_bMaintainHistory, m_bMaintainHistory);
			GetNodeAttributeOrDefault(t_node, "readable", m_bPrintReadableFsm, m_bPrintReadableFsm);
		} catch (CARGoSException& ex) {
			THROW_ARGOSEXCEPTION_NESTED("Error parsing <params>", ex);
		}

		m_unRobotID = atoi(GetId().substr(5, 6).c_str());
		m_pcRobotState->SetRobotIdentifier(m_unRobotID);

		/*
		 * If a FSM configuration is given as parameter of the experiment file, create a FSM from it
		 */
		if (m_strFsmConfiguration.compare("") != 0) {
			m_pcFsmBuilder = new AutoMoDeFsmBuilder();
			SetFiniteStateMachine(m_pcFsmBuilder->BuildFiniteStateMachine(m_strFsmConfiguration));
			if (m_bMaintainHistory) {
				std::ostringstream sHistoryPath;
				sHistoryPath <<  "./fsm_history/fsm_history_" <<  m_unRobotID << ".txt";
				m_pcFiniteStateMachine->MaintainHistory(sHistoryPath.str());   // Give here path (file with ID of robot)
			}
			if (m_bPrintReadableFsm) {
				std::cout << m_pcFiniteStateMachine->GetReadableFormat() << std::endl;
			}
		}

		/*
		 *  Initializing sensors and actuators
		 */
		try{
			m_pcProximitySensor = GetSensor<CCI_EPuckProximitySensor>("epuck_proximity");
			m_pcLightSensor = GetSensor<CCI_EPuckLightSensor>("epuck_light");
			m_pcGroundSensor = GetSensor<CCI_EPuckGroundSensor>("epuck_ground");
			 m_pcRabSensor = GetSensor<CCI_EPuckRangeAndBearingSensor>("epuck_range_and_bearing");
			 m_pcCameraSensor = GetSensor<CCI_EPuckOmnidirectionalCameraSensor>("epuck_omnidirectional_camera");
		} catch (CARGoSException ex) {
			LOGERR<<"Error while initializing a Sensor!\n";
		}

		try{
			m_pcWheelsActuator = GetActuator<CCI_EPuckWheelsActuator>("epuck_wheels");
			m_pcRabActuator = GetActuator<CCI_EPuckRangeAndBearingActuator>("epuck_range_and_bearing");
			m_pcLEDsActuator = GetActuator<CCI_EPuckRGBLEDsActuator>("epuck_rgb_leds");
		} catch (CARGoSException ex) {
			LOGERR<<"Error while initializing an Actuator!\n";
		}
	}

	/****************************************/
	/****************************************/

	void AutoMoDeController::ControlStep() {
		/*
		 * 1. Update RobotDAO
		 */
		//TODO update all fields of RobotDAO
		if(m_pcRabSensor != NULL){
			const CCI_EPuckRangeAndBearingSensor::TPackets& packets = m_pcRabSensor->GetPackets();
			m_pcRobotState->SetNumberNeighbors(packets.size());
			m_pcRobotState->SetRangeAndBearingMessages(packets);
			m_pcRabSensor->ClearPackets();
		}
		if (m_pcGroundSensor != NULL) {
			const CCI_EPuckGroundSensor::SReadings& readings = m_pcGroundSensor->GetReadings();
			m_pcRobotState->SetGroundInput(readings);
		}
		if (m_pcLightSensor != NULL) {
			const CCI_EPuckLightSensor::TReadings& readings = m_pcLightSensor->GetReadings();
			m_pcRobotState->SetLightInput(readings);
		}
		if (m_pcProximitySensor != NULL) {
			const CCI_EPuckProximitySensor::TReadings& readings = m_pcProximitySensor->GetReadings();
			m_pcRobotState->SetProximityInput(readings);
		}


		/*
		 * 2. Execute step of FSM
		 */
		m_pcFiniteStateMachine->ControlStep();


		/*
		 * 3. Update Actuators
		 */
		if (m_pcWheelsActuator != NULL) {
			m_pcWheelsActuator->SetLinearVelocity(m_pcRobotState->GetRightWheelVelocity(), m_pcRobotState->GetLeftWheelVelocity());
		}
		m_unTimeStep++;
	}

	/****************************************/
	/****************************************/

	void AutoMoDeController::Destroy() {

	}

	/****************************************/
	/****************************************/

	void AutoMoDeController::Reset() {
		m_pcFiniteStateMachine->Reset();
		m_pcRobotState->Reset();
	}

	/****************************************/
	/****************************************/

	void AutoMoDeController::SetFiniteStateMachine(AutoMoDeFiniteStateMachine* pc_finite_state_machine) {
		m_pcFiniteStateMachine = pc_finite_state_machine;
		m_pcFiniteStateMachine->SetRobotDAO(m_pcRobotState);
		m_pcFiniteStateMachine->Init();
	}

	REGISTER_CONTROLLER(AutoMoDeController, "automode_controller");
}
