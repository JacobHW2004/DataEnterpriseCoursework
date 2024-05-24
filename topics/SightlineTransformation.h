#ifndef SIGHTLINE_TRANSFORMATION_H
#define SIGHTLINE_TRANSFORMATION_H

#include "Sightline.h"
#include "FrameOfReference.h"
#include "Fabric/Utils/LCA_Macros.h"

#include <chrono>
#include <cstdint>

namespace Topics {

    /**
    * @brief This topic contains a Sightline along with a demanded frame of reference to transform the Sightline into
    *
    */

    struct SightlineTransformation
    {
        /// The Sightline containing its start frame of reference and coordinates
        Sightline sightline {};

        /// The frame of reference to transform a Sightline into
        FrameOfReference demandedFrameOfReference {};

        /// The time point at which the navigation data used to make the transformation
        std::chrono::system_clock::time_point requestedTimePoint{ std::chrono::system_clock::duration::zero() };

        bool operator==(const SightlineTransformation& other) const {
            return sightline == other.sightline && 
                    demandedFrameOfReference == other.demandedFrameOfReference;
        }

        /**
        * @brief Serialise function required for communications
        */
        template <typename T>
        void Serialise (T& archive) {

            // Convert the timestamp to something we can serialise
            std::uint64_t scheduledTimeSinceEpoch{ static_cast<std::uint64_t>(requestedTimePoint.time_since_epoch().count()) };

            archive.Serialise(sightline, "sightline");
            archive.Serialise(demandedFrameOfReference, "demandedFrameOfReference");
            archive.Serialise(scheduledTimeSinceEpoch, "requestedTimePoint");

            // Convert and store the deserialised timestamp in member data
            std::chrono::system_clock::duration const durationSinceLastEpoch(scheduledTimeSinceEpoch);
            std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch);
            requestedTimePoint = timePointSinceLastEpoch;

        }

        LCA_TOPIC("SightlineTransformation", 1, 1)
    };

} //namespace Topics

#endif
