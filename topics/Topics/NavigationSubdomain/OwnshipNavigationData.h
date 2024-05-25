#ifndef OWNSHIP_NAVIGATION_DATA_H
#define OWNSHIP_NAVIGATION_DATA_H

#include <chrono>

#include "Attitude.h"
#include "Acceleration.h"
#include "Fabric/Utils/LCA_Macros.h"
#include "LatitudeLongitudeAltitude.h"
#include "Velocity.h"

namespace Topics
{

    struct OwnshipNavigationData
    {
        
        /**
         * @brief topic used to contain all the relevant navigation data about the ownship
         */
              
        Velocity ownshipVelocity{ FrameOfReference::FRAME_1 };
        Acceleration ownshipAcceleration { FrameOfReference::FRAME_4 };
        LatitudeLongitudeAltitude ownshipLLAPosition {};
        Attitude ownshipAttitude {};
        std::chrono::time_point<std::chrono::system_clock> ownshipNavigationDataTimestamp {};

        /**
        * @brief Serialise function required for communications
        */

        template <class T>
        void Serialise(T& archive) 
        {
            archive.Serialise(ownshipVelocity, "ownshipVelocity");
            archive.Serialise(ownshipAcceleration, "ownshipAcceleration");
            archive.Serialise(ownshipLLAPosition, "ownshipLLAPosition");
            archive.Serialise(ownshipAttitude, "ownshipAttitude");

            //convert the timestamp to something we can serialise
            uint64_t timeSinceEpoch { static_cast<uint64_t>(ownshipNavigationDataTimestamp.time_since_epoch().count()) };
            archive.Serialise(timeSinceEpoch, "ownshipNavigationDataTimestamp");
            
            //deserialise the time into a timestamp
            std::chrono::system_clock::duration const durationSinceLastEpoch(timeSinceEpoch);
            std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch); //create a new time point so it can be initialised with the serialised time value
            ownshipNavigationDataTimestamp = timePointSinceLastEpoch;
        }

        LCA_TOPIC("OwnshipNavigationData", 1, 0)

    };

}   //end namespace Topics

#endif