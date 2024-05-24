#ifndef FIELD_OF_VIEW_SCAN_LIMITS
#define FIELD_OF_VIEW_SCAN_LIMITS

#include <cstdint>

namespace Topics {

enum class FieldOfViewScanLimits : std::uint8_t
{
    LIMITED,
    NON_LIMITED,
    OUTSIDE_FIELD_OF_REGARD
};  

} // namespace Topics

#endif