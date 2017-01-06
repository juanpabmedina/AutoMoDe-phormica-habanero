/**
  * @file <loop-functions/example/ChocolateSCALoopFunc.cpp>
  *
  * @author Antoine Ligot - <aligot@ulb.ac.be>
  *
  * @package ARGoS3-AutoMoDe
  *
  * @license MIT License
  */

#include "ChocolateSCALoopFunc.h"

/****************************************/
/****************************************/

ChocolateSCALoopFunction::ChocolateSCALoopFunction() {
  m_fSpotRadius = 0.3;
  m_cCoordBlackSpot = CVector2(0.8,-0.1);
  m_cCoordWhiteSpot = CVector2(-0.8,-0.1);
  m_fObjectiveFunction = 0;
  m_fWidthShelter = 0.6;
  m_fHeightShelter = 0.15;
  m_cPositionShelter = CVector2(0,0);
}

/****************************************/
/****************************************/

ChocolateSCALoopFunction::ChocolateSCALoopFunction(const ChocolateSCALoopFunction& orig) {}

/****************************************/
/****************************************/

ChocolateSCALoopFunction::~ChocolateSCALoopFunction() {}

/****************************************/
/****************************************/

void ChocolateSCALoopFunction::Destroy() {}

void ChocolateSCALoopFunction::Init(TConfigurationNode& t_tree) {
  AutoMoDeLoopFunctions::Init(t_tree);

  CQuaternion angleWall;

  // Center
  angleWall.FromEulerAngles(CRadians::PI_OVER_TWO, CRadians::ZERO, CRadians::ZERO);
  m_pcBoxCenter = new CBoxEntity("wall_center",
      CVector3(0, m_cPositionShelter.GetY() - (m_fHeightShelter/2)- (0.05/2), 0.0),
      angleWall,
      false,
      CVector3(0.05, m_fWidthShelter+0.05, 0.2));
  AddEntity(*m_pcBoxCenter);


  // Left
  angleWall.FromEulerAngles(CRadians::ZERO, CRadians::ZERO, CRadians::ZERO);
  m_pcBoxLeft = new CBoxEntity("wall_left",
      CVector3(-m_fWidthShelter/2-0.05/4, m_cPositionShelter.GetY()-0.05/2, 0.0),
      angleWall,
      false,
      CVector3(0.05, m_fHeightShelter+0.05, 0.2));
  AddEntity(*m_pcBoxLeft);

  // Right
  m_pcBoxRight = new CBoxEntity("wall_right",
      CVector3(m_fWidthShelter/2+0.05/4, m_cPositionShelter.GetY()-0.05/2, 0.0),
      angleWall,
      false,
      CVector3(0.05, m_fHeightShelter+0.05, 0.2));
  AddEntity(*m_pcBoxRight);
}

/****************************************/
/****************************************/

argos::CColor ChocolateSCALoopFunction::GetFloorColor(const argos::CVector2& c_position_on_plane) {
  CVector2 vCurrentPoint(c_position_on_plane.GetX(), c_position_on_plane.GetY());
  Real d = (m_cCoordBlackSpot - vCurrentPoint).Length();
  if (d <= m_fSpotRadius) {
    return CColor::BLACK;
  }

  d = (m_cCoordWhiteSpot - vCurrentPoint).Length();
  if (d <= m_fSpotRadius) {
    return CColor::BLACK;
  }

  if (IsInShelter(vCurrentPoint)) {
    return CColor::WHITE;
  }

  return CColor::GRAY50;
}

/****************************************/
/****************************************/

bool ChocolateSCALoopFunction::IsInShelter(CVector2& c_position) {
  Real fMaximalXCoord = m_fWidthShelter / 2;
  Real fMaximalYCoord = (m_fHeightShelter / 2) + m_cPositionShelter.GetY();
  if (c_position.GetX() > -fMaximalXCoord && c_position.GetX() < fMaximalXCoord) {
    if (c_position.GetY() > -fMaximalYCoord && c_position.GetY() < fMaximalYCoord) {
      return true;
    }
  }
  return false;
}

/****************************************/
/****************************************/

void ChocolateSCALoopFunction::PostStep() {
  CSpace::TMapPerType& tEpuckMap = GetSpace().GetEntitiesByType("epuck");
  CVector2 cEpuckPosition(0,0);
  for (CSpace::TMapPerType::iterator it = tEpuckMap.begin(); it != tEpuckMap.end(); ++it) {
    CEPuckEntity* pcEpuck = any_cast<CEPuckEntity*>(it->second);
    cEpuckPosition.Set(pcEpuck->GetEmbodiedEntity().GetOriginAnchor().Position.GetX(),
                       pcEpuck->GetEmbodiedEntity().GetOriginAnchor().Position.GetY());

    if (IsInShelter(cEpuckPosition)) {
      m_fObjectiveFunction += 1;
    }
  }
}

/****************************************/
/****************************************/

Real ChocolateSCALoopFunction::GetObjectiveFunction() {
  return m_fObjectiveFunction;
}

/****************************************/
/****************************************/

void ChocolateSCALoopFunction::PositionRobots() {
  Real a;
  Real b;
  Real temp;

  CEPuckEntity* pcEpuck;
  UInt32 unTrials;
  bool bPlaced = false;

  for(UInt32 i = 1; i < m_unNumberRobots + 1; ++i) {
    std::ostringstream id;
    id << "epuck" << i;
    pcEpuck = new CEPuckEntity(id.str().c_str(),
                               "automode",
                               CVector3(0,0,0),
                               CQuaternion().FromEulerAngles(CRadians::ZERO,CRadians::ZERO,CRadians::ZERO));
    AddEntity(*pcEpuck);
    // Choose position at random
    unTrials = 0;
    do {
       ++unTrials;
       a = m_pcRng->Uniform(CRange<Real>(0.0f, 1.0f));
       b = m_pcRng->Uniform(CRange<Real>(0.0f, 1.0f));
       // If b < a, swap them
       if (b < a) {
         temp = a;
         a = b;
         b = temp;
       }
       Real fPosX = b * m_fDistributionRadius * cos(2 * CRadians::PI.GetValue() * (a/b));
       Real fPosY = b * m_fDistributionRadius * sin(2 * CRadians::PI.GetValue() * (a/b));
       bPlaced = MoveEntity((*pcEpuck).GetEmbodiedEntity(),
                            CVector3(fPosX, fPosY, 0),
                            CQuaternion().FromEulerAngles(m_pcRng->Uniform(CRange<CRadians>(CRadians::ZERO,CRadians::TWO_PI)),
                            CRadians::ZERO,CRadians::ZERO),false);
    } while(!bPlaced && unTrials < 100);
    if(!bPlaced) {
       THROW_ARGOSEXCEPTION("Can't place robot #" << i);
    }
  }
}

REGISTER_LOOP_FUNCTIONS(ChocolateSCALoopFunction, "chocolate_sca_loop_functions");
