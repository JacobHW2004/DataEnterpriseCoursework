#ifndef TRACK_TASK_QUALITY_H
#define TRACK_TASK_QUALITY_H

#include <string>
#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"
#include "TrackQualityRadius.h"

namespace Topics {

/** @brief This topic class provides the quality parameters for a given track task */
class TrackTaskQuality {
public:
     
    /** The Identifier for this track.*/
    std::int32_t trackId{0};
    
    /** Reporting parameters stored within TrackQualityRadius topic */    
    Topics::TrackQualityRadius trackQualityValues{};

    /**
    * @brief Topic Constructor with parameters
    */
    TrackTaskQuality(std::int32_t aTrackId, SI::SIMeter aXRadiusPosition, SI::SIMeter aZRadiusPosition, SI::SIMeterPerSecond aXRadiusVelocity, SI::SIMeterPerSecond aZRadiusVelocity) :
            trackId{aTrackId},
            trackQualityValues{aXRadiusPosition, aZRadiusPosition, aXRadiusVelocity, aZRadiusVelocity}
        {};

    /**
    * @brief Default constructor
    */
    TrackTaskQuality() :
        trackId{0},
        trackQualityValues{}
    {};

   /** @brief Serialise function required for communications. */
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(trackId, "trackId");
        archive.Serialise(trackQualityValues, "trackQualityValues");
    }

    LCA_TOPIC("TrackTaskQuality", 1, 0)
 
};

}  // namespace Topics

#endif