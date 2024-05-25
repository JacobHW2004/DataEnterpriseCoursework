#ifndef AREA_TO_VOLUME_REQUEST_RESPONSE_H
#define AREA_TO_VOLUME_REQUEST_RESPONSE_H

#include "AreaToVolumeRequest.h"
#include "Volume.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

   struct AreaToVolumeRequestResponse
   {
      AreaToVolumeRequest areaRequest {};
      Volume volumeResponse {};

      template <class T>
      void Serialise(T& archive) {

         archive.Serialise(areaRequest, "areaRequest");
         archive.Serialise(volumeResponse, "volumeResponse");

   }

      LCA_TOPIC("AreaToVolumeRequestResponse", 1, 0)
   };

}  // namespace Topics

#endif