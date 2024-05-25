#ifndef RADAR_POWER_H
#define RADAR_POWER_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics
{
    enum class RDRS_F_POWER_RESTRICTION : std::uint8_t
    {
        UNRESTRICTED = 0x0U,
        LOADSHED_RESTRICTED_PWR = 0x1U,
        ALERT_MODE_RESTRICTED_PWR = 0x2U,
        GROUND_OPERATION_RESTRICTED_PWR = 0x3U
    };

    /**
    * @brief Topic representation of RDRS-F-POWER-RESTRICTION
    */
    struct RadarPower
    {
        RDRS_F_POWER_RESTRICTION powerRestriction{};

        template <class T>
        void Serialise(T& archive)
        {
            archive.Serialise(powerRestriction, "powerRestriction");
        }

        LCA_TOPIC("RadarPower", 1, 0);
    };
}

#endif