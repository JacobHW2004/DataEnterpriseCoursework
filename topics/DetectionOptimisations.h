#ifndef DETECTION_OPTIMISATIONS_H
#define DETECTION_OPTIMISATIONS_H

#include "Fabric/Utils/LCA_Macros.h"
#include "SIMeter.h"
#include <cstdint>

namespace Topics {

    enum class TargetSize : std::uint8_t
    {
        NO_OPTIMISATION,
        VERY_SMALL,
        SMALL,
        MEDIUM,
        LARGE
    };

    enum class TargetApproach : std::uint8_t
    {
        NO_OPTIMISATION,
        OPENING,
        CLOSING
    };

    enum class WaveformSelection : std::uint8_t
    {
        NO_OPTIMISATION,
        TARGET_OF_INTEREST,
        QUICK_OPTIMISATION
    };
    
    struct DetectionOptimisations
    {
        std::int32_t internalTaskId{ 0 };
        SI::SIMeter rangeUpper{ 0.0 };
        SI::SIMeter rangeLower{ 0.0 };
        TargetApproach targetApproach{ TargetApproach::NO_OPTIMISATION };
        TargetSize targetSize{ TargetSize::NO_OPTIMISATION };
        WaveformSelection waveformSelection{ WaveformSelection::NO_OPTIMISATION };
    
        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {

            double rangeUpper_double{ rangeUpper() };
            double rangeLower_double{ rangeLower() };

            archive.Serialise(internalTaskId, "internalTaskId");
            archive.Serialise(rangeUpper_double, "rangeUpper");
            archive.Serialise(rangeLower_double, "rangeLower");
            archive.Serialise(targetApproach, "targetApproach");
            archive.Serialise(targetSize, "targetSize");
            archive.Serialise(waveformSelection, "waveformSelection");

            rangeUpper = rangeUpper_double;
            rangeLower = rangeLower_double;
        }
        LCA_TOPIC("DetectionOptimisations", 1, 0)
    };

} // namespace Topics

#endif

