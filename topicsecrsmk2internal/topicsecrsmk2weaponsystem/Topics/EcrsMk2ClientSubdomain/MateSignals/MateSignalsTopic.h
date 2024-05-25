#ifndef MATESIGNALSTOPIC_H
#define MATESIGNALSTOPIC_H

#include "Fabric/Utils/LCA_Macros.h"


namespace Topics {


    /**
    * @brief this topic holds messages intended to communicate with BAES Weapon System Sim in the MaTE environment
    */
    struct MateSignalsTopic {

        bool ATK_09_ENABLE {false};
        bool ATK_09_EN_WRAP {false};
        bool ATK_09_EN_DYNAMIC_SIGNALS {false};
        bool RADAR_OFF_OPERATE_HW {false};

        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {
        archive.Serialise( ATK_09_ENABLE, "ATK_09_ENABLE");
        archive.Serialise( ATK_09_EN_WRAP, "ATK_09_EN_WRAP");
        archive.Serialise( ATK_09_EN_DYNAMIC_SIGNALS, "ATK_09_EN_DYNAMIC_SIGNALS");   
        archive.Serialise( RADAR_OFF_OPERATE_HW, "RADAR_OFF_OPERATE_HW");         
        }

    LCA_TOPIC("MateSignalsTopic", 1, 0)

    };

}  // namespace Topics

#endif