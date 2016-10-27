/*
 * File: AutoMoDeBehaviour.h
 *
 */

#ifndef AUTOMODEBEHAVIOUR_H
#define AUTOMODEBEHAVIOUR_H

#include <argos3/core/utility/math/vector2.h>
#include <argos3/core/utility/logging/argos_log.h>
#include <argos3/core/utility/configuration/argos_exception.h>

#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_proximity_sensor.h>
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_range_and_bearing_sensor.h>

#include "../finite_state_machine/AutoMoDeRobotDAO.h"

#include <map>

namespace argos {
	class AutoMoDeBehaviour {
		protected:
			/**
			 * Tells whether or not the behaviour is locked for a given
			 * number of steps. No conditions should be tested if it is locked.
			 */
			bool m_bLocked;

			/**
			 * Tells whether or not the behaviour is ready to be executed.
			 * This could happen if a previous reseting step takes more than
			 * one time step.
			 */
			bool m_bOperational;

			/**
			 * Contains the parameters of the behaviours.
			 */
			std::map<std::string, Real> m_mapParameters;
			std::string m_strLabel;
			UInt8 m_unIndex;
			UInt8 m_unIdentifier;
            AutoMoDeRobotDAO* m_pcRobotDAO;

		public:
			/**
			 * Execution of the behaviour. Based on the state of the robot,
			 * the behaviour should update the output variables.
			 */
			virtual void ControlStep() = 0;

			/**
			 * Method used to reset the status (variables) of the behaviour.
			 */
			virtual void Reset() = 0;

			/**
			 * Method called at the reseting of the behaviour when more than one
			 * time step are needed to prepare before the execution of the behaviour
			 * (that is the call of ControlStep).
			 */
			virtual void ResumeStep() = 0;

			/**
			 * Initialize the behaviour.
			 */
			virtual void Init() = 0;

			virtual AutoMoDeBehaviour* Clone() = 0;

			const std::string GetUrlDescription();

			void AddParameter(std::string str_identifier, Real f_value);
			const Real GetParameter(std::string str_identifier);
			const std::map<std::string, Real> GetParameters();

			void SetIndex(UInt8 un_index);
			const UInt8 GetIndex();

			void SetIdentifier(UInt8 un_id);
			const UInt8 GetIdentifier();

			const std::string GetLabel();

			const bool IsLocked();
			const bool IsOperational();

			CVector2 ComputeWheelsVelocityFromVector(CVector2 c_vector_to_follow);
			CVector2 SumProximityReadings(CCI_EPuckProximitySensor::TReadings s_prox);
			CVector2 ParseLight(CVector2 c_light);

			void SetRobotDAO(AutoMoDeRobotDAO* pc_robot_dao);
	};
}

#endif
