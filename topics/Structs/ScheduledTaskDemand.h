#ifndef SCHEDULEDTASKDEMAND_H
#define SCHEDULEDTASKDEMAND_H

#include "Fabric/Utils/LCA_Macros.h"
#include "Priority.h"

#include <chrono>
#include <cstdint>
namespace Topics {

/**
 * @brief This struct represents the scheduling demand that has been allocated time for scheduling on the resource.
 */
struct ScheduledTaskDemand
{
    /// The task that made the request
    std::int32_t internalTaskID{0};
    /// The scheduled start time of the task job
    std::chrono::system_clock::time_point startTime{};
    /// The amount of time (milliseconds) allocated
    uint64_t allocatedTime_ms{0};
    /// The priority of a scheduled task demand
    Priority priority{Priority::NORMAL};

    /**
    * @brief Serialise function required for communications
    */
    template <class T>
    void Serialise(T& archive) {

        //convert the timestamp to something we can serialise
        uint64_t scheduledTaskDemandTimeSinceEpoch { static_cast<uint64_t>(startTime.time_since_epoch().count()) };

        //serialise
        archive.Serialise(internalTaskID, "internalTaskID");
        archive.Serialise(scheduledTaskDemandTimeSinceEpoch, "scheduledTaskDemandTimeSinceEpoch");
        archive.Serialise(allocatedTime_ms, "allocatedTime_ms");
        archive.Serialise(priority, "priority");

        //deserialise the time into a timestamp
        std::chrono::system_clock::duration const durationSinceLastEpoch(scheduledTaskDemandTimeSinceEpoch);
        std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch); //create a new time point so it can be initialised with the serialised time value
        startTime = timePointSinceLastEpoch;
    }
    LCA_TOPIC("ScheduledTaskDemand", 1, 0)

};

} // namespace Topics

#endif

