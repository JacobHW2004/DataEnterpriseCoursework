#ifndef RADAR_PBIT_STATUS_H
#define RADAR_PBIT_STATUS_H

#include "PBITType.h"

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {
    struct RadarPBITStatus
    {
        PBITType RDRS_F_PBIT_TYPE_REQUEST_RB{};
        PBITType RDRS_F_PBIT_TYPE_REQUEST_STS{};

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(RDRS_F_PBIT_TYPE_REQUEST_RB, "RDRS_F_PBIT_TYPE_REQUEST_RB");
            archive.Serialise(RDRS_F_PBIT_TYPE_REQUEST_STS, "RDRS_F_PBIT_TYPE_REQUEST_STS");
        }

        LCA_TOPIC("RadarPBITStatus", 1, 0);
    };
}

#endif