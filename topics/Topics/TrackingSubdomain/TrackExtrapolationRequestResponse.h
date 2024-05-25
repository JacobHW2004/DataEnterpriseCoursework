#ifndef TRACK_EXTRAPOLATION_REQUEST_RESPONSE
#define TRACK_EXTRAPOLATION_REQUEST_RESPONSE

#include "TrackExtrapolationRequest.h"
#include "TrackExtrapolationResponse.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    class TrackExtrapolationRequestResponse {
    public:

        TrackExtrapolationRequest extrapolationRequest{};
        TrackExtrapolationResponse extrapolationResponse{};

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(extrapolationRequest, "extrapolationRequest");
            archive.Serialise(extrapolationResponse, "extrapolationResponse");
        }

        LCA_TOPIC("TrackExtrapolationRequestResponse", 1, 0)

    };

} 

#endif