#ifndef TRACK_TASK_QUALITY_REPORT_H
#define TRACK_TASK_QUALITY_REPORT_H

#include <string>
#include <vector>
#include "Fabric/Utils/LCA_Macros.h"
#include "TrackTaskQuality.h"

namespace Topics {

/** @brief This topic class provides a report of track task qualities */
class TrackTaskQualityReport {
public:
     
    /** @brief Contains a list of track task qualities.*/
    std::vector<TrackTaskQuality> trackTaskQualities{};

    /**
    * @brief Topic Constructor with parameters
    */
    TrackTaskQualityReport(std::vector<TrackTaskQuality> aTrackQualities) :
        trackTaskQualities{aTrackQualities}
    {};

    /**
    * @brief Default constructor
    */
    TrackTaskQualityReport() noexcept:
        trackTaskQualities{}
    {};
    
    /** @brief Serialise function required for communications. */
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(trackTaskQualities,"TrackTaskQuality", "TrackTaskQualities");
    }

    LCA_TOPIC("TrackTaskQualityReport", 1, 0)

 
};

}  // namespace Topics

#endif