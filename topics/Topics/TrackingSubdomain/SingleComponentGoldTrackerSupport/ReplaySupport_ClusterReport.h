#ifndef REPLAY_SUPPORT_CLUSTER_REPORT_H
#define REPLAY_SUPPORT_CLUSTER_REPORT_H
#include <cstdint>
#include <vector>

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {
    namespace TrackingDomainReplaySupport {

        class ReplaySupport_ClusterReport {
        public:

            std::uint32_t              cluster_id{ 0 };
            std::uint8_t               cluster_type{ 0 };
            std::uint8_t               cluster_status{ 0 };
            double                     cluster_center_range{ 0.0 };
            double                     cluster_center_azimuth{ 0.0 };
            double                     cluster_center_elevation{ 0.0 };
            std::vector<double>        cluster_boundaries_range{ 0.0, 0.0 }; //Length 2
            std::vector<double>        cluster_boundaries_azimuth{ 0.0, 0.0 }; //Length 2
            std::vector<double>        cluster_boundaries_elevation{ 0.0, 0.0 }; //Length 2
            std::uint16_t              no_of_assigned_tracks{ 0 };
            std::vector<std::uint32_t> assigned_track_id_vector{}; //Length 0-500
            std::uint16_t              no_of_assigned_plots{ 0 };
            std::vector<std::uint32_t> assigned_plot_id_vector{}; //Length 0-500

            ReplaySupport_ClusterReport() = default;

            ReplaySupport_ClusterReport(
                std::uint32_t cluster_id,
                std::uint8_t cluster_type,
                std::uint8_t cluster_status,
                double cluster_center_range,
                double cluster_center_azimuth,
                double cluster_center_elevation,
                const std::vector<double>& cluster_boundaries_range,
                const std::vector<double>& cluster_boundaries_azimuth,
                const std::vector<double>& cluster_boundaries_elevation,
                std::uint16_t no_of_assigned_tracks,
                const std::vector<std::uint32_t>& assigned_track_id_vector,
                std::uint16_t no_of_assigned_plots,
                const std::vector<std::uint32_t>& assigned_plot_id_vector)

            : cluster_id(cluster_id),
              cluster_type(cluster_type),
              cluster_status(cluster_status),
              cluster_center_range(cluster_center_range),
              cluster_center_azimuth(cluster_center_azimuth),
              cluster_center_elevation(cluster_center_elevation),
              cluster_boundaries_range(cluster_boundaries_range),
              cluster_boundaries_azimuth(cluster_boundaries_azimuth),
              cluster_boundaries_elevation(cluster_boundaries_elevation),
              no_of_assigned_tracks(no_of_assigned_tracks),
              assigned_track_id_vector(assigned_track_id_vector),
              no_of_assigned_plots(no_of_assigned_plots),
              assigned_plot_id_vector(assigned_plot_id_vector)
            {}

            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(cluster_id, "cluster_id");
                archive.Serialise(cluster_type, "cluster_type");
                archive.Serialise(cluster_status, "cluster_status");
                archive.Serialise(cluster_center_range, "cluster_center_range");
                archive.Serialise(cluster_center_azimuth, "cluster_center_azimuth");
                archive.Serialise(cluster_center_elevation, "cluster_center_elevation");
                archive.Serialise(cluster_boundaries_range, "rng", "cluster_boundaries_range");
                archive.Serialise(cluster_boundaries_azimuth, "az", "cluster_boundaries_azimuth");
                archive.Serialise(cluster_boundaries_elevation, "el", "cluster_boundaries_elevation");
                archive.Serialise(no_of_assigned_tracks, "no_of_assigned_tracks");
                archive.Serialise(assigned_track_id_vector, "track_id", "assigned_track_id_vector");
                archive.Serialise(no_of_assigned_plots, "no_of_assigned_plots");
                archive.Serialise(assigned_plot_id_vector, "plot_id", "assigned_plot_id_vector");
            }

            LCA_TOPIC("ReplaySupport_ClusterReport", 1, 0);
        };
    }

}

#endif