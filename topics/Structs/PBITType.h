#ifndef PBIT_TYPE_H
#define PBIT_TYPE_H

#include <cstdint>

namespace Topics {
    enum class PBITType : uint8_t
    {
        UNCOMMANDED,
        FULL_POWER_UP,
        FULL_PBIT,
        FAST_POWER_UP,
        PBIT_INHIBIT_CANCEL
    };
}

#endif