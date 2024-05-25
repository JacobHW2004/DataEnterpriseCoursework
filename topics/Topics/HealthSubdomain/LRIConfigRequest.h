#ifndef LRI_CONFIG_REQUEST_H
#define LRI_CONFIG_REQUEST_H

#include "LRIEnums.h"

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics {

    enum ConfigRequestDataType
    {
        SUMMARY_CONFIGURATION_DATA
    };

    struct LRIConfigRequest
    {
        LRI_HW_IDENTIFICATION_ENUM lriType{};
        ConfigRequestDataType DATA_TYPE_REQUEST{};

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(lriType, "lriType");
            archive.Serialise(DATA_TYPE_REQUEST, "DATA_TYPE_REQUEST");
        }

        LCA_TOPIC("LRIConfigRequest", 1, 0);
    };
}

#endif