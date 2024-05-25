#ifndef RADAR_PRIMARY_STATE_STATUS_H
#define RADAR_PRIMARY_STATE_STATUS_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics
{
    enum class RDRS_F_PRIMARY_STATE_ENUM : uint8_t
    {
        INVAID = 0x00U,
        WARM_UP = 0x03U,
        OPERATE = 0x05U,
        STANDBY = 0x09U,
        ALERT_STANDBY = 0x0CU,
        FORCED_STANDBY = 0x0FU,
        MD_SWITCH = 0x11U,
        SHUTDOWN_IN_PROGRESS = 0x14U,
        SHUTDOWN_WAITING_FOR_REPO = 0x17U,
        SHUTDOWN_UNSUCCESSFUL = 0x18U,
        SHUTDOWN_SUCCESSFUL = 0x1BU,
        IBIT_IN_PROGRESS = 0x1DU,
        IBIT_CANCELLING = 0x1EU
    };

    /**
    * @brief Topic representation of RDRS-F-PRIMARY-STATE
    */
    struct RadarPrimaryStateStatus
    {
        RDRS_F_PRIMARY_STATE_ENUM RDRS_F_PRIMARY_STATE{};

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(RDRS_F_PRIMARY_STATE, "RDRS_F_PRIMARY_STATE");
        }

        LCA_TOPIC("RadarPrimaryStateStatus", 1, 0);
    };
}

#endif