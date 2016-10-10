/*
 * File: AutoMoDeBehaviour.h
 *
 */
 
#ifndef AUTOMODEBEHAVIOUR_H
#define AUTOMODEBEHAVIOUR_H

#include <argos3/core/utility/math/vector2.h>
#include <argos3/core/utility/logging/argos_log.h>

#include "../finite_state_machine/AutoMoDeRobotDAO.h"

#include <map>

namespace argos {
	class AutoMoDeBehaviour {
		protected:
			bool m_bLocked;
			bool m_bOperational; // tells whether or not the behaviour is ready to go in ControlStep.
			std::map<std::string, Real> m_mapParameters;
			std::string m_strLabel;
			UInt8 m_unIndex;
			UInt8 m_unIdentifier;
		
		public:
			virtual void ControlStep(AutoMoDeRobotDAO* pc_robot_dao) = 0;     //TODO: Add EPuckDAO as parameter
			virtual void Reset() = 0;
			virtual void ResumeStep() = 0; 			// Step before ControlStep to prepare 
			
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
			
			CVector2 ComputeVectorToFollow(CVector2 c_sum);
			CVector2 ParseProximity(CVector2 c_prox);
			CVector2 ParseLight(CVector2 c_light);
	};
}

#endif
