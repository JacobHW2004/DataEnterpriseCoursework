#ifndef PRIORITY_H
#define PRIORITY_H

#include <cstdint>

namespace Topics {


enum class Priority : std::uint8_t
{

   REALTIME,
   HIGH,
   ABOVE_NORMAL,
   NORMAL,
   BELOW_NORMAL,
   LOW
};

} // namespace Topics

#endif

