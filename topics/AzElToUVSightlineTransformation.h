#ifndef AZ_EL_TO_UV_SIGHTLINE_TRANSFORMATION_H
#define AZ_EL_TO_UV_SIGHTLINE_TRANSFORMATION_H

#include "Sightline.h"
#include "Fabric/Utils/LCA_Macros.h"

#include <chrono>
#include <cstdint>

namespace Topics {

    /**
    * @brief This topic contains a Sightline in AzEl along with a time tag that refers to the time at which Navigation
    * Data is required. A Sightline in UV will always need to be in Frame 6UV.
    *
    */

    struct AzElToUVSightlineTransformation
    {
        /// The Sightline containing its start frame of reference and AzEl coordinates
        Sightline sightline {};

        /// The time tag at which Navigation Data is required
        std::chrono::system_clock::time_point timeTag{ std::chrono::system_clock::duration::zero() };

        bool operator==(const AzElToUVSightlineTransformation& other) const {
            return sightline == other.sightline &&
                timeTag == other.timeTag;
        }

        /**
        * @brief Serialise function required for communications
        */
        template <typename T>
        void Serialise (T& archive) {
            // Convert the timestamp to something we can serialise
            std::uint64_t scheduledTimeSinceEpoch{ static_cast<std::uint64_t>(timeTag.time_since_epoch().count()) };

            archive.Serialise(sightline, "sightline");
            archive.Serialise(scheduledTimeSinceEpoch, "timeTag");

            // Convert and store the deserialised timestamp in member data
            std::chrono::system_clock::duration const durationSinceLastEpoch{scheduledTimeSinceEpoch};
            std::chrono::system_clock::time_point const timePointSinceLastEpoch{durationSinceLastEpoch};
            timeTag = timePointSinceLastEpoch;
        }

        LCA_TOPIC("AzElToUVSightlineTransformation", 1, 0)
    };

} //namespace Topics

#endif