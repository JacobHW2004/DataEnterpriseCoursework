#ifndef ALERT_COND_ERROR_H
#define ALERT_COND_ERROR_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
    /**
    * @brief Topic representation of RDRS-F-ALERT-CMD-ERROR
    */
    struct AlertCondError
    {
        bool RDRS_F_ALERT_CMD_ERROR{ false };

        template <class T>
        void Serialise(T& archive)
        {
            archive.Serialise(RDRS_F_ALERT_CMD_ERROR, "RDRS_F_ALERT_CMD_ERROR");
        }

        LCA_TOPIC("AlertCondError", 1, 0);
    };
}

#endif