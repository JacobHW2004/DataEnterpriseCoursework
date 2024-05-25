#ifndef TRACK_TYPE_H
#define TRACK_TYPE_H

#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    enum class TrackType : uint8_t {
        AIR_TRACK_MEASURED_RANGE          = 0,
        AIR_TRACK_ANGLE_ONLY              = 1,
        SURFACE_TRACK_MEASURED_RANGE      = 2,
        SURFACE_TRACK_ANGLE_ONLY          = 3
    };

}

#endif