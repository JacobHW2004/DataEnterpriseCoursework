#ifndef TRACKER_RESET_H
#define TRACKER_RESET_H
#include <cstdint>

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics{
namespace MVP_Tracking{

// TrackerReset is an empty topic that operates as a signal - on receipt, the Tracker will go through a reset process.
// The internal field message_diagnostic_id has no effect on the operation of the Tracker, and is included
// for diagnostic purposes.

class TrackerReset {
public:
    std::uint32_t message_diagnostic_id {0};

    TrackerReset() = default;
    TrackerReset(std::uint32_t diagnostic_id) : message_diagnostic_id(diagnostic_id) {}

    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(message_diagnostic_id, "message_diagnostic_id");
    }
    
    LCA_TOPIC("TrackerReset", 1,0);
};

}
}
#endif