#ifndef AESA_BIT_CONTROL_H
#define AESA_BIT_CONTROL_H

#include "PBITType.h"

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    struct AESABITControl
    {
        PBITType PBIT_COMMAND{};

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(PBIT_COMMAND, "PBIT_COMMAND");
        }

        LCA_TOPIC("AESABITControl", 1, 0);
    };
}

#endif