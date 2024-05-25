#ifndef TRACK_REVISIT_REQUEST_RESPONSE
#define TRACK_REVISIT_REQUEST_RESPONSE

#include "Fabric/Utils/LCA_Macros.h"
#include "TrackRevisitResponse.h"
#include <cstdint>

namespace Topics {

    struct TrackRevisitRequestResponse {

        ///@deprecated This topic is now deprecated, please use trackingJobRequestResponse.h 

        std::uint32_t trackIdRequest{ 0U };
        TrackRevisitResponse trackRevisitResponse{};

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(trackIdRequest, "trackIdRequest");
            archive.Serialise(trackRevisitResponse, "trackRevisitResponse");
        }

        LCA_TOPIC("TrackRevisitRequestResponse", 1, 0)

    };

}  // namespace Topics

#endif