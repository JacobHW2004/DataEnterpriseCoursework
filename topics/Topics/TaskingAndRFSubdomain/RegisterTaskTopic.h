#ifndef REGISTER_TASK_TOPIC_H
#define REGISTER_TASK_TOPIC_H

#include <string>
#include <cstdint>
#include "RadarTaskType.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

/**
* @brief This topic class provides the status of the new task allocation   
*
*/
class RegisterTaskTopic {
public:

    /** The unique Identifier for this internal radar task.
    */
    std::int32_t internalTaskID;

    /** The type of task to request.
    */
    Common::RadarTaskCategoryType taskType{ Common::RadarTaskCategoryType::INVALID_CATEGORY};

    RegisterTaskTopic() = default;
    /**
    * @brief Topic constructor with parameters
    */
    RegisterTaskTopic(int aInternalTaskID, Common::RadarTaskCategoryType aTaskType) :
      internalTaskID(aInternalTaskID),
      taskType(aTaskType){}
      
    /**
    * @brief Serialise function required for communications
    */
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(internalTaskID, "internalTaskID");
        archive.Serialise(taskType, "taskType");
    }

    LCA_TOPIC("RegisterTaskTopic", 1, 0);
 
};

}  // namespace Topics

#endif