#ifndef REPLAY_SUPPORT_INTERNAL_TRACK_RECORD
#define REPLAY_SUPPORT_INTERNAL_TRACK_RECORD
#include <cstdint>
#include <vector>

#include "Fabric/Utils/LCA_Macros.h"
#include "ReplaySupport_TrackProperties.h"
#include "ReplaySupport_TrackHistory.h"

namespace Topics {
    namespace TrackingDomainReplaySupport {

        class ReplaySupport_InternalTrackRecord {
        public:

            std::uint32_t track_id{ 0 };
            double initiation_time{ 0.0 };
            double last_update_time{ 0.0 };
            std::uint8_t track_status{ 0 };
            std::uint32_t plot_id{ 0 };
            std::uint32_t assigned_cluster_id{ 0 };
            ReplaySupport_TrackProperties track_properties;
            std::uint8_t priority_classification{ 0 };
            std::uint32_t rank{ 0 };
            double target_size_estimate{ 0.0 };
            double SNR{ 0.0 };
            double track_angle{ 0.0 };
            double aspect_angle{ 0.0 };
            std::vector<double> position_vector_frame1{ 0.0, 0.0, 0.0 }; //Length 3
            std::vector<double> position_vector_frame0{ 0.0, 0.0, 0.0 }; //Length 3
            std::vector<double> velocity_vector{ 0.0, 0.0, 0.0 }; //Length 3
            std::vector<double> acceleration_vector{ 0.0, 0.0, 0.0 }; //Length 3
            std::uint8_t manoeuvre_class{ 0 };
            std::vector<double> covariance_matrix{}; //Length 81
            double var_a{ 0.0 };
            std::vector<double> process_noise_matrix{}; //Length 81
            double range{ 0.0 };
            double range_uncertainty{ 0.0 };
            double range_rate{ 0.0 };
            double range_rate_uncertainty{ 0.0 };
            double azimuth{ 0.0 };
            double elevation{ 0.0 };
            std::vector<double> angle_uncertainty_matrix{0.0, 0.0, 0.0, 0.0}; //Length 4
            double azimuth_rate{ 0.0 };
            double elevation_rate{ 0.0 };
            double azimuth_acceleration{ 0.0 };
            double elevation_acceleration{ 0.0 };
            std::uint8_t range_rate_index{ 0 };
            std::uint8_t track_transition_type{ 0 };
            double track_transition_time{ 0.0 };
            std::uint8_t no_of_AO_updates{ 0 };
            double nominal_AO_range{ 0.0 };
            std::uint8_t track_reinitialised{ 0 };
            std::uint8_t update_abandoned{ 0 };
            ReplaySupport_TrackHistory track_history;

            ReplaySupport_InternalTrackRecord() = default;

            ReplaySupport_InternalTrackRecord(
                std::uint32_t track_id,
                double initiation_time,
                double last_update_time,
                std::uint8_t track_status,
                std::uint32_t plot_id,
                std::uint32_t assigned_cluster_id,
                ReplaySupport_TrackProperties track_properties,
                std::uint8_t priority_classification,
                std::uint32_t rank,
                double target_size_estimate,
                double SNR,
                double track_angle,
                double aspect_angle,
                const std::vector<double>& position_vector_frame1,
                const std::vector<double>& position_vector_frame0,
                const std::vector<double>& velocity_vector,
                const std::vector<double>& acceleration_vector,
                std::uint8_t manoeuvre_class,
                const std::vector<double>& covariance_matrix, 
                double var_a,
                const std::vector<double>& process_noise_matrix,
                double range,
                double range_uncertainty,
                double range_rate,
                double range_rate_uncertainty,
                double azimuth,
                double elevation,
                const std::vector<double>& angle_uncertainty_matrix,
                double azimuth_rate,
                double elevation_rate,
                double azimuth_acceleration,
                double elevation_acceleration,
                std::uint8_t range_rate_index,
                std::uint8_t track_transition_type,
                double track_transition_time,
                std::uint8_t no_of_AO_updates,
                double nominal_AO_range,
                std::uint8_t track_reinitialised,
                std::uint8_t update_abandoned,
                ReplaySupport_TrackHistory track_history)

