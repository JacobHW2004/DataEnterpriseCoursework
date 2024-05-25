#ifndef VOLUME_SEARCH_JOB_H
#define VOLUME_SEARCH_JOB_H

#include "Fabric/Utils/LCA_Macros.h"
#include "Volume.h"
#include "ScanPattern.h"
#include "ScanPatternOptimisation.h"
#include "Priority.h"

#include <cstdint>

namespace Topics {

    struct VolumeSearchJob {

        std::int32_t internalTaskID{ 0 };
        Volume aVolume{};
        ScanPattern scanPattern{ ScanPattern::HORIZONTAL_RASTER };
        ScanPatternOptimisation scanPatternOptimisation{ ScanPatternOptimisation::NO_OPTIMISATION };
        Priority priority{ Priority::NORMAL };
        bool concurrentJob { true };

        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(internalTaskID, "internalTaskID");
            archive.Serialise(aVolume, "aVolume");
            archive.Serialise(scanPattern, "scanPattern");
            archive.Serialise(scanPatternOptimisation, "scanPatternOptimisation");
            archive.Serialise(priority, "priority");
            archive.Serialise(concurrentJob, "concurrentJob");
        }

        LCA_TOPIC("VolumeSearchJob", 1, 0)

    };

}  // namespace Topics

#endif