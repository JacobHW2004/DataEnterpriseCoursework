#ifndef TASKMAPPINGREQUESTRESPONSE_H
#define TASKMAPPINGREQUESTRESPONSE_H

#include <string>
#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"
#include "TaskMapping.h"
#include "TaskMappingStatus.h"

namespace Topics {

/**
* @brief This topic contains the request and response associated with a request to map a Radar Task type to an available internal task
*
*/
class TaskMappingRequestResponse {
public:
     
    /** The data associated with the mapping request
    */
    Topics::TaskMapping taskMappingRequest;

    /** The response containing the result of the mapping request
    */
    Topics::TaskMappingStatus taskMappingResponse;

   /**
   * @brief Serialise function required for communications
   */
    template <class T>
    void Serialise(T& archive) {
       
        archive.Serialise(taskMappingRequest, "taskMappingRequest");
        archive.Serialise(taskMappingResponse, "taskMappingResponse");
      
    }

    LCA_TOPIC("TaskMappingRequestResponse", 1, 0)
};

}  // namespace Topics

#endif