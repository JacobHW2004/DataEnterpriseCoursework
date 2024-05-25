#ifndef VOLUME_ELIGIBILITY_REQUEST_H
#define VOLUME_ELIGIBILITY_REQUEST_H

#include "Fabric/Utils/LCA_Macros.h"
#include "DemandedVolumeTopic.h"
#include "SIRadian.h"

namespace Topics {

    struct VolumeEligibilityRequest
    {
        DemandedVolumeTopic demandedVolume{};
        SI::SIRadian eligibilityThreshold{0.0};

        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {
            double elThreshold {eligibilityThreshold()};

            archive.Serialise(demandedVolume, "demandedVolume");
            archive.Serialise(elThreshold, "eligibilityThreshold");

            eligibilityThreshold = elThreshold;
        }

        LCA_TOPIC("VolumeEligibilityRequest", 1, 0)
    };

}  // namespace Topics

#endif