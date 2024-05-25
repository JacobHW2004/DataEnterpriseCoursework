#ifndef UV_TO_AZ_EL_TRANSFORMATION_H
#define UV_TO_AZ_EL_TRANSFORMATION_H

#include "UVSightline.h"
#include "Fabric/Utils/LCA_Macros.h"
#include "FrameOfReference.h"

#include <chrono>
#include <cstdint>

namespace Topics {

    /**
    * @brief This topic contains a UVSightline along with a time tag that refers to the time at which Navigation
    * Data is required
    */

    struct UVToAzElSightlineTransformation
    {
        /// The UVSightline
        UVSightline uvSightline {};

        /// The frame of reference to transform a Sightline into
        FrameOfReference demandedFrameOfReference {};

        /// The time tag at which Navigation Data is required
        std::chrono::system_clock::time_point timeTag{ std::chrono::system_clock::duration::zero() };

        bool operator==(const UVToAzElSightlineTransformation& other) const {
            return uvSightline == other.uvSightline &&
                demandedFrameOfReference == other.demandedFrameOfReference &&
                timeTag == other.timeTag;
        }

        /**
        * @brief Serialise function required for communications
        */
        template <typename T>
        void Serialise (T& archive) {
            // Convert the timestamp to something we can serialise
            std::uint64_t scheduledTimeSinceEpoch{ static_cast<std::uint64_t>(timeTag.time_since_epoch().count()) };

            archive.Serialise(uvSightline, "uvSightline");
            archive.Serialise(demandedFrameOfReference, "demandedFrameOfReference");
            archive.Serialise(scheduledTimeSinceEpoch, "timeTag");

            // Convert and store the deserialised timestamp in member data
            std::chrono::system_clock::duration const durationSinceLastEpoch{scheduledTimeSinceEpoch};
            std::chrono::system_clock::time_point const timePointSinceLastEpoch{durationSinceLastEpoch};
            timeTag = timePointSinceLastEpoch;
        }

        LCA_TOPIC("UVToAzElSightlineTransformation", 1, 0)
    };

} //namespace Topics

#endif