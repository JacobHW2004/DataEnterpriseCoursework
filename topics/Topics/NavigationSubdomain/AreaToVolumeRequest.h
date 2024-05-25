#ifndef AREA_TO_VOLUME_REQUEST_H
#define AREA_TO_VOLUME_REQUEST_H

#include "Area.h"
#include "Fabric/Utils/LCA_Macros.h"

#include <chrono>

namespace Topics {

   struct AreaToVolumeRequest
   {
      Area areaToConvert {};
      std::chrono::system_clock::time_point requestedTimePoint{ std::chrono::system_clock::duration::zero() };

      template <class T>
      void Serialise(T& archive) {

         // Convert the timestamp to something we can serialise
         std::uint64_t scheduledTimeSinceEpoch{ static_cast<std::uint64_t>(requestedTimePoint.time_since_epoch().count()) };

         archive.Serialise(areaToConvert, "areaToConvert");
         archive.Serialise(scheduledTimeSinceEpoch, "requestedTimePoint");

         // Convert and store the deserialised timestamp in member data
         std::chrono::system_clock::duration const durationSinceLastEpoch(scheduledTimeSinceEpoch);
         std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch);
         requestedTimePoint = timePointSinceLastEpoch;
      }

      LCA_TOPIC("AreaToVolumeRequest", 1, 0)
   };

}  // namespace Topics

#endif