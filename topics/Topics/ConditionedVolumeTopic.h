#ifndef CONDITIONED_VOLUME_TOPIC_H
#define CONDITIONED_VOLUME_TOPIC_H

#include <string>
#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"
#include "Volume.h"

namespace Topics {

/**
* @brief This topic class represents a conditioned volume
*
*/
struct ConditionedVolumeTopic {
 
    std::int32_t internalTaskID{0};
    Volume aVolume{};
    float percentageOfDemandedVolume{0.0f};

    
   /**
    * @brief Serialise function required for communications
    */
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(internalTaskID, "internalTaskID");
        archive.Serialise(aVolume, "aVolume");
        archive.Serialise(percentageOfDemandedVolume, "percentageOfDemandedVolume");
    }

    LCA_TOPIC("ConditionedVolumeTopic", 1 , 0)
 
};

}  // namespace Topics

#endif