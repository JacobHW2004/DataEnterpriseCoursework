#ifndef SEARCHQUALITY_H
#define SEARCHQUALITY_H

#include <string>
#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

/** @brief This topic class provides a report of the acheived search task quality */
class SearchQuality {
public:
     
    /** The unique Identifier for this internal task.*/
    std::int32_t internalTaskID{0};
    
    /** Represents the achieved quality to the nearest percentage.*/    
    double quality{0.0};
    
   /** @brief Serialise function required for communications. */
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(internalTaskID, "internalTaskID");
        archive.Serialise(quality, "quality");
    }

    LCA_TOPIC("SearchQuality", 1, 0)

 
};

}  // namespace Topics

#endif