#ifndef TASK_AT_TIME_RESPONSE
#define TASK_AT_TIME_RESPONSE

#include <chrono>
#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics{

    class TaskAtTimeResponse {
        public:
            TaskAtTimeResponse() = default;
        
            std::int32_t internalTaskID { 0 };
            std::chrono::system_clock::time_point returnedTimepoint{ std::chrono::system_clock::duration::zero() };

            /**
            * @brief Serialise/deserialise function required for communications
            */
            template <class T>
            void Serialise(T& archive) {

                archive.Serialise(internalTaskID, "internalTaskID");
                
                // Convert the timestamp to something we can serialise
                uint64_t timeSinceEpoch{ static_cast<uint64_t>(returnedTimepoint.time_since_epoch().count()) };

                // Serialise/deserialise
                archive.Serialise(timeSinceEpoch, "returnedTimepoint");

                // Convert and store the deserialised timestamp in member data
                std::chrono::system_clock::duration const durationSinceLastEpoch(timeSinceEpoch);
                std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch);
                returnedTimepoint = timePointSinceLastEpoch;
            }

        LCA_TOPIC("TaskAtTimeResponse", 1, 0);

    };

}       // namespace Topics

#endif