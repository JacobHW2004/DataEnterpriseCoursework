#ifndef SRI_LRI_INDENTIFIER_H
#define SRI_LRI_INDENTIFIER_H

#include <cstdint>

namespace Topics {
    enum class SRI_LRI_IDENTIFIER_ENUM : uint8_t
    {
        LRI_LEVEL,
        SRI_LEVEL
    };

    enum LRI_HW_IDENTIFICATION_ENUM : uint8_t
    {
        E_SCAN_ANTENNA_RADAR = 0xB1,
        E_SCAN_PROCESSOR_RADAR = 0xB2,
        E_SCAN_AAU_RADAR = 0xB3,
        E_SCAN_APSC_RADAR = 0xB4,
        E_SCAN_RECEIVER_RADAR = 0xB5,
        M_SCAN_SCANNER_RADAR = 0xF2,
        M_SCAN_PROCESSOR_RADAR = 0xF3,
        M_SCAN_TX_AUX_UNIT_RADAR = 0xF4,
        M_SCAN_TX_PWR_AMP_RADAR = 0xF5,
        M_SCAN_RECEIVER_RADAR = 0xF6,
        M_SCAN_WG_UNIT_RADAR = 0xF7
    };

    enum class LRI_NO_ENUM : uint8_t
    {
        RESERVED,
        ITEM_1_ANTENNA_SCANNER,
        ITEM_2_PROCESSOR,
        ITEM_3_TAU_AAU,
        ITEM_4_TPA_APSC,
        ITEM_5_RECEIVER,
        ITEM_6_WGU,
        IFF_INTERROGATOR = 0xB
    };

    enum class LRI_DATABUS_IDENT_EMUM : uint8_t
    {
        ATTACK,
        RADAR
    };

}

#endif