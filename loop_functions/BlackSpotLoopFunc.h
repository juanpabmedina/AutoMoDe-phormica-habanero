/*
    Test of loop function to generate black spot on the floor

*/

#ifndef BLACKSPOTLOOPFUNC_H
#define	BLACKSPOTLOOPFUNC_H

#include <argos3/core/simulator/loop_functions.h>

using namespace argos;

class BlackSpotLoopFunction: public CLoopFunctions {
    public:
        BlackSpotLoopFunction();
        BlackSpotLoopFunction(const BlackSpotLoopFunction& orig);
        virtual ~BlackSpotLoopFunction();

        virtual void Init(argos::TConfigurationNode& t_tree);
        virtual void Reset();
        virtual void Destroy();

        virtual argos::CColor GetFloorColor(const argos::CVector2& c_position_on_plane);
};

#endif	/* BLACKSPOTLOOPFUNC_H */
