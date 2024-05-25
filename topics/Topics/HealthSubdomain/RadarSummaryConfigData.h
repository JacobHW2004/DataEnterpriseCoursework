#ifndef RADAR_SUMMARY_CONFIG_DATA_H
#define RADAR_SUMMARY_CONFIG_DATA_H

#include "LRIBlock.h"
#include "LRIEnums.h"

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics {
    struct RadarSummaryConfigData
    {
        //System Block 

        std::uint8_t PROC_RT_ADDRESS{};

        LRI_DATABUS_IDENT_EMUM LRI_DATABUS_IDENT{};
        
        SRI_LRI_IDENTIFIER_ENUM SRI_LRI_INDENTIFIER{};

        float LRI_ETI{};

        std::uint8_t SYS_REPORT_COUNT{};

        std::uint16_t LRI_SERIAL_NUMBER{};

        LRI_HW_IDENTIFICATION_ENUM LRI_HW_IDENTIFICATION{}; 

        std::uint16_t LRI_HW_VERSION{};

        std::uint16_t LRI_SW_VERSION_1 {};    
        
        std::uint16_t LRI_SW_VERSION_2 {};

        // Processor Block
        LRIBlock PROCESSOR;

        // AAU Block 
        LRIBlock AAU; 

        // APSC Block
        LRIBlock APSC; 

        // Receiver Block
        LRIBlock RECEIVER;

        // Antenna Block 
        LRIBlock ANTENNA; 

        template <class T>
        void Serialise(T& archive) {

            archive.Serialise(PROC_RT_ADDRESS, "PROC_RT_ADDRESS");
            archive.Serialise(LRI_DATABUS_IDENT, "LRI_DATABUS_IDENT");
            archive.Serialise(SRI_LRI_INDENTIFIER, "SRI_LRI_INDENTIFIER");
            archive.Serialise(LRI_ETI, "LRI_ETI");
            archive.Serialise(SYS_REPORT_COUNT, "SYS_REPORT_COUNT");
            archive.Serialise(LRI_SERIAL_NUMBER, "LRI_SERIAL_NUMBER");
            archive.Serialise(LRI_HW_IDENTIFICATION, "LRI_HW_IDENTIFICATION");
            archive.Serialise(LRI_HW_VERSION, "LRI_HW_VERSION");
            archive.Serialise(LRI_SW_VERSION_1, "LRI_SW_VERSION_1");
            archive.Serialise(LRI_SW_VERSION_2, "LRI_SW_VERSION_2");
            archive.Serialise(PROCESSOR, "PROCESSOR");
            archive.Serialise(AAU, "AAU");
            archive.Serialise(APSC, "APSC");
            archive.Serialise(RECEIVER, "RECEIVER");
            archive.Serialise(ANTENNA, "ANTENNA");
        }

        LCA_TOPIC("RadarSummaryConfigData", 1, 0);
    };
}

#endif