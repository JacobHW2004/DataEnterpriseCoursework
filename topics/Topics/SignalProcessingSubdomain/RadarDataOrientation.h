#ifndef RADAR_DATA_ORIENTATION_ENUM
#define RADAR_DATA_ORIENTATION_ENUM

#include <cstdint>

namespace Topics {
    enum class RadarDataOrientation : std::uint8_t
    {
        RANGE_GATE_CONTIGUOUS, // Adjacent elements are in different Range Gates. Time-ordered
        PRI_CONTIGUOUS         // Adjacent elements are in different PRIs. Not time-ordered.
    };

}

#endif /* RADAR_DATA_ORIENTATION_ENUM */
