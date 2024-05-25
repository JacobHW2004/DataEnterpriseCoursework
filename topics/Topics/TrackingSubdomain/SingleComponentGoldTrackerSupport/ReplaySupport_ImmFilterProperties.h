#ifndef REPLAY_SUPPORT_IMM_FILTER_PROPERTIES
#define REPLAY_SUPPORT_IMM_FILTER_PROPERTIES
#include <cstdint>
#include <vector>

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {
    namespace TrackingDomainReplaySupport {

        class ReplaySupport_ImmFilterProperties {
        public:

            std::vector<double> track_state_0c_interacted{}; // Length 9
            std::vector<double> track_covariance_0c_interacted{}; // Length 81

            double likelihood{ 0.0 };

            std::vector<double> updated_track_state_0c{}; // Length 9
            std::vector<double> updated_track_covariance_0c{}; // Length 81

            ReplaySupport_ImmFilterProperties() = default;

            ReplaySupport_ImmFilterProperties(
                const std::vector<double>& track_state_0c_interacted,
                const std::vector<double>& track_covariance_0c_interacted,
                double likelihood,
                const std::vector<double>& updated_track_state_0c,
                const std::vector<double>& updated_track_covariance_0c)

            : track_state_0c_interacted(track_state_0c_interacted),
              track_covariance_0c_interacted(track_covariance_0c_interacted),
              likelihood(likelihood),
              updated_track_state_0c(updated_track_state_0c),
              updated_track_covariance_0c(updated_track_covariance_0c)

            {}

            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(track_state_0c_interacted, "state", "track_state_0c_interacted");
                archive.Serialise(track_covariance_0c_interacted, "covar", "track_covariance_0c_interacted");
                archive.Serialise(likelihood, "likelihood");
                archive.Serialise(updated_track_state_0c, "updated_state", "updated_track_state_0c");
                archive.Serialise(updated_track_covariance_0c, "updated_covar", "updated_track_covariance_0c");
            }

            LCA_TOPIC("ReplaySupport_ImmFilterProperties", 1, 0);
        };
    }

}

#endif