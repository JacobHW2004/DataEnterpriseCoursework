#ifndef VOLUME_CONDITIONING_REQUEST_RESPONSE_H
#define VOLUME_CONDITIONING_REQUEST_RESPONSE_H

#include "Fabric/Utils/LCA_Macros.h"
#include "DemandedVolumeTopic.h"
#include "ConditionedVolumeTopic.h"

#include <string>

namespace Topics {

struct VolumeConditioningRequestResponse {

    DemandedVolumeTopic volumeConditioningRequest{};
    ConditionedVolumeTopic volumeConditioningResponse{};

    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(volumeConditioningRequest, "volumeConditioningRequest");
        archive.Serialise(volumeConditioningResponse, "volumeConditioningResponse");
    }

    LCA_TOPIC("VolumeConditioningRequestResponse", 1, 0)
 
};

}  // namespace Topics

#endif