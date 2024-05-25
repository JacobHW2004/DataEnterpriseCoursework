#ifndef UPDATING_TARGET_TYPE_H
#define UPDATING_TARGET_TYPE_H

#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    enum class UpdatingTargetType : uint8_t {
        ECHO = 0,
        EMITTER = 1,
    };

}

#endif