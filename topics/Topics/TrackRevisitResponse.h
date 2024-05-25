#ifndef TRACK_REVISIT_RESPONSE
#define TRACK_REVISIT_RESPONSE

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    struct TrackRevisitResponse {

        ///@deprecated This topic is now deprecated, please use trackingJobRequestResponse.h 

        bool trackIdExists{ false };
        bool trackIsInIfov{ false };

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(trackIdExists, "trackIdExists");
            archive.Serialise(trackIsInIfov, "trackIsInIfov");
        }

        LCA_TOPIC("TrackRevisitResponse", 1, 0)

    };

}  // namespace Topics

#endif