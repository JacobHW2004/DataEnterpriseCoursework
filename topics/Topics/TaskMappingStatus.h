#ifndef TASKMAPPINGSTATUS_H
#define TASKMAPPINGSTATUS_H

#include <string>
#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

/**
* @brief This topic class provides the status of the new task allocation   
*
*/
class TaskMappingStatus {
public:
     
    /** The unique Identifier for this internal radar task.
    */
    std::int32_t internalTaskID{0};
    
    /** The allocation success status
    */    
    bool success{false};
    
    /**  The time this topic was created.
    */
    double timeCalculated_s{0.0};


   /**
   * @brief Serialise function required for communications
   */
    template <class T>
    void Serialise(T& archive) {
       
        archive.Serialise(internalTaskID, "internalTaskID");
        archive.Serialise(success, "success");
        archive.Serialise(timeCalculated_s, "timeCalculated_s");
      
    }

    LCA_TOPIC("TaskMappingStatus", 1, 0)

 
};

}  // namespace Topics

#endif