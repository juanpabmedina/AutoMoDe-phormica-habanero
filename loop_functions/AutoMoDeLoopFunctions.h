#ifndef AUTOMODE_LOOP_FUNCTIONS
#define AUTOMODE_LOOP_FUNCTIONS

#include <argos3/core/simulator/space/space.h>
#include <argos3/core/simulator/loop_functions.h>
#include <argos3/plugins/robots/e-puck/simulator/epuck_entity.h>

using namespace argos;

class AutoMoDeLoopFunctions: public CLoopFunctions {
  public:
    virtual Real GetObjectiveFunction() = 0;
};

#endif
