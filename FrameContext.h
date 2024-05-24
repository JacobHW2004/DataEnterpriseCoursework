#ifndef FRAME_CONTEXT_H
#define FRAME_CONTEXT_H

#include "Fabric/Utils/LCA_Macros.h"

#include <chrono>
#include <cstdint>

namespace Topics {

    struct FrameContext
    {
       
        /**
         * @brief Topic to hold the context of a frame, it's ID and its start time
         * 
         */        
        std::uint32_t id{ 0 }; 
        std::chrono::time_point<std::chrono::system_clock> startRadarTime {}; 

        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {
            
            archive.Serialise(id, "id");

            //convert the timestamp to something we can serialise
            std::uint64_t timeSinceEpoch { static_cast<std::uint64_t>(startRadarTime.time_since_epoch().count()) };
            archive.Serialise(timeSinceEpoch, "startRadarTime");
            
            //deserialise the time into a timestamp
            std::chrono::system_clock::duration const durationSinceLastEpoch(timeSinceEpoch);
            std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch); //create a new time point so it can be initialised with the serialised time value
            startRadarTime = timePointSinceLastEpoch;

        }  

        LCA_TOPIC("FrameContext", 1, 0)   

    };

}

#endif