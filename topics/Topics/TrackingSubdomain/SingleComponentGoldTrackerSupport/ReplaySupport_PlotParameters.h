#ifndef REPLAY_SUPPORT_PLOT_PARAMETERS
#define REPLAY_SUPPORT_PLOT_PARAMETERS
#include <cstdint>
#include <vector>

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {
    namespace TrackingDomainReplaySupport {

        class ReplaySupport_PlotParameters {
        public:

            double detection_time{ 0.0 };
            std::uint32_t plot_id{ 0 };
            std::uint32_t bar_id{ 0 };
            std::uint32_t frame_id{ 0 };
            std::uint8_t plot_type{ 0 };
            std::uint8_t plot_source{ 0 };
            double slant_range{ 0.0 };
            double range_uncertainty{ 0.0 };
            std::uint8_t no_of_range_rates{ 0 };
            std::vector<double>  range_rate_vector{ 0.0, 0.0, 0.0, 0.0 }; // length 4
            std::vector<double>  rate_uncertainty_vector{ 0.0, 0.0, 0.0, 0.0 }; // length 4
            double azimuth{ 0.0 };
            double elevation{ 0.0 };
            std::vector<double>  angle_uncertainty_matrix{ 0.0, 0.0, 0.0, 0.0 }; // length 4
            double target_size_estimate{ 0.0 };
            std::uint16_t no_of_related_tracks{ 0 };
            std::vector <std::uint32_t> track_id_vector{}; // length 0-500
            std::uint32_t GM_flag{ 0 };

            ReplaySupport_PlotParameters() = default;

            ReplaySupport_PlotParameters(
                double detection_time,
                std::uint32_t plot_id,
                std::uint32_t bar_id,
                std::uint32_t frame_id,
                std::uint8_t plot_type,
                std::uint8_t plot_source,
                double slant_range,
                double range_uncertainty,
                std::uint8_t no_of_range_rates,
                const std::vector<double>& range_rate_vector,
                const std::vector<double>& rate_uncertainty_vector,
                double azimuth,
                double elevation,
                const std::vector<double>& angle_uncertainty_matrix,
                double target_size_estimate,
                std::uint16_t no_of_related_tracks,
                const std::vector <std::uint32_t>& track_id_vector,
                std::uint32_t GM_flag)

            : detection_time(detection_time),
              plot_id(plot_id),
              bar_id(bar_id),
              frame_id(frame_id),
              plot_type(plot_type),
              plot_source(plot_source),
              slant_range(slant_range),
              range_uncertainty(range_uncertainty),
              no_of_range_rates(no_of_range_rates),
              range_rate_vector(range_rate_vector),
              rate_uncertainty_vector(rate_uncertainty_vector),
              azimuth(azimuth),
              elevation(elevation),
              angle_uncertainty_matrix(angle_uncertainty_matrix),
              target_size_estimate(target_size_estimate),
              no_of_related_tracks(no_of_related_tracks),
              track_id_vector(track_id_vector),
              GM_flag(GM_flag)

            {}

            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(detection_time, "detection_time");
                archive.Serialise(plot_id, "plot_id");
                archive.Serialise(bar_id, "bar_id");
                archive.Serialise(frame_id, "frame_id");
                archive.Serialise(plot_type, "plot_type");
                archive.Serialise(plot_source, "plot_source");
                archive.Serialise(slant_range, "slant_range");
                archive.Serialise(range_uncertainty, "range_uncertainty");
                archive.Serialise(no_of_range_rates, "no_of_range_rates");
                archive.Serialise(range_rate_vector, "range_rate", "range_rate_vector");
                archive.Serialise(rate_uncertainty_vector, "range_uncertainty", "rate_uncertainty_vector");
                archive.Serialise(azimuth, "azimuth");
                archive.Serialise(elevation, "elevation");
                archive.Serialise(angle_uncertainty_matrix, "angle_uncertainty", "angle_uncertainty_matrix");
                archive.Serialise(target_size_estimate, "target_size_estimate");
                archive.Serialise(no_of_related_tracks, "no_of_related_tracks");
                archive.Serialise(track_id_vector, "track_id", "track_id_vector");
                archive.Serialise(GM_flag, "GM_flag");
            }

            LCA_TOPIC("ReplaySupport_PlotParameters", 1, 0);
        };
    }

}

#endif