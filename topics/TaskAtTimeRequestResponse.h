#ifndef TASK_AT_TIME_REQUEST_RESPONSE
#define TASK_AT_TIME_REQUEST_RESPONSE

#include "TaskAtTimeRequest.h"
#include "TaskAtTimeResponse.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    struct TaskAtTimeRequestResponse {

        TaskAtTimeRequest taskAtTimeRequest;
        TaskAtTimeResponse taskAtTimeResponse;

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(taskAtTimeRequest, "taskAtTimeRequest");
            archive.Serialise(taskAtTimeResponse, "taskAtTimeResponse");
        }

    LCA_TOPIC("TaskAtTimeRequestResponse", 1, 0)

    };

}   // namespace Topics

#endif
