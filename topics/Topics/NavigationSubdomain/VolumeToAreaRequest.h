#ifndef VOLUME_TO_AREA_REQUEST_H
#define VOLUME_TO_AREA_REQUEST_H

#include "Volume.h"
#include "Fabric/Utils/LCA_Macros.h"

#include <chrono>

namespace Topics {

   struct VolumeToAreaRequest
   {
      Volume volumeToconvert {};
      std::chrono::system_clock::time_point requestedTimePoint{ std::chrono::system_clock::duration::zero() };

      template <class T>
      void Serialise(T& archive) {

         // Convert the timestamp to something we can serialise
         std::uint64_t scheduledTimeSinceEpoch{ static_cast<std::uint64_t>(requestedTimePoint.time_since_epoch().count()) };

         archive.Serialise(volumeToconvert, "volumeToconvert");
         archive.Serialise(scheduledTimeSinceEpoch, "requestedTimePoint");

         // Convert and store the deserialised timestamp in member data
         std::chrono::system_clock::duration const durationSinceLastEpoch(scheduledTimeSinceEpoch);
         std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch);
         requestedTimePoint = timePointSinceLastEpoch;
      }

      LCA_TOPIC("VolumeToAreaRequest", 1, 0)
   };

}  // namespace Topics

#endif