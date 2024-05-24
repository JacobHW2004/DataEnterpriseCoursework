#ifndef SIGHTLINE_TARGET_REPORT_H
#define SIGHTLINE_TARGET_REPORT_H

#include <vector>
#include <cstdint>

#include "Fabric/Utils/LCA_Macros.h"
#include "SightlineTargetRecord.h"

namespace Topics {

    class SightlineTargetReport {

    public:
        std::uint32_t                                   numberOfTargetRecords{ 0 };
        std::vector<Topics::SightlineTargetRecord>      sightlineTargetRecords{};

        SightlineTargetReport() = default;

        SightlineTargetReport(std::uint32_t numberOfTargetRecords, std::vector<Topics::SightlineTargetRecord>& sightlineTargetRecords) :
            numberOfTargetRecords(numberOfTargetRecords),
            sightlineTargetRecords(sightlineTargetRecords)
        {}


        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(numberOfTargetRecords, "numberOfTargetRecords");
            archive.Serialise(sightlineTargetRecords, "sightlineTargetRecord", "sightlineTargetRecords");
        }

        LCA_TOPIC("SightlineTargetReport", 1, 0);
    };
}
#endif