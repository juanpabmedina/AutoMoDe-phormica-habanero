/*
 * File: AutoMoDeController.cpp
 * 
 */

#include "AutoMoDeController.h"

namespace argos {
	
	AutoMoDeController::AutoMoDeController() {
		m_pcRobotState = new AutoMoDeRobotDAO();
		m_unTimeStep = 0;
		m_strFsmConfiguration = "";
		m_bMaintainHistory = false;
		m_bPrintReadableFsm = false;
	}
	
	AutoMoDeController::~AutoMoDeController() {
		
	}
	
	void AutoMoDeController::Init(TConfigurationNode& t_node) {
		// Parsing parameters
		try {
			GetNodeAttributeOrDefault(t_node, "fsm-config", m_strFsmConfiguration, m_strFsmConfiguration);
			GetNodeAttributeOrDefault(t_node, "history", m_bMaintainHistory, m_bMaintainHistory);
			GetNodeAttributeOrDefault(t_node, "readable", m_bPrintReadableFsm, m_bPrintReadableFsm);
		} catch (CARGoSException& ex) {
			THROW_ARGOSEXCEPTION_NESTED("Error parsing <params>", ex);
		}
	
		/*
		 * If a FSM configuration is given as parameter of the experiment file, create a FSM from it
		 */
		if (m_strFsmConfiguration.compare("") != 0) {
			m_pcFsmBuilder = new AutoMoDeFsmBuilder();
			SetFiniteStateMachine(m_pcFsmBuilder->BuildFiniteStateMachine(m_strFsmConfiguration));
			if (m_bMaintainHistory) {
				m_pcFiniteStateMachine->MaintainHistory();   // Give here path (file with ID of robot)
			}
			if (m_bPrintReadableFsm) {
				std::cout << m_pcFiniteStateMachine->GetReadableFormat() << std::endl;
			}
		} 
		
		/*
		 *  Initializing sensors and actuators 
		 */
		try{
			// TODO: add all sensors
			//m_pcRabSensor = GetSensor<CCI_EPuckRangeAndBearingSensor>("epuck_range_and_bearing");
		} catch (CARGoSException ex) {
			LOGERR<<"Error while initializing a Sensor!\n";
		}
	
		try{
			// TODO: add all actuators
			//m_pcWheelsActuator = GetActuator<CCI_EPuckWheelsActuator>("epuck_wheels");
			//m_pcRabActuator = GetActuator<CCI_EPuckRangeAndBearingActuator>("epuck_range_and_bearing");
		} catch (CARGoSException ex) {
			LOGERR<<"Error while initializing an Actuator!\n";
		}
	}
	
	void AutoMoDeController::ControlStep() {
		/*
		 * 1. Update RobotDAO
		 *
		//TODO update all fields of RobotDAO
		if(m_pcRabSensor!= NULL){
			const CCI_EPuckRangeAndBearingSensor::TPackets& packets = m_pcRabSensor->GetPackets();
			m_pcRobotState->SetNumberNeighbors(packets.size());
			
			m_pcRabSensor->ClearPackets();
		}
		*/
	 
		
		/*
		 * 2. Execute step of FSM
		 */ 
		m_pcFiniteStateMachine->ControlStep(m_pcRobotState);
		
		
		/*
		 * 3. Update Actuators
		 */ 
		//if (m_pcWheelsActuator != NULL) {
		//	m_pcWheelsActuator->SetLinearVelocity(m_pcRobotState->GetRightWheelVelocity(),m_pcRobotState->GetLeftWheelVelocity());
		//}
		m_unTimeStep++;
	}
	
	void AutoMoDeController::Destroy() {
		
	}
	
	void AutoMoDeController::Reset() {
		
	}
	
	void AutoMoDeController::SetFiniteStateMachine(AutoMoDeFiniteStateMachine* pc_finite_state_machine) {
		m_pcFiniteStateMachine = pc_finite_state_machine;
		m_pcFiniteStateMachine->Init();
	}
}

REGISTER_CONTROLLER(AutoMoDeController, "automode_controller");
