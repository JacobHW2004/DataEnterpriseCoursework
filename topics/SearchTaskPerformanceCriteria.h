#ifndef SEARCH_TASK_PERFORMANCE_CRITERIA_H
#define SEARCH_TASK_PERFORMANCE_CRITERIA_H

#include <string>
#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"


namespace Topics {

/**
* @brief Topic provides a report of search task performance metrics.
*/
struct SearchTaskPerformanceCriteria {

    
    std::int32_t internalTaskID{ 0 };
    std::uint32_t priority{ 0 };
    double minimumRequiredQuality{ 0.0 };
    double desiredQuality{ 0.0 };

    /**
    * @brief Serialise function required for communications
    */
    template <class T>
    void Serialise(T& archive) {

        archive.Serialise(internalTaskID, "internalTaskID");
        archive.Serialise(priority, "priority");
        archive.Serialise(minimumRequiredQuality, "minimumRequiredQuality");
        archive.Serialise(desiredQuality, "desiredQuality");
    }

    LCA_TOPIC("SearchTaskPerformanceCriteria", 1, 0)
 
};

}  // namespace Topics

#endif
