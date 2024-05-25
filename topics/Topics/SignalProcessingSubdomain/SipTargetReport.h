#ifndef SIP_TARGET_REPORT_H
#define SIP_TARGET_REPORT_H

#include <vector>
#include <cstdint>

#include "Fabric/Utils/LCA_Macros.h"
#include "SipTargetRecord.h"

namespace Topics {
    namespace SipTopics {

        class SipTargetReport {
        public:
            std::uint32_t                numberOfTargetRecords{ 0 };
            std::vector<SipTargetRecord> targetRecords{};

            SipTargetReport() = default;

            SipTargetReport(std::uint32_t numberOfTargetRecords, std::vector<SipTargetRecord>& targetRecords):
                numberOfTargetRecords(numberOfTargetRecords),
                targetRecords(targetRecords)
            {}

            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(numberOfTargetRecords, "numberOfTargetRecords");
                archive.Serialise(targetRecords, "targetRecord", "targetRecords");
            }

            LCA_TOPIC("SipTargetReport", 2, 0);
        };
    }
}
#endif