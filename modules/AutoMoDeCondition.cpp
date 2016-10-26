/*
 * File: AutoMoDeCondition.cpp
 *
 */

#include "AutoMoDeCondition.h"

namespace argos {

	/****************************************/
	/****************************************/

	const std::string AutoMoDeCondition::GetUrlDescription() {
		std::stringstream ss;
		ss << m_strLabel;
		if (!m_mapParameters.empty()) {
			std::map<std::string, Real>::iterator it;
			for (it = m_mapParameters.begin(); it != m_mapParameters.end(); it++) {
				ss << "\\n" << it->first << "=" << it->second ;
			}
		}
		return ss.str();
	}

	/****************************************/
	/****************************************/

	void AutoMoDeCondition::AddParameter(std::string str_identifier, Real f_value) {
		m_mapParameters.insert(std::pair<std::string, Real>(str_identifier, f_value));
	}

	/****************************************/
	/****************************************/

	const UInt8 AutoMoDeCondition::GetOrigin() {
		return m_unFromBehaviourIndex;
	}

	/****************************************/
	/****************************************/

	const UInt8 AutoMoDeCondition::GetExtremity() {
		return m_unToBehaviourIndex;
	}

	/****************************************/
	/****************************************/

	void AutoMoDeCondition::SetOrigin(UInt8 un_from) {
		m_unFromBehaviourIndex = un_from;
	}

	/****************************************/
	/****************************************/

	void AutoMoDeCondition::SetExtremity(UInt8 un_to) {
		m_unToBehaviourIndex = un_to;
	}

	/****************************************/
	/****************************************/

	void AutoMoDeCondition::SetOriginAndExtremity(UInt8 un_from, UInt8 un_to) {
		m_unFromBehaviourIndex = un_from;
		m_unToBehaviourIndex = un_to;
	}

	/****************************************/
	/****************************************/

	const std::string AutoMoDeCondition::GetLabel() {
		return m_strLabel;
	}

	/****************************************/
	/****************************************/

	void AutoMoDeCondition::SetIndex(UInt8 un_index) {
		m_unIndex = un_index;
	}

	/****************************************/
	/****************************************/

	const UInt8 AutoMoDeCondition::GetIndex() {
		return m_unIndex;
	}

	/****************************************/
	/****************************************/

	void AutoMoDeCondition::SetIdentifier(UInt8 un_id) {
		m_unIdentifier = un_id;
	}

	/****************************************/
	/****************************************/

	const UInt8 AutoMoDeCondition::GetIdentifier() {
		return m_unIdentifier;
	}

	/****************************************/
	/****************************************/

	std::map<std::string, Real> AutoMoDeCondition::GetParameters() {
		return m_mapParameters;
	}

    /****************************************/
	/****************************************/

    void SetRobotDao(AutoMoDeRobotDAO* pc_robot_dao) {
        m_pcRobotDao = pc_robot_dao;
    }

}
