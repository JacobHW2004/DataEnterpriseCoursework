#ifndef LLA_OWNSHIP_REQUEST_RESPONSE_H
#define LLA_OWNSHIP_REQUEST_RESPONSE_H

#include "LLAOwnship.h"
#include "OwnshipRequest.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {


struct LLAOwnshipRequestResponse {

    OwnshipRequest ownshipRequest{};
    LLAOwnship ownshipResponse{};

    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(ownshipRequest, "ownshipRequest");
        archive.Serialise(ownshipResponse, "ownshipResponse");
    }

    LCA_TOPIC("LLAOwnshipRequestResponse", 1, 0)
 
};

}  // namespace Topics

#endif
