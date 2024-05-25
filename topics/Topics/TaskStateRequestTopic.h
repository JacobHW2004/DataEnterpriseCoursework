#ifndef TASKSPECIFICDATATOPIC_H
#define TASKSPECIFICDATATOPIC_H

#include <string>
#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"
#include "TaskState.h"

namespace Topics {

/**
* @brief This topic class provides the task specific data for the Air Search Normal task.
*
*/
class TaskStateRequestTopic {
public:

    /** The unique Identifier for this internal radar task.
    */
    std::int32_t internalTaskID{0};

    Common::TaskState aTaskState{ Common::TaskState::DEAD };
    /**  The time this topic was created.
    */
    double timeCalculated_s{0};



   /**
   * @brief Serialise function required for communications
   * @todo Bools don't serialise
   */
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(internalTaskID, "internalTaskID");
        archive.Serialise(aTaskState, "aTaskState");
        archive.Serialise(timeCalculated_s, "timeCalculated_s");
       
    }

    LCA_TOPIC("TaskStateRequestTopic", 1, 0)

 
};

}  // namespace Topics

#endif