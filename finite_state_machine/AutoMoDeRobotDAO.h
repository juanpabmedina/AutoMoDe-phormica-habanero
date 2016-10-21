/*
 * File: AutoMoDeRobotDAO.h
 * 
 */


#ifndef AUTOMODE_ROBOT_DAO_H
#define AUTOMODE_ROBOT_DAO_H

#include <vector>
#include <argos3/core/utility/logging/argos_log.h> 
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_proximity_sensor.h>

namespace argos {
	class AutoMoDeRobotDAO {
		public:
			AutoMoDeRobotDAO();
			virtual ~AutoMoDeRobotDAO();
			
			CCI_EPuckProximitySensor::TReadings GetProximityInput();
			void SetProximityInput(CCI_EPuckProximitySensor::TReadings vec_prox_input);
			
			std::vector<UInt8> GetLightInput();
			void SetLightInput(std::vector<UInt8> vec_light_input);
			
			std::vector<UInt8> GetGroundInput();
			void SetGroundInput(std::vector<UInt8> vec_ground_input);
			
			UInt8 GetNumberNeighbors();
			void SetNumberNeighbors(UInt8 un_number_neighbors);
			
			std::vector<Real> GetRangesNeighbors();
			void SetRangesNeighbors(std::vector<Real> vec_ranges_neighbors);
			
			std::vector<Real> GetBearingsNeighbors();
			void SetBearingsNeighbors(std::vector<Real> vec_bearings_neighbors);
			
			void SetWheelsVelocity(Real un_left_velocity, Real un_right_velocity);
			Real GetRightWheelVelocity();
			Real GetLeftWheelVelocity();
			
		private:
			CCI_EPuckProximitySensor::TReadings m_sProximityInput;
			std::vector<UInt8> m_vecLightInput;
			std::vector<UInt8> m_vecGroundInput;
			
			UInt8 m_unNumberNeighbors;
			std::vector<Real> m_vecRangesNeighbors;
			std::vector<Real> m_vecBearingsNeighbors;
			
			Real m_fLeftWheelVelocity;
			Real m_fRightWheelVelocity;
	};
}


#endif
