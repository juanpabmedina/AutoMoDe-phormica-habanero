/*
 * File: AutoMoDeRobotDAO.cpp
 * 
 */


#include "AutoMoDeRobotDAO.h"

namespace argos {
	
	AutoMoDeRobotDAO::AutoMoDeRobotDAO() {}
	
	AutoMoDeRobotDAO::~AutoMoDeRobotDAO() {}
	
	std::vector<UInt8> AutoMoDeRobotDAO::GetProximityInput() {
		return m_vecProximityInput;
	}
	
	void AutoMoDeRobotDAO::SetProximityInput(std::vector<UInt8> vec_prox_input) {
		m_vecProximityInput = vec_prox_input;
	}
	
	std::vector<UInt8> AutoMoDeRobotDAO::GetLightInput() {
		return m_vecLightInput;
	}
	
	void AutoMoDeRobotDAO::SetLightInput(std::vector<UInt8> vec_light_input) {
		m_vecLightInput = vec_light_input;
	}
	
	std::vector<UInt8> AutoMoDeRobotDAO::GetGroundInput() {
		return m_vecGroundInput;
	}
	
	void AutoMoDeRobotDAO::SetGroundInput(std::vector<UInt8> vec_ground_input) {
		m_vecGroundInput = vec_ground_input;
	}
	
	UInt8 AutoMoDeRobotDAO::GetNumberNeighbors() {
		return m_unNumberNeighbors;
	}
	
	void AutoMoDeRobotDAO::SetNumberNeighbors(UInt8 un_number_neighbors){
		m_unNumberNeighbors = un_number_neighbors;
	}
	
	std::vector<Real> AutoMoDeRobotDAO::GetRangesNeighbors() {
		return m_vecRangesNeighbors;
	}
	
	void AutoMoDeRobotDAO::SetRangesNeighbors(std::vector<Real> vec_ranges_neighbors){
		m_vecRangesNeighbors = vec_ranges_neighbors;
	}
	
	std::vector<Real> AutoMoDeRobotDAO::GetBearingsNeighbors() {
		return m_vecBearingsNeighbors;
	}
	
	void AutoMoDeRobotDAO::SetBearingsNeighbors(std::vector<Real> vec_bearings_neighbors) {
		m_vecBearingsNeighbors = vec_bearings_neighbors;
	}
			
	void AutoMoDeRobotDAO::SetWheelsVelocity(Real un_left_velocity, Real un_right_velocity) {
		m_fLeftWheelVelocity = un_left_velocity;
		m_fRightWheelVelocity = un_right_velocity;
	}
	
	Real AutoMoDeRobotDAO::GetRightWheelVelocity() {
		return m_fRightWheelVelocity;
	}
	
	Real AutoMoDeRobotDAO::GetLeftWheelVelocity() {
		return m_fLeftWheelVelocity;
	}
}
