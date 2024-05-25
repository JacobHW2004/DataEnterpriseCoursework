#ifndef ECEF_OWNSHIP_REQUEST_RESPONSE_H
#define ECEF_OWNSHIP_REQUEST_RESPONSE_H

#include "XYZOwnship.h"
#include "OwnshipRequest.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {


struct ECEFOwnshipRequestResponse {

    OwnshipRequest ownshipRequest{};
    XYZOwnship ownshipResponse{};

    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(ownshipRequest, "ownshipRequest");
        archive.Serialise(ownshipResponse, "ownshipResponse");
    }

    LCA_TOPIC("ECEFOwnshipRequestResponse", 1, 0)
 
};

}  // namespace Topics

#endif