#ifndef SUMMARY_CONFIGURATION_DATA_H
#define SUMMARY_CONFIGURATION_DATA_H

#include "LRIEnums.h"

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics {
    struct SummaryConfigurationData
    {
        LRI_HW_IDENTIFICATION_ENUM lriType{};
        
        float ETI{};

        std::uint8_t REPORT_COUNT{};

        std::uint16_t SERIAL_NUMBER{};

        std::uint32_t HW_PART_NO{};

        std::uint8_t HW_PART_NO_BUILD_STATE{};

        std::uint32_t SW_PART_NO{};

        std::uint8_t SW_PART_NO_VERSION{};

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(lriType, "lriType");
            archive.Serialise(ETI, "ETI");
            archive.Serialise(REPORT_COUNT, "REPORT_COUNT");
            archive.Serialise(SERIAL_NUMBER, "SERIAL_NUMBER");
            archive.Serialise(HW_PART_NO, "HW_PART_NO");
            archive.Serialise(HW_PART_NO_BUILD_STATE, "HW_PART_NO_BUILD_STATE");
            archive.Serialise(SW_PART_NO, "SW_PART_NO");
            archive.Serialise(SW_PART_NO_VERSION, "SW_PART_NO_VERSION");
        }

        LCA_TOPIC("SummaryConfigurationData", 1, 0);
    };
}

#endif