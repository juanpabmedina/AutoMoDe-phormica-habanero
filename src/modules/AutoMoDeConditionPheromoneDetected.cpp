/**
  * @file <src/modules/AutoMoDeConditionColor.cpp>
  *
  * @author Antoine Ligot - <aligot@ulb.ac.be>
  *
  * @package ARGoS3-AutoMoDe
  *
  * @license MIT License
  */

 #include "AutoMoDeConditionPheromoneDetected.h"

 namespace argos {

  /****************************************/
  /****************************************/

    AutoMoDeConditionPheromoneDetected::AutoMoDeConditionPheromoneDetected() {
        m_strLabel = "PheromoneDetected";
	}

  /****************************************/
  /****************************************/

    AutoMoDeConditionPheromoneDetected::~AutoMoDeConditionPheromoneDetected() {}

  /****************************************/
  /****************************************/

    AutoMoDeConditionPheromoneDetected::AutoMoDeConditionPheromoneDetected(AutoMoDeConditionPheromoneDetected* pc_condition) {
		m_strLabel = pc_condition->GetLabel();
		m_unIndex = pc_condition->GetIndex();
		m_unIdentifier = pc_condition->GetIndex();
		m_unFromBehaviourIndex = pc_condition->GetOrigin();
		m_unToBehaviourIndex = pc_condition->GetExtremity();
		m_mapParameters = pc_condition->GetParameters();
    Init();
	}

  /****************************************/
  /****************************************/

    void AutoMoDeConditionPheromoneDetected::Init() {
        std::map<std::string, Real>::iterator it = m_mapParameters.find("p");
        if (it != m_mapParameters.end()) {
            m_fProbability = it->second;
        } else {
            LOGERR << "[FATAL] Missing parameter for the following condition:" << m_strLabel << std::endl;
            THROW_ARGOSEXCEPTION("Missing Parameter");
        }
        it = m_mapParameters.find("f");
        if (it != m_mapParameters.end()) {
            m_unFOVParameter = (it->second);

            if (m_unFOVParameter == 0) {
              m_unFOVParameter = 0.26; // directional field of view of 30 degree
            } else {
              m_unFOVParameter = 3.14; // Omni directional view of 360 degree
            }

        } else {
            LOGERR << "[FATAL] Missing parameter for the following behaviour:" << m_strLabel << std::endl;
            THROW_ARGOSEXCEPTION("Missing Parameter");
        }
        // it = m_mapParameters.find("l");
        // if (it != m_mapParameters.end()) {
        //     m_cColorParameter = GetColorParameter(it->second);
                m_cColorParameter = CColor::MAGENTA; //Magenta color
        // } else {
        //     LOGERR << "[FATAL] Missing parameter for the following condition:" << m_strLabel << std::endl;
        //     THROW_ARGOSEXCEPTION("Missing Parameter");
        // }
    }

  /****************************************/
  /****************************************/

    AutoMoDeConditionPheromoneDetected* AutoMoDeConditionPheromoneDetected::Clone() {
        return new AutoMoDeConditionPheromoneDetected(this);
	}

  /****************************************/
  /****************************************/

    bool AutoMoDeConditionPheromoneDetected::Verify() {
        CCI_EPuckOmnidirectionalCameraSensor::SReadings sReadings = m_pcRobotDAO->GetCameraInput();
        CCI_EPuckOmnidirectionalCameraSensor::TBlobList::iterator it;
        bool bColorPerceived = false;

        for (it = sReadings.BlobList.begin(); it != sReadings.BlobList.end(); it++) {
            if ((*it)->Color == m_cColorParameter && (*it)->Distance >= 4.5    &&  (*it)->Distance <= 25) {
                //LOG << "Distance Pheromone: " << (*it)->Distance << std::endl;
              if ((*it)->Angle.SignedNormalize().GetValue() >= 0 && (*it)->Angle.SignedNormalize().GetValue() <= m_unFOVParameter) {
                  bColorPerceived = true;
                  break;
              }
              else if ((*it)->Angle.SignedNormalize().GetValue() < 0 && (*it)->Angle.SignedNormalize().GetValue() >= -m_unFOVParameter) {
                  bColorPerceived = true;
                 break;
              }
            }
        }

        if (bColorPerceived){
            return EvaluateBernoulliProbability(m_fProbability);
        }

    return false;
 }

  /****************************************/
  /****************************************/

    void AutoMoDeConditionPheromoneDetected::Reset() {
    Init();
  }

 }
