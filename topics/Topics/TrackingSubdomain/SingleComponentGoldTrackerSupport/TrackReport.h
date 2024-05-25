#ifndef TRACK_REPORT_H
#define TRACK_REPORT_H
#include <vector>
#include <cstdint>

#include "Fabric/Utils/LCA_Macros.h"
namespace Topics {

    class TrackData {
    public:
        std::uint32_t       track_id{ 0 };
        std::uint8_t        track_status{ 0 };
        double              time_of_last_update{ 0.0 };
        std::uint32_t       plot_id{ 0 };
        std::uint8_t        track_type{ 0 };
        std::uint8_t        updating_target_type{ 0 };
        std::uint8_t        initial_source{ 0 };
        std::uint8_t        update_source{ 0 };
        std::uint8_t        priority_classification{ 0 };
        std::uint32_t       rank{ 0 };
        double              target_size_estimate{ 0.0 };
        bool                target_size_validity_flag{ false };
        double              SNR{ 0.0 };
        double              track_angle{ 0.0 };
        double              aspect_angle{ 0.0 };
        std::vector<double> position_vector{ 0.0,0.0,0.0 };     // length 3
        std::vector<double> velocity_vector{ 0.0,0.0,0.0 };     // length 3
        std::vector<double> acceleration_vector{ 0.0,0.0,0.0 }; // length 3
        std::uint8_t        manoeuvre_class{ 0 };
        std::vector<double> covariance_matrix_f0{}; // length 81, no default values due to excessive length
        std::vector<double> covariance_matrix_f1{}; // length 81, no default values due to excessive length
        std::vector<double> process_noise_matrix{}; // length 81
        double              range{ 0.0 };
        double              range_uncertainty{ 0.0 };
        double              range_rate{ 0.0 };
        double              range_rate_uncertainty{ 0.0 };
        double              azimuth{ 0.0 };
        double              elevation{ 0.0 };
        std::vector<double> angle_uncertainty_matrix{ 0.0,0.0,0.0,0.0 }; // length 4
        double              azimuth_rate{ 0.0 };
        double              elevation_rate{ 0.0 };
        double              azimuth_acceleration{ 0.0 };
        double              elevation_acceleration{ 0.0 };

        TrackData() = default;
        TrackData(std::uint32_t track_id,
            std::uint8_t track_status,
            double time_of_last_update,
            std::uint32_t plot_id,
            std::uint8_t track_type,
            std::uint8_t updating_target_type,
            std::uint8_t initial_source,
            std::uint8_t update_source,
            std::uint8_t priority_classification,
            std::uint32_t rank,
            double target_size_estimate,
            std::uint8_t target_size_validity_flag,
            double SNR,
            double track_angle,
            double aspect_angle,
            const std::vector<double>& position_vector,
            const std::vector<double>& velocity_vector,
            const std::vector<double>& acceleration_vector,
            std::uint8_t manoeuvre_class,
            const std::vector<double>& covariance_matrix_f0,
            const std::vector<double>& covariance_matrix_f1,
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
            double elevation_acceleration)
            : track_id(track_id),
            track_status(track_status),
            time_of_last_update(time_of_last_update),
            plot_id(plot_id),
            track_type(track_type),
            updating_target_type(updating_target_type),
            initial_source(initial_source),
            update_source(update_source),
            priority_classification(priority_classification),
            rank(rank),
            target_size_estimate(target_size_estimate),
            target_size_validity_flag(target_size_validity_flag),
            SNR(SNR),
            track_angle(track_angle),
            aspect_angle(aspect_angle),
            position_vector(position_vector),
            velocity_vector(velocity_vector),
            acceleration_vector(acceleration_vector),
            manoeuvre_class(manoeuvre_class),
            covariance_matrix_f0(covariance_matrix_f0),
            covariance_matrix_f1(covariance_matrix_f1),
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
            elevation_acceleration(elevation_acceleration)
        {}

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(track_id, "track_id");
            archive.Serialise(track_status, "track_status");
            archive.Serialise(time_of_last_update, "time_of_last_update");
            archive.Serialise(plot_id, "plot_id");
            archive.Serialise(track_type, "track_type");
            archive.Serialise(updating_target_type, "updating_target_type");
            archive.Serialise(initial_source, "initial_source");
            archive.Serialise(update_source, "update_source");
            archive.Serialise(priority_classification, "priority_classification");
            archive.Serialise(rank, "rank");
            archive.Serialise(target_size_estimate, "target_size_estimate");
            archive.Serialise(target_size_validity_flag, "target_size_validity_flag");
            archive.Serialise(SNR, "SNR");
            archive.Serialise(track_angle, "track_angle");
            archive.Serialise(aspect_angle, "aspect_angle");
            archive.Serialise(position_vector, "pos", "position_vector");
            archive.Serialise(velocity_vector, "vel", "velocity_vector");
            archive.Serialise(acceleration_vector, "accel", "acceleration_vector");
            archive.Serialise(manoeuvre_class, "manoeuvre_class");
            archive.Serialise(covariance_matrix_f0, "covar_f0", "covariance_matrix_f0");
            archive.Serialise(covariance_matrix_f1, "covar_f1", "covariance_matrix_f1");
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
        }

        LCA_TOPIC("TrackData", 1, 0);
    };

    class TrackReport {
    public:
        std::uint32_t track_report_id;
        std::uint16_t no_of_tracks;
        std::uint16_t no_of_updated_tracks;
        std::vector<std::uint32_t> updated_track_id_vector; // length 0-360
        std::uint16_t no_of_deleted_tracks;
        std::vector<std::uint32_t> deleted_track_id_vector; // length 0-500
        std::uint8_t no_of_initiated_tracks;
        std::vector<std::uint32_t> initiated_track_id_vector; // length 0-140
        std::vector<TrackData> tracks; // length 0-500

        TrackReport() = default;
        TrackReport(std::uint32_t track_report_id,
            std::uint16_t no_of_tracks,
            std::uint16_t no_of_updated_tracks,
            const std::vector<std::uint32_t>& updated_track_id_vector,
            std::uint16_t no_of_deleted_tracks,
            const std::vector<std::uint32_t>& deleted_track_id_vector,
            std::uint8_t no_of_initiated_tracks,
            const std::vector<std::uint32_t>& initiated_track_id_vector,
            const std::vector<TrackData>& tracks)
            : track_report_id(track_report_id),
            no_of_tracks(no_of_tracks),
            no_of_updated_tracks(no_of_updated_tracks),
            updated_track_id_vector(updated_track_id_vector),
            no_of_deleted_tracks(no_of_deleted_tracks),
            deleted_track_id_vector(deleted_track_id_vector),
            no_of_initiated_tracks(no_of_initiated_tracks),
            initiated_track_id_vector(initiated_track_id_vector),
            tracks(tracks)
        {}

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(track_report_id, "track_report_id");
            archive.Serialise(no_of_tracks, "no_of_tracks");
            archive.Serialise(no_of_updated_tracks, "no_of_updated_tracks");
            archive.Serialise(updated_track_id_vector, "updated_track_id", "updated_track_id_vector");
            archive.Serialise(no_of_deleted_tracks, "no_of_deleted_tracks");
            archive.Serialise(deleted_track_id_vector, "deleted_track_id", "deleted_track_id_vector");
            archive.Serialise(no_of_initiated_tracks, "no_of_initiated_tracks");
            archive.Serialise(initiated_track_id_vector, "initiated_track_id", "initiated_track_id_vector");
            archive.Serialise(tracks, "track", "tracks");
        }

        LCA_TOPIC("TrackReport", 1, 0);
    };

}
#endif