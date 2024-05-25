#ifndef AAU_PRIMARY_STATE_H
#define AAU_PRIMARY_STATE_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics {
    enum AAUOperatingState : uint8_t
    {
        AAU_UNINITIALISED,
        AAU_INITIALISING
    };

    struct AAUPrimaryState
    {
        AAUOperatingState AAU_OPERATING_STATE{};

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(AAU_OPERATING_STATE, "AAU_OPERATING_STATE");
        }

        LCA_TOPIC("AAUPrimaryState", 1, 0);
    };
}

#endif