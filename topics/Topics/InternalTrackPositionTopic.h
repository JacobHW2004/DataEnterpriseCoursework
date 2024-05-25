#ifndef INTERNALTRACKPOSITIONTOPIC_H
#define INTERNALTRACKPOSITIONTOPIC_H

#include <vector>
#include <string>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

/**
* @brief This topic class provides track information   
* This topic is based upon the topic InternalTrackPositionTopic from the RRA repo.
*/
class InternalTrackPositionTopic {
public:
    double                  azimuth{ 0.0 };
    double                  azimuthError{ 0.0 };
    double                  elevation{ 0.0 };
    double                  elevationError{ 0.0 };
    double                  range{ 0.0 };
    double                  rangeError{ 0.0 };
    uint64_t                timestamp{ 0 };
    uint64_t                timestampHighAccuracy{ 0 };
    uint32_t                uniqueReferenceNumber{ 0 }; 
    std::vector<uint32_t>   contributingTaskURNs;  //Unique Reference Number abbreviated to URN

    template <class T>
    void Serialise(T& archive)
    {    
        archive.Serialise(azimuth,                          "azimuth"                       );
        archive.Serialise(azimuthError,                     "azimuthError"                  );
        archive.Serialise(elevation,                        "elevation"                     );
        archive.Serialise(elevationError,                   "elevationError"                );
        archive.Serialise(range,                            "range"                         );
        archive.Serialise(rangeError,                       "rangeError"                    );
        archive.Serialise(timestampHighAccuracy,            "timestampHighAccuracy"         );
        archive.Serialise(timestamp,                        "timestamp"                     );
        archive.Serialise(uniqueReferenceNumber,            "uniqueReferenceNumber"         );
        archive.Serialise(contributingTaskURNs,             "contributingTaskURN",  "ContributingTaskURNs");
    }

    LCA_TOPIC("InternalTrackPositionTopic", 1, 0)
};

}  // namespace Topics

#endif // #ifndef TOPIC_InternalTrackPosition_TOPIC_H_
