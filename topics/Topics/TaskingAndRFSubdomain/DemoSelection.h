#ifndef DEMO_SELECTION_H
#define DEMO_SELECTION_H

#include "Fabric/Utils/LCA_Macros.h"


#include <cstdint>

namespace Topics {

    struct DemoSelection {

        std::int32_t demoNumber{ 0 };

        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(demoNumber, "demoNumber");
        }

        LCA_TOPIC("DemoSelection", 1, 0)

    };

}  // namespace Topics

#endif