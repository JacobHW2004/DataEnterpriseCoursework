#ifndef TRACK_STATUS_H
#define TRACK_STATUS_H

#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    enum class TrackStatus : uint8_t {
        TENTATIVE = 1,
        CONFIRMED = 2
    };

}

#endif