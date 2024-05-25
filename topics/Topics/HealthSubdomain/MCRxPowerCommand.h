#ifndef MCRX_POWER_COMMAND_H
#define MCRX_POWER_COMMAND_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics
{
    enum class RADAR_POWER_STATUS : std::uint8_t
    {
        LIMITED_POWER = 0x0U,//WoW is True and/or LoadShed is True
        FULL_POWER = 0x1U//Normal Operation (in Air)
    };

    struct MCRxPowerCommand
    {
        RADAR_POWER_STATUS mcrxPowerCommand{};

        template <class T>
        void Serialise(T& archive) 
        {
            archive.Serialise(mcrxPowerCommand, "mcrxPowerCommand");
        }

        LCA_TOPIC("MCRxPowerCommand", 1, 0);
    };
}

#endif