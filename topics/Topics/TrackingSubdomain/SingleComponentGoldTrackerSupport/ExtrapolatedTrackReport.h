#ifndef EXTRAPOLATED_TRACK_DATA_H
#define EXTRAPOLATED_TRACK_DATA_H
#include <vector>
#include <cstdint>

#include "SIMeter.h"
#include "SIMeterPerSecond.h"
#include "SISecond.h"
#include "SIRadian.h"

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    class ExtrapolatedTrackData {
    public:
        std::uint32_t track_id{ 0 };
        double time_of_last_update{ 0.0 };
        double extrapolation_time{ 0.0 };

        std::vector<double> extrapolated_position_vector{ 0.0,0.0,0.0 };     // length 3
        std::vector<double> extrapolated_velocity_vector{ 0.0,0.0,0.0 };     // length 3
        std::vector<double> extrapolated_acceleration_vector{ 0.0,0.0,0.0 }; // length 3
        std::vector<double> extrapolated_covariance_matrix_f0{};             // length 81, no default values due to excessive length
        std::vector<double> extrapolated_covariance_matrix_f1{};             // length 81, no default values due to excessive length

        double extrapolated_range{ 0.0 };
        double extrapolated_range_uncertainty{ 0.0 };
        double extrapolated_range_rate{ 0.0 };
        double extrapolated_range_rate_uncertainty{ 0.0 };
        double extrapolated_azimuth{ 0.0 };
        double extrapolated_elevation{ 0.0 };

        std::vector<double> extrapolated_angle_uncertainty_matrix{ 0.0,0.0,0.0,0.0 };  // length 4

        ExtrapolatedTrackData() = default;
        ExtrapolatedTrackData(std::uint32_t track_id,
            double time_of_last_update,
            double extrapolation_time,
            const std::vector<double>& extrapolated_position_vector,
            const std::vector<double>& extrapolated_velocity_vector,
            const std::vector<double>& extrapolated_acceleration_vector,
            const std::vector<double>& extrapolated_covariance_matrix_f0,
            const std::vector<double>& extrapolated_covariance_matrix_f1,
            double extrapolated_range,
            double extrapolated_range_uncertainty,
            double extrapolated_range_rate,
            double extrapolated_range_rate_uncertainty,
            double extrapolated_azimuth,
            double extrapolated_elevation,
            const std::vector<double>& extrapolated_angle_uncertainty_matrix)
            : track_id(track_id),
            time_of_last_update(time_of_last_update),
            extrapolation_time(extrapolation_time),
            extrapolated_position_vector(extrapolated_position_vector),
            extrapolated_velocity_vector(extrapolated_velocity_vector),
            extrapolated_acceleration_vector(extrapolated_acceleration_vector),
            extrapolated_covariance_matrix_f0(extrapolated_covariance_matrix_f0),
            extrapolated_covariance_matrix_f1(extrapolated_covariance_matrix_f1),
            extrapolated_range(extrapolated_range),
            extrapolated_range_uncertainty(extrapolated_range_uncertainty),
            extrapolated_range_rate(extrapolated_range_rate),
            extrapolated_range_rate_uncertainty(extrapolated_range_rate_uncertainty),
            extrapolated_azimuth(extrapolated_azimuth),
            extrapolated_elevation(extrapolated_elevation),
            extrapolated_angle_uncertainty_matrix(extrapolated_angle_uncertainty_matrix)
        {}

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(track_id, "track_id");
            archive.Serialise(time_of_last_update, "time_of_last_update");
            archive.Serialise(extrapolation_time, "extrapolation_time");
            archive.Serialise(extrapolated_position_vector, "extrap_pos", "extrapolated_position_vector");
            archive.Serialise(extrapolated_velocity_vector, "extrap_vel", "extrapolated_velocity_vector");
            archive.Serialise(extrapolated_acceleration_vector, "extrap_accel", "extrapolated_acceleration_vector");
            archive.Serialise(extrapolated_covariance_matrix_f0, "extrap_covar_f0", "extrapolated_covariance_matrix_f0");
            archive.Serialise(extrapolated_covariance_matrix_f1, "extrap_covar_f1", "extrapolated_covariance_matrix_f1");
            archive.Serialise(extrapolated_range, "extrapolated_range");
            archive.Serialise(extrapolated_range_uncertainty, "extrapolated_range_uncertainty");
            archive.Serialise(extrapolated_range_rate, "extrapolated_range_rate");
            archive.Serialise(extrapolated_range_rate_uncertainty, "extrapolated_range_rate_uncertainty");
            archive.Serialise(extrapolated_azimuth, "extrapolated_azimuth");
            archive.Serialise(extrapolated_elevation, "extrapolated_elevation");
            archive.Serialise(extrapolated_angle_uncertainty_matrix, "extrap_angle_uncertainty", "extrapolated_angle_uncertainty_matrix");
        }

        LCA_TOPIC("ExtrapolatedTrackData", 1, 0);
    };

    class ExtrapolatedTrackReport {
    public:
        std::uint32_t extrapolated_track_report_id;
        std::uint16_t no_of_tracks;
        std::vector<ExtrapolatedTrackData> extrapolated_tracks; // length 0-500

        ExtrapolatedTrackReport() = default;
        ExtrapolatedTrackReport(std::uint32_t extrapolated_track_report_id,
            std::uint16_t no_of_tracks,
            const std::vector<ExtrapolatedTrackData>& extrapolated_tracks)
            : extrapolated_track_report_id(extrapolated_track_report_id),
            no_of_tracks(no_of_tracks),
            extrapolated_tracks(extrapolated_tracks)
        {}

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(extrapolated_track_report_id, "extrapolated_track_report_id");
            archive.Serialise(no_of_tracks, "no_of_tracks");
            archive.Serialise(extrapolated_tracks, "track_extrapolation", "extrapolated_tracks");
        }

        LCA_TOPIC("ExtrapolatedTrackReport", 1, 0);
    };

}

#endif