/*
 * @file <src/core/AutoMoDeLoopFunctions.cpp>
 *
 * @author Antoine Ligot - <aligot@ulb.ac.be>
 *
 * @package ARGoS3-AutoMoDe
 *
 * @license MIT License
 */


#include "AutoMoDeLoopFunctions.h"

/****************************************/
/****************************************/

void AutoMoDeLoopFunctions::Init(argos::TConfigurationNode& t_tree) {
  m_pcRng = CRandom::CreateRNG("argos");
  TConfigurationNode cParametersNode;
  try {
    cParametersNode = GetNode(t_tree, "params");
    GetNodeAttributeOrDefault(cParametersNode, "number_robots", m_unNumberRobots, (UInt32) 1);
    GetNodeAttributeOrDefault(cParametersNode, "dist_radius", m_fDistributionRadius, (Real) 0);
  } catch(std::exception e) {
    LOGERR << e.what() << std::endl;
  }

  PositionRobots();
}

/****************************************/
/****************************************/

void AutoMoDeLoopFunctions::Reset() {
  RemoveRobots();
  PositionRobots();
}

/****************************************/
/****************************************/

AutoMoDeLoopFunctions::~AutoMoDeLoopFunctions() {}

/****************************************/
/****************************************/

/****************************************/
/****************************************/

void AutoMoDeLoopFunctions::RemoveRobots() {
  for(UInt32 i = 1; i < m_unNumberRobots + 1; ++i) {
    std::ostringstream id;
    id << "epuck" << i;
    RemoveEntity(id.str().c_str());
  }
}
