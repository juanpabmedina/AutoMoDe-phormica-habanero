#ifndef AGGREGATION_LOOP_FUNC
#define AGGREGATION_LOOP_FUNC

#include "AutoMoDeLoopFunctions.h"
#include <argos3/core/simulator/space/space.h>
#include <argos3/plugins/robots/e-puck/simulator/epuck_entity.h>

using namespace argos;

class AggregationLoopFunction: public AutoMoDeLoopFunctions {
  public:
    AggregationLoopFunction();
    AggregationLoopFunction(const AggregationLoopFunction& orig);
    virtual ~AggregationLoopFunction();

    //virtual void Init(argos::TConfigurationNode& t_tree);
    virtual void Reset();
    virtual void Destroy();

    virtual argos::CColor GetFloorColor(const argos::CVector2& c_position_on_plane);
    virtual void PostExperiment();

    Real GetObjectiveFunction();
  private:
    Real m_fRadius;
    CVector2 m_cCoordSpot1;
    CVector2 m_cCoordSpot2;

    UInt32 m_unScoreSpot1;
    UInt32 m_unScoreSpot2;
    UInt32 m_unNumberRobots;
    Real m_fObjectiveFunction;
};

#endif
