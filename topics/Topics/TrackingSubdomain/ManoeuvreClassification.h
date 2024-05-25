#ifndef MANOEUVRE_CLASSIFICATION_H
#define MANOEUVRE_CLASSIFICATION_H

#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    enum class ManoeuvreClassification : uint8_t {
        NO_MANOEUVRE        = 0,
        POTENTIAL_MANOEUVRE = 1,
        CONFIRMED_MANOEUVRE = 2
    };

}

#endif