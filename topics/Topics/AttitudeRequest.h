#ifndef ATTITUDE_REQUEST_H
#define ATTITUDE_REQUEST_H


#include "Fabric/Utils/LCA_Macros.h"
#include <chrono>
#include "TimepointSelection.h"

namespace Topics {
    
    class AttitudeRequest {
        public:
            AttitudeRequest() = default;
        
        std::chrono::system_clock::time_point requestedNavTime{ std::chrono::system_clock::duration::zero() };
        TimepointSelection requestedTimepointSelection{ TimepointSelection::USE_TIMEPOINT };

        /**
        * @brief Serialise/deserialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {

            // Convert the timestamp to something we can serialise
            uint64_t scheduledTimeSinceEpoch{ static_cast<uint64_t>(requestedNavTime.time_since_epoch().count()) };

            // Serialise/deserialise
            archive.Serialise(scheduledTimeSinceEpoch, "requestedNavTime");
            archive.Serialise(requestedTimepointSelection, "requestedTimepointSelection");

            // Convert and store the deserialised timestamp in member data
            std::chrono::system_clock::duration const durationSinceLastEpoch(scheduledTimeSinceEpoch);
            std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch);
            requestedNavTime = timePointSinceLastEpoch;
        }

        LCA_TOPIC("AttitudeRequest", 1, 0);

    };
}

#endif