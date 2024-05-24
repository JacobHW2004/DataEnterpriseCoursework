#ifndef SEARCH_QUALITY_REPORT_REQUEST_RESPONSE
#define SEARCH_QUALITY_REPORT_REQUEST_RESPONSE

#include <string>
#include <chrono>
#include "Fabric/Utils/LCA_Macros.h"
#include "SearchQualityReport.h"

namespace Topics {

/**
* @brief Topic provides a report of search qualities at a given window end point.
*
*/
struct SearchQualityReportRequestResponse {

    
    std::chrono::system_clock::time_point windowEndPointRequest{ std::chrono::system_clock::duration::zero() };
    Topics::SearchQualityReport searchQualityReportResponse {};

    /**
    * @brief Serialise function required for communications
    */
    template <class T>
    void Serialise(T& archive) {

        uint64_t timeSinceEpoch{ static_cast<uint64_t>(windowEndPointRequest.time_since_epoch().count()) };

        archive.Serialise(timeSinceEpoch, "windowEndPointRequest");
        archive.Serialise(searchQualityReportResponse, "searchQualityReportResponse");

        std::chrono::system_clock::duration const durationSinceLastEpoch(timeSinceEpoch);
        std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch);
        windowEndPointRequest = timePointSinceLastEpoch;
    }

    LCA_TOPIC("SearchQualityReportRequestResponse", 1, 0)
 
};

}  // namespace Topics

#endif
