#ifndef ATTITUDE_REQUEST_RESPONSE_H
#define ATTITUDE_REQUEST_RESPONSE_H

#include "AttitudeRequest.h"
#include "NavigationSubdomain/Attitude.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {


struct AttitudeRequestResponse {

    AttitudeRequest attitudeRequest{};
    Attitude attitudeResponse{};

    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(attitudeRequest, "attitudeRequest");
        archive.Serialise(attitudeResponse, "attitudeResponse");
    }

    LCA_TOPIC("AttitudeRequestResponse", 1, 0)
 
};

}  // namespace Topics

#endif