#ifndef APSC_BIT_COMMAND_H
#define APSC_BIT_COMMAND_H

#include "PBITType.h"

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    struct APSCBITCommand
    {
        PBITType POWER_UP_TYPE{};

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(POWER_UP_TYPE, "POWER_UP_TYPE");
        }

        LCA_TOPIC("APSCBITCommand", 1, 0);
    };
}

#endif