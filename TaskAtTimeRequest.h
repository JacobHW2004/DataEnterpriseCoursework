#ifndef TASK_AT_TIME_REQUEST
#define TASK_AT_TIME_REQUEST

#include <chrono>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics{

    class TaskAtTimeRequest {
        public:
            TaskAtTimeRequest() = default;
        
            std::chrono::system_clock::time_point requestedTime{ std::chrono::system_clock::duration::zero() };

            /**
            * @brief Serialise/deserialise function required for communications
            */
            template <class T>
            void Serialise(T& archive) {

                // Convert the timestamp to something we can serialise
                uint64_t timeSinceEpoch{ static_cast<uint64_t>(requestedTime.time_since_epoch().count()) };

                // Serialise/deserialise
                archive.Serialise(timeSinceEpoch, "requestedTime");

                // Convert and store the deserialised timestamp in member data
                std::chrono::system_clock::duration const durationSinceLastEpoch(timeSinceEpoch);
                std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch);
                requestedTime = timePointSinceLastEpoch;
            }

        LCA_TOPIC("TaskAtTimeRequest", 1, 0);

    };

}       // namespace Topics

#endif