#ifndef REVISIT_JOB_RESPONSE_H
#define REVISIT_JOB_RESPONSE_H

#include "Fabric/Utils/LCA_Macros.h"

#include <cstdint>

namespace Topics {

    struct RevisitJobResponse {

        std::int32_t internalTaskId{ 0 };
        bool isInFoV{ false };
        bool isMapped {false};

        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(internalTaskId, "internalTaskId");
            archive.Serialise(isInFoV, "isInFoV");
            archive.Serialise(isMapped, "isMapped");
        }
        LCA_TOPIC("RevisitJobResponse", 1, 0)

    };

}  // namespace Topics

#endif