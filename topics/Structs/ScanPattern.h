#ifndef SCAN_PATTERN_H
#define SCAN_PATTERN_H

#include <cstdint>

namespace Topics {


    enum class ScanPattern : std::uint8_t
    {
        HORIZONTAL_RASTER,
        VERTICAL_RASTER
    };

} // namespace Topics

#endif

