#ifndef PUBLISH_APSC_STATUS_H
#define PUBLISH_APSC_STATUS_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics {
    enum APSCOperatingState : uint8_t
    {
        APSC_UNINITIALISED,
        APSC_STANDBY_LOW_POWER
    };

    struct PublishAPSCStatus
    {
        APSCOperatingState APSC_OPERATING_STATE{};
		bool APSC_WoW_STS{ true };

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(APSC_OPERATING_STATE, "APSC_OPERATING_STATE");
			archive.Serialise(APSC_WoW_STS, "APSC_WoW_STS");
        }

        LCA_TOPIC("PublishAPSCStatus", 1, 0);
    };
}

#endif