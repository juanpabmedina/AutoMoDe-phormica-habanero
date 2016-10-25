/*
 * File: AutoMoDeController.h
 * 
 */

#ifndef AUTOMODE_CONTROLLER_H
#define AUTOMODE_CONTROLLER_H

#include <argos3/core/utility/logging/argos_log.h>
#include <argos3/core/control_interface/ci_controller.h>

#include "./finite_state_machine/AutoMoDeFiniteStateMachine.h"
#include "./finite_state_machine/AutoMoDeFsmBuilder.h"
#include "./finite_state_machine/AutoMoDeRobotDAO.h"

#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_wheels_actuator.h>
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_range_and_bearing_sensor.h>
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_range_and_bearing_actuator.h>
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_rgb_leds_actuator.h>
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_proximity_sensor.h>
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_light_sensor.h>
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_ground_sensor.h>
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_omnidirectional_camera_sensor.h>

namespace argos{
	class AutoMoDeController: public CCI_Controller {
		public:
			AutoMoDeController();
			
			virtual ~AutoMoDeController();
			
			virtual void Init(TConfigurationNode& t_node);
			virtual void ControlStep();
			virtual void Reset();
			virtual void Destroy();
			
			void SetFiniteStateMachine(AutoMoDeFiniteStateMachine* pc_fine_state_machine);
		
		private:
			AutoMoDeFiniteStateMachine* m_pcFiniteStateMachine;
			AutoMoDeRobotDAO* m_pcRobotState;
			UInt8 m_unTimeStep;
			UInt32 m_unRobotID;
			
			std::string m_strFsmConfiguration;
			bool m_bMaintainHistory;
			bool m_bPrintReadableFsm;
			
			AutoMoDeFsmBuilder* m_pcFsmBuilder;
			
			CCI_EPuckWheelsActuator* m_pcWheelsActuator;
			CCI_EPuckRangeAndBearingActuator* m_pcRabActuator;
			CCI_EPuckRGBLEDsActuator* m_pcLEDsActuator;

			CCI_EPuckProximitySensor* m_pcProximitySensor;
			CCI_EPuckRangeAndBearingSensor* m_pcRabSensor;
			CCI_EPuckLightSensor* m_pcLightSensor;
			CCI_EPuckGroundSensor* m_pcGroundSensor;
			CCI_EPuckOmnidirectionalCameraSensor* m_pcCameraSensor;
	};
}

#endif
