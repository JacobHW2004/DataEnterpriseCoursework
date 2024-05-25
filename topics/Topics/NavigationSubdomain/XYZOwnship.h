#ifndef XYZ_OWNSHIP_H
#define XYZ_OWNSHIP_H

#include "Fabric/Utils/LCA_Macros.h"
#include "Velocity.h"
#include "Acceleration.h"
#include "Position.h"
#include <chrono>

namespace Topics
{

    struct XYZOwnship
    {

        /**
         * @brief topic used to describe a ownship using XYZ positional format
         */
        Acceleration acceleration{};
        Velocity velocity{};
        Position position{};
        std::chrono::system_clock::time_point timeTag{ std::chrono::system_clock::duration::zero() };


        XYZOwnship() = default;

        XYZOwnship(const Acceleration& aAcceleration, const Velocity& aVelocity, const Position& aPoint, const std::chrono::system_clock::time_point& aTimeTag) :
            acceleration(aAcceleration),
            velocity(aVelocity), 
            position(aPoint),
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
            archive.Serialise(position, "position");

            // Convert and store the deserialised timestamp in member data
            std::chrono::system_clock::duration const durationSinceLastEpoch(scheduledTimeSinceEpoch);
            std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch);
            timeTag = timePointSinceLastEpoch;
        }

        LCA_TOPIC("XYZOwnship", 1, 0)

    };

}       //End namespace Topics

#endif