#ifndef OUTCOME_H
#define OUTCOME_H

#include <cstdint>

namespace Topics {

    enum class Outcome : std::uint8_t
    {
        FAIL,
        SUCCESS
    };
    
} // namespace Topics

#endif // #ifndef OUTCOME_H
