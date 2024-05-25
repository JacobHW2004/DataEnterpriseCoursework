#ifndef TRACKING_CONFIGURATION_OPTIONS_H
#define TRACKING_CONFIGURATION_OPTIONS_H

namespace Tracking {
    namespace Config {

        enum class TrackClustering {
            enable  = 0,
            disable = 1
        };

        enum class CorrelationThreshold {
            normal = 0,
            large  = 1
        };

        enum class ManoeuvreDetection {
            enable  = 0,
            disable = 1
        };

        enum class ProcessNoiseLevel {
            normal = 0,
            medium = 1,
            large  = 2
        };

        enum class ForceUpdateWithoutRR {
            disable = 0,
            enable  = 1
        };

        enum class GroundMoversCanUpdate {
            enable  = 0,
            disable = 1
        };

        enum class ForceSingleStageUpdate {
            disable = 0,
            enable  = 1
        };

        enum class QualityBasedDeletion {
            enable  = 0,
            disable = 1
        };

        enum class OverrideAOTrackDeletionTimeout {
            disable = 0,
            enable  = 1
        };

        enum class FilterType {
            EKF = 0,
            UKF = 1
        };

        enum class RangeVarianceTransitionThreshold {
            no_transitions = 0,
            at_9e2         = 1,
            at_4_5e3       = 2,
            at_9e3         = 3,
            at_13_5e3      = 4,
            at_9e4         = 5
        };

        enum class EarthType {
            flat_earth = 0,
            full_earth  = 1
        };

        enum class Wgs84 {
            disable = 0,
            enable = 1
        };
    }
}

#endif