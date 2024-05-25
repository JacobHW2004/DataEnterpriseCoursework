#ifndef TRACKING_CONFIG_DATA_TOPIC_H
#define TRACKING_CONFIG_DATA_TOPIC_H

#include "TrackingConfigurationOptions.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics{
    namespace Tracking{
        struct ConfigData {

            // Enumerated options
            ::Tracking::Config::TrackClustering                  track_clustering               { ::Tracking::Config::TrackClustering::enable };
            ::Tracking::Config::CorrelationThreshold             increase_correlation_threshold { ::Tracking::Config::CorrelationThreshold::normal };
            ::Tracking::Config::ManoeuvreDetection               manoeuvre_detection            { ::Tracking::Config::ManoeuvreDetection::enable };
            ::Tracking::Config::ProcessNoiseLevel                process_noise_level            { ::Tracking::Config::ProcessNoiseLevel::normal };
            ::Tracking::Config::ForceUpdateWithoutRR             force_update_without_rr        { ::Tracking::Config::ForceUpdateWithoutRR::disable };
            ::Tracking::Config::GroundMoversCanUpdate            GM_update                      { ::Tracking::Config::GroundMoversCanUpdate::enable };
            ::Tracking::Config::ForceSingleStageUpdate           force_single_stage_update      { ::Tracking::Config::ForceSingleStageUpdate::disable };
            ::Tracking::Config::QualityBasedDeletion             quality_deletion               { ::Tracking::Config::QualityBasedDeletion::disable };
            ::Tracking::Config::OverrideAOTrackDeletionTimeout   ao_deletion_timeout_override   { ::Tracking::Config::OverrideAOTrackDeletionTimeout::disable };
            ::Tracking::Config::FilterType                       ekf_or_ukf                     { ::Tracking::Config::FilterType::EKF };
            ::Tracking::Config::Wgs84                            wgs84_enable                   { ::Tracking::Config::Wgs84::disable };
            ::Tracking::Config::RangeVarianceTransitionThreshold range_var_threshold_selection  { ::Tracking::Config::RangeVarianceTransitionThreshold::no_transitions };
            ::Tracking::Config::EarthType                        flat_or_full_earth_model       { ::Tracking::Config::EarthType::flat_earth };

            // Continuous-variable options
            double max_acceleration   { 0.0 };
            double max_velocity       { 1000.0 };
            double max_range          { 300000.0 };
            double min_range          { 600.0 };
            double sub_window_size_az { 0.0 };
            double sub_window_size_el { 0.0 };
            
            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(track_clustering              , "track_clustering");
                archive.Serialise(increase_correlation_threshold, "increase_correlation_threshold");
                archive.Serialise(manoeuvre_detection           , "manoeuvre_detection");
                archive.Serialise(process_noise_level           , "process_noise_level");
                archive.Serialise(force_update_without_rr       , "force_update_without_rr");
                archive.Serialise(GM_update                     , "GM_update");
                archive.Serialise(force_single_stage_update     , "force_single_stage_update");
                archive.Serialise(quality_deletion              , "quality_deletion");
                archive.Serialise(ao_deletion_timeout_override  , "ao_deletion_timeout_override");
                archive.Serialise(ekf_or_ukf                    , "ekf_or_ukf");
                archive.Serialise(wgs84_enable                  , "wgs84_enable");
                archive.Serialise(range_var_threshold_selection , "range_var_threshold_selection");
                archive.Serialise(flat_or_full_earth_model      , "flat_or_full_earth_model");
                archive.Serialise(max_acceleration              , "max_acceleration");
                archive.Serialise(max_velocity                  , "max_velocity");
                archive.Serialise(max_range                     , "max_range");
                archive.Serialise(min_range                     , "min_range");
                archive.Serialise(sub_window_size_az            , "sub_window_size_az");
                archive.Serialise(sub_window_size_el            , "sub_window_size_el");
            }

            LCA_TOPIC("Tracking::ConfigData", 1, 0)
        };
    }
}

#endif
