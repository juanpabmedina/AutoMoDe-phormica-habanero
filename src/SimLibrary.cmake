# Set up ARGoS compilation information
include_directories(${CMAKE_SOURCE_DIR} ${ARGOS_INCLUDE_DIRS})
link_directories(${ARGOS_LIBRARY_DIRS})

# Headers
set(AUTOMODE_HEADERS
	core/AutoMoDeController.h
	core/AutoMoDeFiniteStateMachine.h
	core/AutoMoDeFsmBuilder.h
	core/AutoMoDeFsmHistory.h
	# Behaviours
	modules/AutoMoDeBehaviour.h
	modules/AutoMoDeBehaviourStop.h
	modules/AutoMoDeBehaviourExploration.h
  modules/AutoMoDeBehaviourGoToColor.h
  modules/AutoMoDeBehaviourGoAwayColor.h
	modules/AutoMoDeBehaviourWaggle.h
	modules/AutoMoDeBehaviourGoToPheromone.h
	modules/AutoMoDeBehaviourAvoidPheromone.h

	modules/AutoMoDeBehaviourTuttiExploration.h
	modules/AutoMoDeBehaviourTuttiGoToColor.h
	modules/AutoMoDeBehaviourTuttiGoAwayColor.h
	modules/AutoMoDeBehaviourTuttiWaggle.h
	modules/AutoMoDeBehaviourTuttiStop.h

	# Conditions
	modules/AutoMoDeCondition.h
	modules/AutoMoDeConditionBlackFloor.h
	modules/AutoMoDeConditionWhiteFloor.h
	modules/AutoMoDeConditionGrayFloor.h
  modules/AutoMoDeConditionFixedProbability.h
  modules/AutoMoDeConditionProbColor.h
	modules/AutoMoDeConditionPheromoneDetected.h)


# Sources
set(AUTOMODE_SOURCES
	core/AutoMoDeController.cpp
	core/AutoMoDeFiniteStateMachine.cpp
	core/AutoMoDeFsmBuilder.cpp
	core/AutoMoDeFsmHistory.cpp
	# Behaviours
	modules/AutoMoDeBehaviour.cpp
	modules/AutoMoDeBehaviourStop.cpp
	modules/AutoMoDeBehaviourExploration.cpp
  modules/AutoMoDeBehaviourGoToColor.cpp
  modules/AutoMoDeBehaviourGoAwayColor.cpp
	modules/AutoMoDeBehaviourWaggle.cpp
	modules/AutoMoDeBehaviourGoToPheromone.cpp
	modules/AutoMoDeBehaviourAvoidPheromone.cpp

	modules/AutoMoDeBehaviourTuttiExploration.cpp
	modules/AutoMoDeBehaviourTuttiGoToColor.cpp
	modules/AutoMoDeBehaviourTuttiGoAwayColor.cpp
	modules/AutoMoDeBehaviourTuttiWaggle.cpp
	modules/AutoMoDeBehaviourTuttiStop.cpp
	# Conditions
	modules/AutoMoDeCondition.cpp
	modules/AutoMoDeConditionBlackFloor.cpp
	modules/AutoMoDeConditionWhiteFloor.cpp
	modules/AutoMoDeConditionGrayFloor.cpp
  modules/AutoMoDeConditionFixedProbability.cpp
  modules/AutoMoDeConditionProbColor.cpp
	modules/AutoMoDeConditionPheromoneDetected.cpp)


add_library(automode SHARED ${AUTOMODE_HEADERS} ${AUTOMODE_SOURCES})
target_link_libraries(automode argos3plugin_${ARGOS_BUILD_FOR}_epuck)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
add_executable(automode_main AutoMoDeMain.cpp)
target_link_libraries(automode_main automode argos3core_${ARGOS_BUILD_FOR} argos3plugin_${ARGOS_BUILD_FOR}_epuck argos3_demiurge_loop_functions argos3_demiurge_epuck_dao)

add_executable(visualize_fsm AutoMoDeVisualizeFSM.cpp)
target_link_libraries(visualize_fsm automode argos3core_${ARGOS_BUILD_FOR} argos3plugin_${ARGOS_BUILD_FOR}_epuck argos3_demiurge_epuck_dao)
