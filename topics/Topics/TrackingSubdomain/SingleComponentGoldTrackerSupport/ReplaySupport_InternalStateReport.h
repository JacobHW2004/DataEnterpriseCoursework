#ifndef REPLAY_SUPPORT_INTERNAL_STATE_REPORT_H
#define REPLAY_SUPPORT_INTERNAL_STATE_REPORT_H
#include <cstdint>
#include <vector>

#include "Fabric/Utils/LCA_Macros.h"
#include "ReplaySupport_ClusterReport.h"
#include "ReplaySupport_InternalTrackRecord.h"
#include "ReplaySupport_InteractingMultipleModels.h"
#include "ReplaySupport_PlotReport.h"
#include "ReplaySupport_CorrelationData.h"

namespace Topics {
    namespace TrackingDomainReplaySupport {

        class ReplaySupport_InternalStateReport {
        public:

            double dwell_time{ 0.0 };
            std::uint32_t dwell_id{ 0 };
            std::uint32_t input_record_id{ 0 };
            std::uint16_t no_of_clusters{ 0 };
            std::vector<ReplaySupport_ClusterReport> clusters{}; // length 0-750
            std::uint16_t no_of_internal_tracks{ 0 };
            std::vector<ReplaySupport_InternalTrackRecord> internal_track{}; // length 0-500
            std::vector<ReplaySupport_InteractingMultipleModels> IMM{};   // length 0-500
            std::vector<std::uint32_t> track_update_count{};  // length 0-500
            std::uint16_t no_of_unprocessed_plots{ 0 };
            std::vector<ReplaySupport_PlotReport> unprocessed_plot{};  // length 0-500
            std::vector<ReplaySupport_CorrelationData> correlation_data{};  // length 0-500
            std::vector<std::uint32_t> track_ids_output{};  // length 0-500

            ReplaySupport_InternalStateReport() = default;

            ReplaySupport_InternalStateReport(
                double dwell_time,
                std::uint32_t dwell_id,
                std::uint32_t input_record_id,
                std::uint16_t no_of_clusters,
                const std::vector<ReplaySupport_ClusterReport>& clusters,
                std::uint16_t no_of_internal_tracks,
                const std::vector<ReplaySupport_InternalTrackRecord>& internal_track,
                const std::vector<ReplaySupport_InteractingMultipleModels>& IMM,
                const std::vector<std::uint32_t>& track_update_count,
                std::uint16_t no_of_unprocessed_plots,
                const std::vector<ReplaySupport_PlotReport>& unprocessed_plot,
                const std::vector<ReplaySupport_CorrelationData>& correlation_data,
                const std::vector<std::uint32_t>& track_ids_output)

            : dwell_time(dwell_time),
              dwell_id(dwell_id),
              input_record_id(input_record_id),
              no_of_clusters(no_of_clusters),
              clusters(clusters),
              no_of_internal_tracks(no_of_internal_tracks),
              internal_track(internal_track),
              IMM(IMM),
              track_update_count(track_update_count),
              no_of_unprocessed_plots(no_of_unprocessed_plots),
              unprocessed_plot(unprocessed_plot),
              correlation_data(correlation_data),
              track_ids_output(track_ids_output)
            {}

            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(dwell_time, "dwell_time");
                archive.Serialise(dwell_id, "dwell_id");
                archive.Serialise(input_record_id, "input_record_id");
                archive.Serialise(no_of_clusters, "no_of_clusters");
                archive.Serialise(clusters, "cluster", "clusters");
                archive.Serialise(no_of_internal_tracks, "no_of_internal_tracks");
                archive.Serialise(internal_track, "track", "internal_track");
                archive.Serialise(IMM, "IMM_properties", "IMM");
                archive.Serialise(track_update_count, "update_count", "track_update_count");
                archive.Serialise(no_of_unprocessed_plots, "no_of_unprocessed_plots");
                archive.Serialise(unprocessed_plot, "plot", "unprocessed_plot");
                archive.Serialise(correlation_data, "correlation", "correlation_data");
                archive.Serialise(track_ids_output, "track_id", "track_ids_output");
            }

            LCA_TOPIC("ReplaySupport_InternalStateReport", 1, 0);
        };
    }

}

#endif