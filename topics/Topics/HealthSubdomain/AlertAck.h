#ifndef ALERT_ACK_H
#define ALERT_ACK_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics
{
    enum class RDRS_F_RADAR_ALERT_ACK : std::uint8_t
    {
        NO_ALERT = 0x0U,
        ALERT = 0x1U
    };

    /**
    * @brief Topic representation of RDRS-F-RADAR-ALERT-ACK
    */
    struct AlertAck
    {
        RDRS_F_RADAR_ALERT_ACK alertAck{};

        template <class T>
        void Serialise(T& archive)
        {
            archive.Serialise(alertAck, "alertAck");
        }

        LCA_TOPIC("AlertAck", 1, 0);
    };
}

#endif