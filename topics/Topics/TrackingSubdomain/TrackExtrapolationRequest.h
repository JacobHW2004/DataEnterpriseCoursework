#ifndef TRACK_EXTRAPOLATION_REQUEST_H
#define TRACK_EXTRAPOLATION_REQUEST_H

#include "Fabric/Utils/LCA_Macros.h"

#include "SISecond.h"
#include "LatitudeLongitudeAltitude.h"
#include "Acceleration.h"
#include "Velocity.h"

namespace Topics {
    class TrackExtrapolationRequest {
    public:

        SI::SISecond demanded_time{ 0.0 };

        LatitudeLongitudeAltitude ownship_position{};
        Velocity                  ownship_velocity{ FrameOfReference::FRAME_1 };
        Acceleration              ownship_acceleration{ FrameOfReference::FRAME_1 };

        TrackExtrapolationRequest() = default;

        TrackExtrapolationRequest(double aDemandedTime, const LatitudeLongitudeAltitude& aPosition, const Velocity& aVelocity, const Acceleration& aAcceleration) :
            demanded_time(aDemandedTime),
            ownship_position(aPosition),
            ownship_velocity(aVelocity),
            ownship_acceleration(aAcceleration)
        {}

        template <class T>
        void Serialise(T& archive) {

            /* Temporary variable to allow serialization of SI-unit members */
            double demanded_time_double{ demanded_time() };

            archive.Serialise(demanded_time_double, "demanded_time");
            archive.Serialise(ownship_position,     "ownship_position");
            archive.Serialise(ownship_velocity,     "ownship_velocity");
            archive.Serialise(ownship_acceleration, "ownship_acceleration");

            /* After deserialisation convert back to SIRadians */
            demanded_time = demanded_time_double;

        }

        LCA_TOPIC("TrackExtrapolationRequest", 2, 0);
    };
}

#endif