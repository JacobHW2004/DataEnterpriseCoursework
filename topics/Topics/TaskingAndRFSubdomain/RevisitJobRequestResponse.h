#ifndef REVISIT_JOB_REQUEST_RESPONSE_H
#define REVISIT_JOB_REQUEST_RESPONSE_H

#include "Fabric/Utils/LCA_Macros.h"
#include "RevisitJobRequest.h"
#include "RevisitJobResponse.h"

namespace Topics {

    struct RevisitJobRequestResponse 
    {

        RevisitJobRequest revisitJobRequest {};
        RevisitJobResponse revisitJobResponse {};

        template <typename T>
        void Serialise(T& archive) {
            archive.Serialise(revisitJobRequest, "revisitJobRequest");
            archive.Serialise(revisitJobResponse, "revisitJobResponse");
        }

        LCA_TOPIC("RevisitJobRequestResponse", 1, 0)

    };

}

#endif