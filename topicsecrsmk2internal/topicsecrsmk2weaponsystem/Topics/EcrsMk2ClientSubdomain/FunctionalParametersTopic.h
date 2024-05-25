#ifndef FUNCTIONALPARAMETERSTOPIC_H
#define FUNCTIONALPARAMETERSTOPIC_H

#include "Fabric/Utils/LCA_Macros.h"


namespace Topics {


    /**
    * @brief this topic is a strongly typed one to one partial mapping of Functional Parameters from Radar Status 2
    * This is currently an MVP solution to allow integration with the Weapon System Simulator and not all fields are included
    */
    struct FunctionalParametersTopic {

        uint8_t RDRC_F_PRIM_STATE_CMD {0};
        uint8_t RDRC_F_LIQUID_COOLING {0};
        uint8_t RDRC_F_PPM_OVRD {0};
        uint8_t RDRC_F_PPM_NEW_VALUE {0};
        uint8_t RDRC_F_PPM_VALUE {0};
        uint8_t RDRC_F_RDR_RECONFIG_PERMITTED {0};
        uint8_t RDRC_F_SEU_RECOVERY_PERMITTED {0};

        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {
        archive.Serialise( RDRC_F_PRIM_STATE_CMD, "RDRC_F_PRIM_STATE_CMD");
        archive.Serialise( RDRC_F_LIQUID_COOLING, "RDRC_F_LIQUID_COOLING");
        archive.Serialise( RDRC_F_PPM_OVRD, "RDRC_F_PPM_OVRD");
        archive.Serialise( RDRC_F_PPM_NEW_VALUE, "RDRC_F_PPM_NEW_VALUE");
        archive.Serialise( RDRC_F_PPM_VALUE, "RDRC_F_PPM_VALUE");
        archive.Serialise( RDRC_F_RDR_RECONFIG_PERMITTED, "RDRC_F_RDR_RECONFIG_PERMITTED");
        archive.Serialise( RDRC_F_SEU_RECOVERY_PERMITTED, "RDRC_F_SEU_RECOVERY_PERMITTED");           
        }

    LCA_TOPIC("FunctionalParametersTopic", 1, 0)

    };

}  // namespace Topics

#endif