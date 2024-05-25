#ifndef VOLUME_ELIGIBILITY_REQUEST_RESPONSE
#define VOLUME_ELIGIBILITY_REQUEST_RESPONSE

#include "Eligibility.h"
#include "VolumeEligibilityRequest.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {


struct VolumeEligibilityRequestResponse {

    VolumeEligibilityRequest volumeEligibilityRequest{};
    Eligibility eligibilityResponse{};

    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(volumeEligibilityRequest, "volumeEligibilityRequest");
        archive.Serialise(eligibilityResponse, "eligibilityResponse");
    }

    LCA_TOPIC("VolumeEligibilityRequestResponse", 1, 0)

};

}  // namespace Topics

#endif