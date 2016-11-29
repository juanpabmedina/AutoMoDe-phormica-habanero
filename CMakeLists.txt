# Headers
set(AUTOMODE_HEADERS
	AutoMoDeController.h
	finite_state_machine/AutoMoDeRabBuffer.h
	finite_state_machine/AutoMoDeFiniteStateMachine.h
	finite_state_machine/AutoMoDeFsmBuilder.h
	finite_state_machine/AutoMoDeFsmHistory.h
	finite_state_machine/AutoMoDeRobotDAO.h
	modules/AutoMoDeBehaviour.h
	modules/AutoMoDeBehaviourAntiPhototaxis.h
	modules/AutoMoDeBehaviourPhototaxis.h
	modules/AutoMoDeBehaviourAttraction.h
	modules/AutoMoDeBehaviourRepulsion.h
	modules/AutoMoDeBehaviourStop.h
	modules/AutoMoDeBehaviourExploration.h
	modules/AutoMoDeCondition.h
	modules/AutoMoDeConditionBlackFloor.h
	modules/AutoMoDeConditionWhiteFloor.h
	modules/AutoMoDeConditionGrayFloor.h
	modules/AutoMoDeConditionNeighborsCount.h
	modules/AutoMoDeConditionInvertedNeighborsCount.h
	modules/AutoMoDeConditionFixedProbability.h)

# Sources
set(AUTOMODE_SOURCES
	AutoMoDeController.cpp
	finite_state_machine/AutoMoDeRabBuffer.cpp
	finite_state_machine/AutoMoDeFiniteStateMachine.cpp
	finite_state_machine/AutoMoDeFsmBuilder.cpp
	finite_state_machine/AutoMoDeRobotDAO.cpp
	finite_state_machine/AutoMoDeFsmHistory.cpp
	modules/AutoMoDeBehaviour.cpp
	modules/AutoMoDeBehaviourAntiPhototaxis.cpp
	modules/AutoMoDeBehaviourPhototaxis.cpp
	modules/AutoMoDeBehaviourAttraction.cpp
	modules/AutoMoDeBehaviourRepulsion.cpp
	modules/AutoMoDeBehaviourStop.cpp
	modules/AutoMoDeBehaviourExploration.cpp
	modules/AutoMoDeCondition.cpp
	modules/AutoMoDeConditionBlackFloor.cpp
	modules/AutoMoDeConditionWhiteFloor.cpp
	modules/AutoMoDeConditionGrayFloor.cpp
	modules/AutoMoDeConditionNeighborsCount.cpp
	modules/AutoMoDeConditionInvertedNeighborsCount.cpp
	modules/AutoMoDeConditionFixedProbability.cpp)

if(ARGOS_BUILD_FOR_SIMULATOR)
	add_library(automode SHARED ${AUTOMODE_HEADERS} ${AUTOMODE_SOURCES})
	target_link_libraries(automode argos3plugin_${ARGOS_BUILD_FOR}_epuck)

	add_library(blackspot_loopfunc SHARED loop_functions/BlackSpotLoopFunc.h loop_functions/BlackSpotLoopFunc.cpp)
	target_link_libraries(blackspot_loopfunc argos3plugin_${ARGOS_BUILD_FOR}_epuck)
	
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../../controllers/argos3-AutoMoDe)
	add_executable(automode_main AutoMoDeMain.cpp ${AUTOMODE_HEADERS} ${AUTOMODE_SOURCES})
	target_link_libraries(automode_main argos3core_${ARGOS_BUILD_FOR}  argos3plugin_${ARGOS_BUILD_FOR}_epuck)

elseif(ARGOS_BUILD_FOR_EPUCK)
	add_executable(automode
        ${AUTOMODE_HEADERS}
        ${AUTOMODE_SOURCES})

	target_link_libraries(automode
    	argos3plugin_${ARGOS_BUILD_FOR}_epuck)
endif(ARGOS_BUILD_FOR_SIMULATOR)
