/**
 * @file AutoMoDeRobotDAO.cpp
 * 
 * @brief This class represents the status of the robot.
 * It contains the input variables (the sensor inputs) and
 * the output variables (the values for the wheel actuators),
 * as well as the setters and getters to access them.
 * 
 * Only one object of this class should be instanciated, and 
 * is to be used as a brigde between the AutoMoDeController and 
 * the AutoMoDeFiniteStateMachine classes. In AutoMoDeController,
 * the variables of the object shall be updated before being sent to 
 * the AutoMoDeFiniteStateMachine. The AutoMoDeFiniteStateMachine will
 * then use the input variables and update the output variables
 * accordingly.
 * 
 */


#ifndef AUTOMODE_ROBOT_DAO_H
#define AUTOMODE_ROBOT_DAO_H

#include <vector>
#include <argos3/core/utility/math/rng.h> 
#include <argos3/core/utility/logging/argos_log.h> 
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_wheels_actuator.h>
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_range_and_bearing_sensor.h>
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_range_and_bearing_actuator.h>
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_rgb_leds_actuator.h>
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_proximity_sensor.h>
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_light_sensor.h>
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_ground_sensor.h>
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_omnidirectional_camera_sensor.h>

namespace argos {
	class AutoMoDeRobotDAO {
		public:
			AutoMoDeRobotDAO();
			virtual ~AutoMoDeRobotDAO();
			
			CCI_EPuckProximitySensor::TReadings GetProximityInput();
			void SetProximityInput(CCI_EPuckProximitySensor::TReadings s_prox_input);
			
			CCI_EPuckLightSensor::TReadings GetLightInput();
			void SetLightInput(CCI_EPuckLightSensor::TReadings s_light_input);
			
			CCI_EPuckGroundSensor::SReadings GetGroundInput();
			void SetGroundInput(CCI_EPuckGroundSensor::SReadings s_ground_input);
			
			UInt8 GetNumberNeighbors();
			void SetNumberNeighbors(UInt8 un_number_neighbors);
			
			CCI_EPuckRangeAndBearingSensor::TPackets GetRangeAndBearingMessages();
			void SetRangeAndBearingMessages(CCI_EPuckRangeAndBearingSensor::TPackets);
			
			void SetWheelsVelocity(Real un_left_velocity, Real un_right_velocity);
			Real GetRightWheelVelocity();
			Real GetLeftWheelVelocity();
			
			void SetRobotIdentifier(UInt32 un_robot_id);
			UInt32 GetRobotIdentifier();
			
			void Reset();
			
			CRandom::CRNG* GetRandomNumberGenerator();
			
		private:
			CCI_EPuckProximitySensor::TReadings m_sProximityInput;
			CCI_EPuckLightSensor::TReadings m_sLightInput;
			CCI_EPuckGroundSensor::SReadings m_sGroundInput;
			
			UInt8 m_unNumberNeighbors;
			CCI_EPuckRangeAndBearingSensor::TPackets m_sRangeAndBearingMessages;
			
			Real m_fLeftWheelVelocity;
			Real m_fRightWheelVelocity;
			
			UInt32 m_unRobotIdentifier;
			
			CRandom::CRNG* m_pcRng;
	};
}


#endif
