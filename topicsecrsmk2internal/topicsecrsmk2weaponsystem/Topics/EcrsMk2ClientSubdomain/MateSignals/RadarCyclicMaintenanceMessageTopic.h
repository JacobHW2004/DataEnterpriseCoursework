#ifndef RADARCYCLICMAINTENANCEMESSAGETOPIC_H
#define RADARCYCLICMAINTENANCEMESSAGETOPIC_H

#include "Fabric/Utils/LCA_Macros.h"


namespace Topics {


    /**
    * @brief this topic is a strongly typed one to one partial mapping of Functional Parameters from Radar Status 2
    * This is currently an MVP solution to allow integration with the Weapon System Simulator and not all fields are included
    */
    struct RadarCyclicMaintenanceMessageTopic {

        uint8_t RADAR29_IPU_HAT_STATTAG {0};
        uint8_t RADAR29_IPU_HAT_DYNTAG {0};
        uint8_t E_ASPC_RDR_LIVE_STATUS {0};
        uint8_t RADAR_HEALTHFILE_DOWNLOAD_STATUS {0};
        uint8_t RADAR_LIVE_RT_STATUS_IMPLTD {0};
        uint8_t RADAR_MSCAN_ESCAN_STANDARD {0};

        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {
        archive.Serialise( RADAR29_IPU_HAT_STATTAG, "RADAR29_IPU_HAT_STATTAG");
        archive.Serialise( RADAR29_IPU_HAT_DYNTAG, "RADAR29_IPU_HAT_DYNTAG");
        archive.Serialise( E_ASPC_RDR_LIVE_STATUS, "E_ASPC_RDR_LIVE_STATUS");
        archive.Serialise( RADAR_HEALTHFILE_DOWNLOAD_STATUS, "RADAR_HEALTHFILE_DOWNLOAD_STATUS");
        archive.Serialise( RADAR_LIVE_RT_STATUS_IMPLTD, "RADAR_LIVE_RT_STATUS_IMPLTD");
        archive.Serialise( RADAR_MSCAN_ESCAN_STANDARD, "RADAR_MSCAN_ESCAN_STANDARD");         
        }

    LCA_TOPIC("RadarCyclicMaintenanceMEssageTopic", 1, 0)

    };

}  // namespace Topics

#endif