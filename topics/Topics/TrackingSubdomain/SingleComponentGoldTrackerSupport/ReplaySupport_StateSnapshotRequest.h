#ifndef REPLAY_SUPPORT_STATE_SNAPSHOT_REQUEST
#define REPLAY_SUPPORT_STATE_SNAPSHOT_REQUEST
#include <cstdint>

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {
    namespace TrackingDomainReplaySupport {

        class ReplaySupport_StateSnapshotRequest {
        public:

            std::uint32_t message_diagnostic_id{ 0 };

            ReplaySupport_StateSnapshotRequest() = default;

            ReplaySupport_StateSnapshotRequest(std::uint32_t message_diagnostic_id) : message_diagnostic_id(message_diagnostic_id) {}

            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(message_diagnostic_id, "message_diagnostic_id");
            }

            LCA_TOPIC("ReplaySupport_StateSnapshotRequest", 1, 0);
        };
    }

}

#endif