#ifndef GEO_LLA_TO_FRAME_REFERENCED_REQUEST_RESPONSE_H
#define GEO_LLA_TO_FRAME_REFERENCED_REQUEST_RESPONSE_H

#include "GeoLLAReferencedVolume.h"
#include "Volume.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    /**
     * @brief topic containing the relevant information for requesting a conversion
     *  from a geo LLA referenced volume into a frame referenced volume
     */


    struct GeoLLAToFrameReferencedRequestResponse
    {
        GeoLLAReferencedVolume geoLLAReferencedVolumeRequest {};
        Volume volumeResponse {};

        template <typename T>
        void Serialise(T& archive)
        {
            archive.Serialise(geoLLAReferencedVolumeRequest, "geoLLAReferencedVolumeRequest");
            archive.Serialise(volumeResponse, "volumeResponse");
        }

        LCA_TOPIC("GeoLLAToFrameReferencedRequestResponse", 1, 0)

    };
    

}

#endif
