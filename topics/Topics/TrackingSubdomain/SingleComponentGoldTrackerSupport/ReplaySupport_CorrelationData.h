#ifndef REPLAY_SUPPORT_CORRELATION_DATA
#define REPLAY_SUPPORT_CORRELATION_DATA
#include <cstdint>
#include <vector>

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {
    namespace TrackingDomainReplaySupport {

        class ReplaySupport_CorrelationData {
        public:

            std::uint32_t plot_id{ 0 };
            std::uint16_t no_of_related_tracks{ 0 };

            std::vector <std::uint32_t> related_track_id_vector{}; //Length 0-500
            std::vector<double>         weighted_distance_vector{}; //Length 0-500

            ReplaySupport_CorrelationData() = default;

            ReplaySupport_CorrelationData(
                std::uint32_t plot_id,
                std::uint16_t no_of_related_tracks,
                const std::vector <std::uint32_t>& related_track_id_vector,
                const std::vector<double>& weighted_distance_vector)

            : plot_id(plot_id),
              no_of_related_tracks(no_of_related_tracks),
              related_track_id_vector(related_track_id_vector),
              weighted_distance_vector(weighted_distance_vector)

            {}

            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(plot_id, "plot_id");
                archive.Serialise(no_of_related_tracks, "no_of_related_tracks");
                archive.Serialise(related_track_id_vector, "track_id", "related_track_id_vector");
                archive.Serialise(weighted_distance_vector, "distance", "weighted_distance_vector");
            }

            LCA_TOPIC("ReplaySupport_CorrelationData", 1, 0);
        };
    }

}

#endif