            : track_id(track_id),
              initiation_time(initiation_time),
              last_update_time(last_update_time),
              track_status(track_status),
              plot_id(plot_id),
              assigned_cluster_id(assigned_cluster_id),
              track_properties(track_properties),
              priority_classification(priority_classification),
              rank(rank),
              target_size_estimate(target_size_estimate),
              SNR(SNR),
              track_angle(track_angle),
              aspect_angle(aspect_angle),
              position_vector_frame1(position_vector_frame1),
              position_vector_frame0(position_vector_frame0),
              velocity_vector(velocity_vector),
              acceleration_vector(acceleration_vector),
              manoeuvre_class(manoeuvre_class),
              covariance_matrix(covariance_matrix),
              var_a(var_a),
              process_noise_matrix(process_noise_matrix),
              range(range),
              range_uncertainty(range_uncertainty),
              range_rate(range_rate),
              range_rate_uncertainty(range_rate_uncertainty),
              azimuth(azimuth),
              elevation(elevation),
              angle_uncertainty_matrix(angle_uncertainty_matrix),
              azimuth_rate(azimuth_rate),
              elevation_rate(elevation_rate),
              azimuth_acceleration(azimuth_acceleration),
              elevation_acceleration(elevation_acceleration),
              range_rate_index(range_rate_index),
              track_transition_type(track_transition_type),
              track_transition_time(track_transition_time),
              no_of_AO_updates(no_of_AO_updates),
              nominal_AO_range(nominal_AO_range),
              track_reinitialised(track_reinitialised),
              update_abandoned(update_abandoned),
              track_history(track_history)

            {}

            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(track_id, "track_id");
                archive.Serialise(initiation_time, "initiation_time");
                archive.Serialise(last_update_time, "last_update_time");
                archive.Serialise(track_status, "track_status");
                archive.Serialise(plot_id, "plot_id");
                archive.Serialise(assigned_cluster_id, "assigned_cluster_id");
                archive.Serialise(track_properties, "track_properties");
                archive.Serialise(priority_classification, "priority_classification");
                archive.Serialise(rank, "rank");
                archive.Serialise(target_size_estimate, "target_size_estimate");
                archive.Serialise(SNR, "SNR");
                archive.Serialise(track_angle, "track_angle");
                archive.Serialise(aspect_angle, "aspect_angle");
                archive.Serialise(position_vector_frame1, "pos", "position_vector_frame1");
                archive.Serialise(position_vector_frame0, "pos", "position_vector_frame0");
                archive.Serialise(velocity_vector, "vel", "velocity_vector");
                archive.Serialise(acceleration_vector, "acc", "acceleration_vector");
                archive.Serialise(manoeuvre_class, "manoeuvre_class");
                archive.Serialise(covariance_matrix, "covar", "covariance_matrix");
                archive.Serialise(var_a, "var_a");
                archive.Serialise(process_noise_matrix, "process_noise", "process_noise_matrix");
                archive.Serialise(range, "range");
                archive.Serialise(range_uncertainty, "range_uncertainty");
                archive.Serialise(range_rate, "range_rate");
                archive.Serialise(range_rate_uncertainty, "range_rate_uncertainty");
                archive.Serialise(azimuth, "azimuth");
                archive.Serialise(elevation, "elevation");
                archive.Serialise(angle_uncertainty_matrix, "angle_uncertainty", "angle_uncertainty_matrix");
                archive.Serialise(azimuth_rate, "azimuth_rate");
                archive.Serialise(elevation_rate, "elevation_rate");
                archive.Serialise(azimuth_acceleration, "azimuth_acceleration");
                archive.Serialise(elevation_acceleration, "elevation_acceleration");
                archive.Serialise(range_rate_index, "range_rate_index");
                archive.Serialise(track_transition_type, "track_transition_type");
                archive.Serialise(track_transition_time, "track_transition_time");
                archive.Serialise(no_of_AO_updates, "no_of_AO_updates");
                archive.Serialise(nominal_AO_range, "nominal_AO_range");
                archive.Serialise(track_reinitialised, "track_reinitialised");
                archive.Serialise(update_abandoned, "update_abandoned");
                archive.Serialise(track_history, "track_history");

            }

            LCA_TOPIC("ReplaySupport_InternalTrackRecord", 1, 0);
        };
    }


}

#endif