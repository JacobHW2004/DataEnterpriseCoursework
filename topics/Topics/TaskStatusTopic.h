#ifndef TASKSTATUSTOPIC_H
#define TASKSTATUSTOPIC_H

#include <string>
#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"
#include "TaskState.h"

namespace Topics {

/**
* @brief This topic class provides the creation success status based on the task specific parameters 
*
*
*/
class TaskStatusTopic {
public:   
    
    /** The unique Identifier for this internal radar task.
    */
    std::int32_t internalTaskID{0};

    /** The state of the task
    */
    Common::TaskState taskState{ Common::TaskState::DEAD };

    TaskStatusTopic() {};

   /**
   * @brief Topic Constructor with parameters
   */
    TaskStatusTopic(int aInternalTaskID, Common::TaskState aTaskState) :
        internalTaskID(aInternalTaskID),
        taskState(aTaskState){};

   /**
   * @brief Serialise function required for communications
   * @todo Bools don't serialise
   */
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(internalTaskID, "internalTaskID");
        archive.Serialise(taskState, "taskState");
    }

    LCA_TOPIC("TaskStatusTopic", 1, 0)

 
};

}  // namespace Topics

#endif