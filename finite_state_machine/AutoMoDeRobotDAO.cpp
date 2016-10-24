/*
 * File: AutoMoDeRobotDAO.cpp
 * 
 */


#include "AutoMoDeRobotDAO.h"

namespace argos {
	
	/****************************************/
	/****************************************/
	
	AutoMoDeRobotDAO::AutoMoDeRobotDAO() {
		Reset();
	}
	
	/****************************************/
	/****************************************/
	
	AutoMoDeRobotDAO::~AutoMoDeRobotDAO() {}
	
	/****************************************/
	/****************************************/
	
	CCI_EPuckProximitySensor::TReadings AutoMoDeRobotDAO::GetProximityInput() {
		return m_sProximityInput;
	}
	
	/****************************************/
	/****************************************/
	
	void AutoMoDeRobotDAO::SetProximityInput(CCI_EPuckProximitySensor::TReadings s_prox_input) {
		m_sProximityInput = s_prox_input;
	}
	
	/****************************************/
	/****************************************/
	
	CCI_EPuckLightSensor::TReadings AutoMoDeRobotDAO::GetLightInput() {
		return m_sLightInput;
	}
	
	/****************************************/
	/****************************************/
	
	void AutoMoDeRobotDAO::SetLightInput(CCI_EPuckLightSensor::TReadings s_light_input) {
		m_sLightInput = s_light_input;
	}
	
	/****************************************/
	/****************************************/
	
	CCI_EPuckGroundSensor::SReadings AutoMoDeRobotDAO::GetGroundInput() {
		return m_sGroundInput;
	}
	
	/****************************************/
	/****************************************/
	
	void AutoMoDeRobotDAO::SetGroundInput(CCI_EPuckGroundSensor::SReadings s_ground_input) {
		m_sGroundInput = s_ground_input;
	}
	
	/****************************************/
	/****************************************/
	
	UInt8 AutoMoDeRobotDAO::GetNumberNeighbors() {
		return m_unNumberNeighbors;
	}
	
	/****************************************/
	/****************************************/
	
	void AutoMoDeRobotDAO::SetNumberNeighbors(UInt8 un_number_neighbors){
		m_unNumberNeighbors = un_number_neighbors;
	}
	
	/****************************************/
	/****************************************/
	
	std::vector<Real> AutoMoDeRobotDAO::GetRangesNeighbors() {
		return m_vecRangesNeighbors;
	}
	
	/****************************************/
	/****************************************/
	
	void AutoMoDeRobotDAO::SetRangesNeighbors(std::vector<Real> vec_ranges_neighbors){
		m_vecRangesNeighbors = vec_ranges_neighbors;
	}
	
	/****************************************/
	/****************************************/
	
	std::vector<Real> AutoMoDeRobotDAO::GetBearingsNeighbors() {
		return m_vecBearingsNeighbors;
	}
	
	/****************************************/
	/****************************************/
	
	void AutoMoDeRobotDAO::SetBearingsNeighbors(std::vector<Real> vec_bearings_neighbors) {
		m_vecBearingsNeighbors = vec_bearings_neighbors;
	}
			
	/****************************************/
	/****************************************/		
			
	void AutoMoDeRobotDAO::SetWheelsVelocity(Real un_left_velocity, Real un_right_velocity) {
		m_fLeftWheelVelocity = un_left_velocity;
		m_fRightWheelVelocity = un_right_velocity;
	}
	
	/****************************************/
	/****************************************/
	
	Real AutoMoDeRobotDAO::GetRightWheelVelocity() {
		return m_fRightWheelVelocity;
	}
	
	/****************************************/
	/****************************************/
	
	Real AutoMoDeRobotDAO::GetLeftWheelVelocity() {
		return m_fLeftWheelVelocity;
	}
	
	/****************************************/
	/****************************************/
	
	void AutoMoDeRobotDAO::Reset() {
		m_fLeftWheelVelocity = 0;
		m_fRightWheelVelocity = 0;
	}
}
