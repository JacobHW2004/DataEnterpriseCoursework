#ifndef RADAR_CONTROL_CIU_MESSAGE_TOPIC_H
#define RADAR_CONTROL_CIU_MESSAGE_TOPIC_H


#include <string>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    struct RadarControlCIUMessageTopic {


        uint16_t CIU18_RADAR_HAV_STATTAG;

        uint8_t CIU18_RADAR_HAV_DYNTAG;

        uint8_t INT_CRYPTO_ERASE_DMD;

        uint8_t AI_SECURE_DATA_ERASE_DMD;

        uint8_t RADAR_THERMAL_OVRD_SELC;

        uint8_t IFF_INT_ON_OFF;

        uint8_t PBIT_TYPE_REQUEST;

        uint8_t FAST_RESP_PBIT;

        uint8_t IBIT_REQUEST_IN_AIR;

        uint8_t BELOW_CP_OVRD_SELC;

        uint8_t ANT_RESET_CMD;

        uint8_t AAU_RESET_CMD;

        uint8_t APSC_RESET_CMD;

        uint8_t RECEIVER_RESET_CMD;

        uint8_t SHUTDOWN_CMD;

        uint8_t GAMMA_TABLE_UPDATE_COUNT;

        // Won't serialize but we don't care for now
        uint16_t VIDEO_ENCODE_LEVEL_X[128];

        /**
        * @brief Serialise function required for communications
        * @todo serialise the fields in this topic.
        */
        template <class T>
        void Serialise(T& archive){
            archive.Serialise(CIU18_RADAR_HAV_STATTAG, "CIU18_RADAR_HAV_STATTAG");
            archive.Serialise(CIU18_RADAR_HAV_DYNTAG, "CIU18_RADAR_HAV_DYNTAG");
            archive.Serialise(INT_CRYPTO_ERASE_DMD, "INT_CRYPTO_ERASE_DMD");
            archive.Serialise(AI_SECURE_DATA_ERASE_DMD, "AI_SECURE_DATA_ERASE_DMD");
            archive.Serialise(RADAR_THERMAL_OVRD_SELC, "RADAR_THERMAL_OVRD_SELC");
            archive.Serialise(IFF_INT_ON_OFF, "IFF_INT_ON_OFF");
            archive.Serialise(PBIT_TYPE_REQUEST, "PBIT_TYPE_REQUEST");
            archive.Serialise(FAST_RESP_PBIT, "FAST_RESP_PBIT");
            archive.Serialise(IBIT_REQUEST_IN_AIR, "IBIT_REQUEST_IN_AIR");
            archive.Serialise(BELOW_CP_OVRD_SELC, "BELOW_CP_OVRD_SELC");
            archive.Serialise(ANT_RESET_CMD, "ANT_RESET_CMD");
            archive.Serialise(AAU_RESET_CMD, "AAU_RESET_CMD");
            archive.Serialise(APSC_RESET_CMD, "APSC_RESET_CMD");
            archive.Serialise(RECEIVER_RESET_CMD, "RECEIVER_RESET_CMD");
            archive.Serialise(SHUTDOWN_CMD, "SHUTDOWN_CMD");
            archive.Serialise(GAMMA_TABLE_UPDATE_COUNT, "GAMMA_TABLE_UPDATE_COUNT");
        }

        LCA_TOPIC("RadarControlCIUMessageTopic", 1, 0)


    };

}  // namespace Topics

#endif