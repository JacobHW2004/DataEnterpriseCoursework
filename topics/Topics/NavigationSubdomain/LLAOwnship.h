#ifndef LLA_OWNSHIP_H
#define LLA_OWNSHIP_H

#include "Fabric/Utils/LCA_Macros.h"
#include "Velocity.h"
#include "Acceleration.h"
#include "LatitudeLongitudeAltitude.h"
#include <chrono>

namespace Topics
{

    struct LLAOwnship
    {

        /**
         * @brief topic used to describe a ownship using LLA positional format
         */
        Acceleration acceleration{};
        Velocity velocity{};
        LatitudeLongitudeAltitude latitudeLongitudeAltitude{};
        std::chrono::system_clock::time_point timeTag{ std::chrono::system_clock::duration::zero() };


        LLAOwnship() = default;

        LLAOwnship(const Acceleration& aAcceleration, const Velocity& aVelocity, const LatitudeLongitudeAltitude& aLatitudeLongitudeAltitude, const std::chrono::system_clock::time_point& aTimeTag) :
            acceleration(aAcceleration),
            velocity(aVelocity), 
            latitudeLongitudeAltitude(aLatitudeLongitudeAltitude),
            timeTag(aTimeTag)
        {}

        template <class T>
        void Serialise(T& archive) 
        {
            // Convert the timestamp to something we can serialise
            uint64_t scheduledTimeSinceEpoch{ static_cast<uint64_t>(timeTag.time_since_epoch().count()) };

            // Serialise/deserialise
            archive.Serialise(scheduledTimeSinceEpoch, "timeTag");
            archive.Serialise(acceleration, "acceleration");
            archive.Serialise(velocity, "velocity");
            archive.Serialise(latitudeLongitudeAltitude, "latitudeLongitudeAltitude");

            // Convert and store the deserialised timestamp in member data
            std::chrono::system_clock::duration const durationSinceLastEpoch(scheduledTimeSinceEpoch);
            std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch);
            timeTag = timePointSinceLastEpoch;
        }

        LCA_TOPIC("LLAOwnship", 1, 0)

    };

}       //End namespace Topics

#endif