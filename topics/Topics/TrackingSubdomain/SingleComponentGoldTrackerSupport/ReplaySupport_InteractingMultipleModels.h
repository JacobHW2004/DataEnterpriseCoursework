#ifndef REPLAY_SUPPORT_INTERACTING_MULTIPLE_MODELS
#define REPLAY_SUPPORT_INTERACTING_MULTIPLE_MODELS
#include <cstdint>
#include <vector>

#include "Fabric/Utils/LCA_Macros.h"
#include "ReplaySupport_ImmFilterProperties.h"


namespace Topics {
    namespace TrackingDomainReplaySupport {

        class ReplaySupport_InteractingMultipleModels {
        public:

            std::uint32_t track_id{ 0 };

            std::vector <ReplaySupport_ImmFilterProperties> filters{}; //length 10

            std::vector<double> transition_probability_matrix{}; //length 100
            std::vector<double> mixing_probability_matrix{}; //length 100
            std::vector<double> normalisations_vector{}; //length 10
            std::vector<double> model_probabilities_vector{}; //length 10
            std::vector<double> track_state_0c_combined{}; //length 9
            std::vector<double> track_covariance_0c_combined{}; //length 81
            std::vector<double> track_state_1c_combined{}; //length 9

            ReplaySupport_InteractingMultipleModels() = default;

            ReplaySupport_InteractingMultipleModels(
                std::uint32_t track_id,
                const std::vector <ReplaySupport_ImmFilterProperties>& filters,
                const std::vector<double>& transition_probability_matrix,
                const std::vector<double>& mixing_probability_matrix,
                const std::vector<double>& normalisations_vector,
                const std::vector<double>& model_probabilities_vector,
                const std::vector<double>& track_state_0c_combined,
                const std::vector<double>& track_covariance_0c_combined,
                const std::vector<double>& track_state_1c_combined)

            : track_id(track_id),
              filters(filters),
              transition_probability_matrix(transition_probability_matrix),
              mixing_probability_matrix(mixing_probability_matrix),
              normalisations_vector(normalisations_vector),
              model_probabilities_vector(model_probabilities_vector),
              track_state_0c_combined(track_state_0c_combined),
              track_covariance_0c_combined(track_covariance_0c_combined),
              track_state_1c_combined(track_state_1c_combined)

            {}

            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(filters, "filter", "filters");
                archive.Serialise(transition_probability_matrix, "transition_probability", "transition_probability_matrix");
                archive.Serialise(mixing_probability_matrix, "mixing_probability", "mixing_probability_matrix");
                archive.Serialise(normalisations_vector, "normalisation", "normalisations_vector");
                archive.Serialise(model_probabilities_vector, "model_probability", "model_probabilities_vector");
                archive.Serialise(track_state_0c_combined, "state", "track_state_0c_combined");
                archive.Serialise(track_covariance_0c_combined, "covar", "track_covariance_0c_combined");
                archive.Serialise(track_state_1c_combined, "state", "track_state_1c_combined");
            }

            LCA_TOPIC("ReplaySupport_InteractingMultipleModels", 1, 0);
        };
    }

}

#endif