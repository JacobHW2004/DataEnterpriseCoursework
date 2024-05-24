#ifndef DEMANDEDVOLUMETOPIC_H
#define DEMANDEDVOLUMETOPIC_H

#include <cstdint>
#include <string>
#include "Fabric/Utils/LCA_Macros.h"
#include "Volume.h"
#include "FrameOfReference.h"
#include "SIRadian.h"

namespace Topics {
    
struct DemandedVolumeTopic {

    std::int32_t internalTaskID{0};
    Volume aVolume{};
    FrameOfReference frameOfReference {FrameOfReference::FRAME_2};

    /**
    * @brief Serialise function required for communications
    */
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(internalTaskID, "internalTaskID");
        archive.Serialise(frameOfReference, "frameOfReference");
        archive.Serialise(aVolume, "aVolume");
    }

    LCA_TOPIC("DemandedVolumeTopic", 1, 0)

};

}  // namespace Topics

#endif