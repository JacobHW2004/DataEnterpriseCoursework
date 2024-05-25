#ifndef RADAR_PBIT_CONTROL_H
#define RADAR_PBIT_CONTROL_H

#include "PBITType.h"

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {
    struct RadarPBITControl
    {
        PBITType PBIT_TYPE_REQUEST{};

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(PBIT_TYPE_REQUEST, "PBIT_TYPE_REQUEST");
        }

        LCA_TOPIC("RadarPBITControl", 1, 0);
    };
}

#endif