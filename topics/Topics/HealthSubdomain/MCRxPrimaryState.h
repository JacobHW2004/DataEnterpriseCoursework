#ifndef MCRx_PRIMARY_STATE_H
#define MCRx_PRIMARY_STATE_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics {
    enum MCRxOperatingState : uint8_t
    {
        UNINITIALISED,
        LOW_POWER
    };

    struct MCRxPrimaryState
    {
        MCRxOperatingState MCRx_OPERATING_STATE{};

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(MCRx_OPERATING_STATE, "MCRx_OPERATING_STATE");
        }

        LCA_TOPIC("MCRxPrimaryState", 1, 0);
    };
}

#endif