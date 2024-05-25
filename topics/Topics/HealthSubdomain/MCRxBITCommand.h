#ifndef MCRx_BIT_COMMAND_H
#define MCRx_BIT_COMMAND_H

#include "PBITType.h"

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    struct MCRxBITCommand
    {
        PBITType PBIT_COMMAND {};

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(PBIT_COMMAND , "PBIT_COMMAND ");
        }

        LCA_TOPIC("MCRxBITCommand", 1, 0);
    };
}

#endif