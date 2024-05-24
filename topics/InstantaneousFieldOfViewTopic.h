#ifndef INSTANTANEOUS_FIELD_OF_VIEW_H
#define INSTANTANEOUS_FIELD_OF_VIEW_H

#include "FieldOfView.h"
#include "Fabric/Utils/LCA_Macros.h"
#include <string>
#include <vector>

namespace Topics {

/**
* @brief This topic class provides the radar field of view as an ellipse
*/
struct InstantaneousFieldOfViewTopic {
public:

    FieldOfView aFieldofView{0.f,0.f,0.f,0.f};

   /**
    * @brief Serialise function required for communications
    */
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(aFieldofView, "aFieldofView");
    }

    LCA_TOPIC("InstantaneousFieldOfViewTopic", 1, 0)

};

}  // namespace Topics

#endif
