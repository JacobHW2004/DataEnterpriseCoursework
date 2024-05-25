#ifndef TRACK_TASK_PERFORMANCE_CRITERIA_H
#define TRACK_TASK_PERFORMANCE_CRITERIA_H

#include <string>
#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"
#include "TrackQualityRadius.h"

namespace Topics {

/**
* @brief Topic stores performance criteria for a given track task.
*
*/
struct TrackTaskPerformanceCriteria {

    
    std::int32_t trackID{ 0 };
    std::uint32_t priority{ 0 };
    Topics::TrackQualityRadius minimumRequiredQuality{};
    Topics::TrackQualityRadius desiredQuality{};

    /**
    * @brief Serialise function required for communications
    */
    template <class T>
    void Serialise(T& archive) {

        archive.Serialise(trackID, "trackID");
        archive.Serialise(priority, "priority");
        archive.Serialise(minimumRequiredQuality, "minimumRequiredQuality");
        archive.Serialise(desiredQuality, "desiredQuality");
    }

    LCA_TOPIC("TrackTaskPerformanceCriteria", 1, 0)
 
};

}  // namespace Topics

#endif