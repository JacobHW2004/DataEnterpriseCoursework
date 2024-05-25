#ifndef LRI_BLOCK_H
#define LRI_BLOCK_H

#include "LRIEnums.h"

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics {
    
    struct LRIBlock
    {
        LRI_NO_ENUM LRI_NO{};

        float LRI_ETI{};

        std::uint8_t LRI_REPORT_COUNT{};

        LRI_DATABUS_IDENT_EMUM LRI_DATABUS_IDENT{};

        SRI_LRI_IDENTIFIER_ENUM SRI_LRI_INDENTIFIER{};

        std::uint16_t LRI_SERIAL_NUMBER{};

        LRI_HW_IDENTIFICATION_ENUM LRI_HW_IDENTIFICATION{};

        std::uint16_t LRI_HW_VERSION{};

        std::uint16_t LRI_SW_VERSION_1 {};    
        
        std::uint16_t LRI_SW_VERSION_2 {};

        template <class T>
        void Serialise(T& archive) {

            // System Block
            archive.Serialise(LRI_NO, "LRI_NO");
            archive.Serialise(LRI_ETI, "LRI_ETI");
            archive.Serialise(LRI_REPORT_COUNT, "LRI_REPORT_COUNT");
            archive.Serialise(LRI_DATABUS_IDENT, "LRI_DATABUS_IDENT");
            archive.Serialise(SRI_LRI_INDENTIFIER, "SRI_LRI_INDENTIFIER");
            archive.Serialise(LRI_SERIAL_NUMBER, "LRI_SERIAL_NUMBER");
            archive.Serialise(LRI_HW_IDENTIFICATION, "LRI_HW_IDENTIFICATION");
            archive.Serialise(LRI_HW_VERSION, "LRI_HW_VERSION");
            archive.Serialise(LRI_SW_VERSION_1, "LRI_SW_VERSION_1");
            archive.Serialise(LRI_SW_VERSION_2, "LRI_SW_VERSION_2");
        }

        LCA_TOPIC("RadarSummaryConfigData", 1, 0);
    };
}

#endif