#ifndef FRAMECOUNTTOPIC_H
#define FRAMECOUNTTOPIC_H

#include "Fabric/Utils/LCA_Macros.h"

#include <cstdint>

namespace Topics {

class FrameCountTopic {
public:

    std::int32_t internalTaskID{0};
    int frameCount {0};

    FrameCountTopic() {};
   /**
   * @brief Topic constructor with parameters
   */
    FrameCountTopic(int aInternalTaskID, int aFrameCount) :
        internalTaskID(aInternalTaskID),
        frameCount(aFrameCount){};
    
    /**
    * @brief Serialise function required for communications
    */
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(internalTaskID, "internalTaskID");
        archive.Serialise(frameCount, "frameCount");
    }

    LCA_TOPIC("FrameCountTopic", 1, 0)

};

}  // namespace Topics

#endif
