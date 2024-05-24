#ifndef FRAME_TO_GEO_LLA_REFERENCED_REQUEST_RESPONSE_H
#define FRAME_TO_GEO_LLA_REFERENCED_REQUEST_RESPONSE_H

#include "Volume.h"
#include "GeoLLAReferencedVolume.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    /**
     * @brief topic containing the relevant information for requesting a conversion
     *  from a frame referenced volume into a geo LLA referenced volume
     */

    struct FrameToGeoLLAReferencedRequestResponse
    {
        Volume volumeRequest {};
        GeoLLAReferencedVolume geoLLAReferencedVolumeResponse {};

        template <typename T>
        void Serialise(T& archive)
        {
            archive.Serialise(volumeRequest, "volumeRequest");
            archive.Serialise(geoLLAReferencedVolumeResponse, "geoLLAReferencedVolumeResponse");
        }

        LCA_TOPIC("FrameToGeoLLAReferencedRequestResponse", 1, 0)

    };
    

}

#endif
