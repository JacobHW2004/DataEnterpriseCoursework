#ifndef REPLAY_SUPPORT_TRACK_PROPERTIES
#define REPLAY_SUPPORT_TRACK_PROPERTIES
#include <cstdint>
#include <vector>

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {
    namespace TrackingDomainReplaySupport {

        class ReplaySupport_TrackProperties {
        public:

            std::uint8_t track_type{ 0 };
            std::uint8_t updating_target_type{ 0 };
            std::uint8_t initial_source{ 0 };
            std::uint8_t update_source{ 0 };

            ReplaySupport_TrackProperties() = default;

            ReplaySupport_TrackProperties(
                std::uint8_t track_type,
                std::uint8_t updating_target_type,
                std::uint8_t initial_source,
                std::uint8_t update_source)

            : track_type(track_type),
              updating_target_type(updating_target_type),
              initial_source(initial_source),
              update_source(update_source)

            {}

            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(track_type, "track_type");
                archive.Serialise(updating_target_type, "updating_target_type");
                archive.Serialise(initial_source, "initial_source");
                archive.Serialise(update_source, "update_source");
            }

            LCA_TOPIC("ReplaySupport_TrackProperties", 1, 0);
        };
    }

}

#endif