/*
    Test of loop function to generate black spot on the floor

*/

#include "BlackSpotLoopFunc.h"


BlackSpotLoopFunction::BlackSpotLoopFunction(){
}

BlackSpotLoopFunction::BlackSpotLoopFunction(const BlackSpotLoopFunction& orig) {
}

BlackSpotLoopFunction::~BlackSpotLoopFunction() {
}

void BlackSpotLoopFunction::Init(argos::TConfigurationNode& t_tree) {

    /* Initialize the objective function */

    Reset();
}

void BlackSpotLoopFunction::Reset() {

}

void BlackSpotLoopFunction::Destroy() {

}

argos::CColor BlackSpotLoopFunction::GetFloorColor(const argos::CVector2& c_position_on_plane) {

	// if(sqrt(pow(c_position_on_plane.GetX(),2) + pow(c_position_on_plane.GetY() - 0.6,2)) < 0.30f) {
	//   return CColor::WHITE;
	// }

	if(sqrt(pow(c_position_on_plane.GetX(),2) + pow(c_position_on_plane.GetY() + 0.6,2)) < 0.50f) {
	  return CColor::BLACK;
	}

    else {
        return CColor::GRAY50;
    }

}


REGISTER_LOOP_FUNCTIONS(BlackSpotLoopFunction, "blackspot_loop_functions");
