/*
 * File: AutoMoDeConditionFixedProbability.cpp
 *
 */

 #include "AutoMoDeConditionFixedProbability.h"

 namespace argos {

	AutoMoDeConditionFixedProbability::AutoMoDeConditionFixedProbability() {
		m_strLabel = "FixedProbability";
	}

	AutoMoDeConditionFixedProbability::~AutoMoDeConditionFixedProbability() {}

	AutoMoDeConditionFixedProbability::AutoMoDeConditionFixedProbability(AutoMoDeConditionFixedProbability* pc_condition) {
		m_strLabel = pc_condition->GetLabel();
		m_unIndex = pc_condition->GetIndex();
		m_unIdentifier = pc_condition->GetIndex();
		m_unFromBehaviourIndex = pc_condition->GetOrigin();
		m_unToBehaviourIndex = pc_condition->GetExtremity();
		m_mapParameters = pc_condition->GetParameters();
	}

	AutoMoDeConditionFixedProbability* AutoMoDeConditionFixedProbability::Clone() {
		return new AutoMoDeConditionFixedProbability(*this);
	}
	
	void AutoMoDeConditionFixedProbability::Init() {
		m_fProbability = 0.5; //TODO init from m_mapParameters
	}

	bool AutoMoDeConditionFixedProbability::Verify() {
		return EvaluateBernoulliProbability(m_fProbability);
	}

	void AutoMoDeConditionFixedProbability::Reset() {

	}

 }
