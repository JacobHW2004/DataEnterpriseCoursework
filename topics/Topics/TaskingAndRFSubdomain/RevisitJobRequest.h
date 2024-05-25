#ifndef REVISIT_JOB_REQUEST_H
#define REVISIT_JOB_REQUEST_H

#include "Fabric/Utils/LCA_Macros.h"
#include "Priority.h"

#include <cstdint>

namespace Topics {

    struct RevisitJobRequest {

        std::int32_t trackId{ 0 };
        Priority priority{ Priority::NORMAL };

        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(trackId, "trackId");
            archive.Serialise(priority, "priority");
        }

        LCA_TOPIC("RevisitJobRequest", 1, 0)

    };

}  // namespace Topics

#endif