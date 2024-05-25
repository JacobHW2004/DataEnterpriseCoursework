#ifndef VOLUME_TO_AREA_REQUEST_RESPONSE_H
#define VOLUME_TO_AREA_REQUEST_RESPONSE_H

#include "VolumeToAreaRequest.h"
#include "Area.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

   struct VolumeToAreaRequestResponse
   {
      VolumeToAreaRequest volumeRequest {};
      Area areaResponse {};

      template <class T>
      void Serialise(T& archive) {

         archive.Serialise(volumeRequest, "volumeRequest");
         archive.Serialise(areaResponse, "areaResponse");

      }

      LCA_TOPIC("VolumeToAreaRequestResponse", 1, 0)
   };

}  // namespace Topics

#endif