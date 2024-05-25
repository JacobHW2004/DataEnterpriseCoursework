#ifndef TRACKING_DOMAIN_PLOT_H
#define TRACKING_DOMAIN_PLOT_H

#include "Fabric/Utils/LCA_Macros.h"

#include <cstdint>
#include <array>

#include "SISecond.h"
#include "SIMeter.h"
#include "SIMeterSquared.h"
#include "SIMeterPerSecond.h"
#include "SIMeterSquaredPerSecondSquared.h"
#include "SIRadian.h"
#include "SIRadianSquared.h"
#include "SIDecibelsPerSquareMeter.h"
#include "Velocity.h"
#include "LatitudeLongitudeAltitude.h"

namespace Topics {
    namespace Tracking {

        constexpr uint8_t MAXIMUM_NUMBER_OF_RANGE_RATES{ 4U };

        class Plot {

        public:

            std::uint32_t plot_id{ 0 };
            SI::SISecond  detection_time{ 0.0 };

            double SNR{ 0.0 };
            double target_amplitude{ 0.0 };

            LatitudeLongitudeAltitude ownship_position{};
            Velocity                  ownship_velocity{ FrameOfReference::FRAME_0 };

            bool angle_only_flag  { false };
            bool ground_mover_flag{ false };

            SI::SIMeter        slant_range{ 0.0 };
            SI::SIMeterSquared range_uncertainty{ 0.0 };
            std::uint8_t       no_of_range_rates{ 0 };

            std::array<SI::SIMeterPerSecond, MAXIMUM_NUMBER_OF_RANGE_RATES>               range_rate_vector{ SI::SIMeterPerSecond(0.0), SI::SIMeterPerSecond(0.0), SI::SIMeterPerSecond(0.0), SI::SIMeterPerSecond(0.0) };
            std::array<SI::SIMeterSquaredPerSecondSquared, MAXIMUM_NUMBER_OF_RANGE_RATES> rate_uncertainty_vector{ SI::SIMeterSquaredPerSecondSquared(0.0), SI::SIMeterSquaredPerSecondSquared(0.0), SI::SIMeterSquaredPerSecondSquared(0.0), SI::SIMeterSquaredPerSecondSquared(0.0) };

            SI::SIRadian azimuth{ 0.0 };
            SI::SIRadian elevation{ 0.0 };

            SI::SIRadianSquared azimuth_variance{ 0.0 };
            SI::SIRadianSquared elevation_variance{ 0.0 };
            SI::SIRadianSquared azimuth_elevation_covariance{ 0.0 };
            SI::SIRadianSquared elevation_azimuth_covariance{ 0.0 };

            SI::SIDecibelsPerSquareMeter target_size_estimate{ 0.0 };

            Plot() = default;

            Plot(std::uint32_t plot_id, 
                SI::SISecond detection_time, 
                double SNR, 
                double target_amplitude,
                LatitudeLongitudeAltitude ownship_position,
                Velocity ownship_velocity, 
                SI::SIMeter slant_range, 
                SI::SIMeterSquared range_uncertainty,
                std::uint8_t no_of_range_rates,
                const std::array<SI::SIMeterPerSecond, MAXIMUM_NUMBER_OF_RANGE_RATES>& range_rate_vector,
                const std::array<SI::SIMeterSquaredPerSecondSquared, MAXIMUM_NUMBER_OF_RANGE_RATES>& rate_uncertainty_vector,
                SI::SIRadian azimuth, 
                SI::SIRadian elevation,
                SI::SIRadianSquared azimuth_variance,
                SI::SIRadianSquared elevation_variance,
                SI::SIRadianSquared azimuth_elevation_covariance,
                SI::SIRadianSquared elevation_azimuth_covariance,
                SI::SIDecibelsPerSquareMeter target_size_estimate)
               
                : plot_id(plot_id),
                detection_time(detection_time),
                SNR(SNR),
                target_amplitude(target_amplitude),
                ownship_position(ownship_position),
                ownship_velocity(ownship_velocity),
                slant_range(slant_range),
                range_uncertainty(range_uncertainty),
                no_of_range_rates(no_of_range_rates),
                range_rate_vector(range_rate_vector),
                rate_uncertainty_vector(rate_uncertainty_vector),
                azimuth(azimuth),
                elevation(elevation),
                azimuth_variance(azimuth_variance),
                elevation_variance(elevation_variance),
                azimuth_elevation_covariance(azimuth_elevation_covariance),
                elevation_azimuth_covariance(elevation_azimuth_covariance),
                target_size_estimate(target_size_estimate)  
            {}

