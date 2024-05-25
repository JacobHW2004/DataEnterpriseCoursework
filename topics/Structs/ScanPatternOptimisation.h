#ifndef SCAN_PATTERN_OPTIMISATION_H
#define SCAN_PATTERN_OPTIMISATION_H

#include <cstdint>

namespace Topics {


    enum class ScanPatternOptimisation : std::uint8_t
    {
        NO_OPTIMISATION,
        CENTRE_OPTIMISATION,
        QUICK_OPTIMISATION
    };

} // namespace Topics

#endif

