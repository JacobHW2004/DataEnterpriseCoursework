#ifndef VOLUME_COMPLETION_STATUS_H
#define VOLUME_COMPLETION_STATUS_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

/** @brief This topic class provides the progress of the scan through a volume. */
class VolumeCompletionStatus {
public:

    /** @brief The task the volume relates to. */
    std::int32_t internalTaskID{0};

    /** @brief The progress of the scan through the volume. */
    std::uint32_t percentCompleted{0};
    
    /** @brief Serialise function required for communications. */
    template <class T>
    void Serialise(T& archive) {

        archive.Serialise(internalTaskID, "internalTaskID");
        archive.Serialise(percentCompleted, "percentCompleted");
    }

    LCA_TOPIC("VolumeCompletionStatus", 1, 0)

};

}  // namespace Topics

#endif