            template <class T>
            void Serialise(T& archive) {

                /* Temporary variables to allow serialization of SI-unit members */
                double detection_time_double{ detection_time() };
                double slant_range_double{ slant_range() };
                double range_uncertainty_double{ range_uncertainty() };
                double azimuth_double{ azimuth() };
                double elevation_double{ elevation() };
                double azimuth_variance_double{ azimuth_variance() };
                double elevation_variance_double{ elevation_variance() };
                double azimuth_elevation_covariance_double{ azimuth_elevation_covariance() };
                double elevation_azimuth_covariance_double{ elevation_azimuth_covariance() };
                double target_size_estimate_double{ target_size_estimate() };

                std::array<double, MAXIMUM_NUMBER_OF_RANGE_RATES> range_rate_vector_double{};
                std::array<double, MAXIMUM_NUMBER_OF_RANGE_RATES> rate_uncertainty_vector_double{};

                archive.Serialise(plot_id,                  "plot_id");
                archive.Serialise(detection_time_double,    "detection_time");
                archive.Serialise(SNR,                      "SNR");
                archive.Serialise(target_amplitude,         "target_amplitude");
                archive.Serialise(ownship_position,         "ownship_position");
                archive.Serialise(ownship_velocity,         "ownship_velocity");
                archive.Serialise(angle_only_flag,          "angle_only_flag");
                archive.Serialise(ground_mover_flag,        "ground_mover_flag");
                archive.Serialise(slant_range_double,       "slant_range");
                archive.Serialise(range_uncertainty_double, "range_uncertainty");
                archive.Serialise(no_of_range_rates,        "no_of_range_rates");

                for (std::uint8_t i{ 0 }; i < MAXIMUM_NUMBER_OF_RANGE_RATES; i++) {

                    range_rate_vector_double[i] = range_rate_vector[i]();

                    archive.Serialise(range_rate_vector_double[i], "range_rate_vector[" + std::to_string(i) + "]");
                }

                for (std::uint8_t i{ 0 }; i < MAXIMUM_NUMBER_OF_RANGE_RATES; i++) {

                    rate_uncertainty_vector_double[i] = rate_uncertainty_vector[i]();

                    archive.Serialise(rate_uncertainty_vector_double[i], "rate_uncertainty_vector[" + std::to_string(i) + "]");
                }

                archive.Serialise(azimuth_double,                      "azimuth");
                archive.Serialise(elevation_double,                    "elevation");
                archive.Serialise(azimuth_variance_double,             "azimuth_variance");
                archive.Serialise(elevation_variance_double,           "elevation_variance");
                archive.Serialise(azimuth_elevation_covariance_double, "azimuth_elevation_covariance");
                archive.Serialise(elevation_azimuth_covariance_double, "elevation_azimuth_covariance");
                archive.Serialise(target_size_estimate_double,         "target_size_estimate");

                /* After deserialisation convert back to SIRadians */
                detection_time               = detection_time_double;
                slant_range                  = slant_range_double;
                range_uncertainty            = range_uncertainty_double;
                azimuth                      = azimuth_double;
                elevation                    = elevation_double;
                azimuth_variance             = azimuth_variance_double;
                elevation_variance           = elevation_variance_double;
                azimuth_elevation_covariance = azimuth_elevation_covariance_double;
                elevation_azimuth_covariance = elevation_azimuth_covariance_double;
                target_size_estimate         = target_size_estimate_double;

                for (std::uint8_t i{ 0 }; i < MAXIMUM_NUMBER_OF_RANGE_RATES; i++) {

                    range_rate_vector[i]       = range_rate_vector_double[i];
                    rate_uncertainty_vector[i] = rate_uncertainty_vector_double[i];
                }

            }

            LCA_TOPIC("Tracking::Plot", 2, 0);
        };

    }
}
#endif