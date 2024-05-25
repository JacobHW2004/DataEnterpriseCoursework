#ifndef TRACK_TASK_QUALITY_REPORT_REQUEST_RESPONSE_H
#define TRACK_TASK_QUALITY_REPORT_REQUEST_RESPONSE_H

#include <chrono>
#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"
#include "TrackTaskQualityReport.h"

namespace Topics {
    
    struct TrackTaskQualityReportRequestResponse
    {
        std::chrono::system_clock::time_point timepointRequest{ std::chrono::system_clock::duration::zero() };
        Topics::TrackTaskQualityReport trackTaskQualityReportResponse{};

        template <typename T>
        void Serialise (T& archive) {
           
            std::uint64_t timeSinceEpoch{ static_cast<std::uint64_t>(timepointRequest.time_since_epoch().count()) };

            archive.Serialise(timeSinceEpoch, "timepointRequest");
            archive.Serialise(trackTaskQualityReportResponse, "trackTaskQualityReportResponse");

            std::chrono::system_clock::duration const durationSinceLastEpoch(timeSinceEpoch);
            std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch);
            timepointRequest = timePointSinceLastEpoch;
        }

        LCA_TOPIC("TrackTaskQualityReportRequestResponse", 1, 0)
    };

}

#endif