#ifndef FILTER_TYPE_H
#define FILTER_TYPE_H

#include <cstdint>

namespace Topics {

    enum class FilterType : std::uint8_t
    {
        GAUSSIAN,
        CHIRP
    };

} //end namespace Topics

#endif