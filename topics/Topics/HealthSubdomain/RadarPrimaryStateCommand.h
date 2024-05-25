#ifndef RADAR_PRIMARY_STATE_COMMAND_H
#define RADAR_PRIMARY_STATE_COMMAND_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics
{
    enum class RDRC_F_PRIM_STATE_CMD_ENUM : uint8_t
    {
        AUTOMATIC = 0x00U,
        STANDBY = 0x03U,
        MD_SWITCH = 0x05U,
        SHUTDOWN = 0x09U,
        RE_START = 0x0CU
    };

    /**
    * @brief Topic representation of RDRC-F-PRIM-STATE-CMD
    */
    struct RadarPrimaryStateCommand
    {
        RDRC_F_PRIM_STATE_CMD_ENUM RDRC_F_PRIM_STATE_CMD{};

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(RDRC_F_PRIM_STATE_CMD, "RDRC_F_PRIM_STATE_CMD");
        }

        LCA_TOPIC("RadarPrimaryStateCommand", 1, 0);
    };
}

#endif