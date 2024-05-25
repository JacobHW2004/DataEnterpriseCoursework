#ifndef TIMEPOINT_SELECTION_H
#define TIMEPOINT_SELECTION_H

#include <cstdint>

namespace Topics {

    enum class TimepointSelection : std::uint8_t{
        USE_TIMEPOINT = 0x00,
        USE_LATEST = 0x01
    };

}

#endif