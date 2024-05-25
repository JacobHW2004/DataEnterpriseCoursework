#ifndef REPLAY_SUPPORT_TRACK_HISTORY
#define REPLAY_SUPPORT_TRACK_HISTORY
#include <cstdint>
#include <vector>

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {
    namespace TrackingDomainReplaySupport {

        class ReplaySupport_TrackHistory {
        public:

            std::uint8_t history_based_track_type{ 0 };
            std::uint8_t history_update_count{ 0 };
            std::vector <std::uint8_t> history_of_updates{}; // length 5
            std::uint8_t stored_range_rate_count{ 0 };
            std::vector<double> stored_updating_range_rates{}; // length 5

            ReplaySupport_TrackHistory() = default;

            ReplaySupport_TrackHistory(
                std::uint8_t history_based_track_type,
                std::uint8_t history_update_count,
                const std::vector<std::uint8_t>& history_of_updates,
                std::uint8_t stored_range_rate_count,
                const std::vector<double>& stored_updating_range_rates)

            : history_based_track_type(history_based_track_type),
              history_update_count(history_update_count),
              history_of_updates(history_of_updates),
              stored_range_rate_count(stored_range_rate_count),
              stored_updating_range_rates(stored_updating_range_rates)

            {}

            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(history_based_track_type, "history_based_track_type");
                archive.Serialise(history_update_count, "history_update_count");
                archive.Serialise(history_of_updates, "update", "history_of_updates");
                archive.Serialise(stored_range_rate_count, "stored_range_rate_count");
                archive.Serialise(stored_updating_range_rates, "range_rate", "stored_updating_range_rates");
            }

            LCA_TOPIC("ReplaySupport_TrackHistory", 1, 0);
        };
    }

}

#endif