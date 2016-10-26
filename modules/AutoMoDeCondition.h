/*
 * File: AutoMoDeCondition.h
 *
 */

#ifndef AUTOMODECONDITION_H
#define AUTOMODECONDITION_H

#include <argos3/core/utility/math/vector2.h>
#include <argos3/core/utility/logging/argos_log.h>

#include "../finite_state_machine/AutoMoDeRobotDAO.h"

#include <map>

namespace argos {
	class AutoMoDeCondition {
		protected:
			std::map<std::string, Real> m_mapParameters;
			UInt8 m_unFromBehaviourIndex;
			UInt8 m_unToBehaviourIndex;
			std::string m_strLabel;
			UInt8 m_unIndex;
			UInt8 m_unIdentifier;
			AutoMoDeRobotDAO* m_pcRobotDAO;

		public:
			virtual bool Verify() = 0;
			virtual void Reset() = 0;

			const std::string GetUrlDescription();

			virtual AutoMoDeCondition* Clone() = 0;

			void SetOriginAndExtremity(UInt8 un_from, UInt8 un_to);
			void SetOrigin(UInt8 un_from);
			void SetExtremity(UInt8 un_to);
			void SetIndex(UInt8 un_index);
			const UInt8 GetOrigin();
			const UInt8 GetExtremity();
			const UInt8 GetIndex();

			void SetIdentifier(UInt8 un_id);
			const UInt8 GetIdentifier();

			void AddParameter(std::string str_identifier, Real f_value);
			Real GetParameter(std::string str_identifier);
			std::map<std::string, Real> GetParameters();

			const std::string GetLabel();
			void SetRobotDAO(AutoMoDeRobotDAO* pc_robot_dao);
	};
}

#endif
