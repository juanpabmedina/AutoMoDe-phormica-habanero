/**
  * @file AutoMoDeRabBuffer.h
  *
  * @brief Container that keep range-and-bearing messages for a fixed
  * period of time. After the time to live of a message is exceded, the
  * message is discarded. 
  */

#ifndef AUTOMODE_RAB_BUFFER_H
#define AUTOMODE_RAB_BUFFER_H

#include <vector>
#include <algorithm>
#include <argos3/core/utility/logging/argos_log.h>
#include <argos3/core/utility/datatypes/datatypes.h>
#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_range_and_bearing_sensor.h>

namespace argos {
  class AutoMoDeRabBuffer {
    public:
      AutoMoDeRabBuffer();
      ~AutoMoDeRabBuffer();

      void SetTimeLife(UInt32 un_max_time_to_live);
      void Update();
      void AddMessage(CCI_EPuckRangeAndBearingSensor::SReceivedPacket* c_packet, UInt32 un_timestamp);
      void AddMessage(CCI_EPuckRangeAndBearingSensor::SReceivedPacket* c_packet);

      std::vector<CCI_EPuckRangeAndBearingSensor::SReceivedPacket*> GetMessages();

      //void Clear();

      // Debbuging function. Displays elements of buffer.
      void DisplayContent();

      UInt32 GetSize();

    private:
      UInt32 m_unCurrentTime;
      UInt32 m_unMaxTimeToLive;
      std::vector<std::pair<CCI_EPuckRangeAndBearingSensor::SReceivedPacket, UInt32> > m_vecBufferElements;  // Pairs <Message, Timestamp>
  };
}

#endif
