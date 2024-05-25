#ifndef ALERT_MESSAGE_H
#define ALERT_MESSAGE_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
    struct AlertMessage
    {
        bool alertInput{ false };

        template <class T>
        void Serialise(T& archive)
        {
            archive.Serialise(alertInput, "alertInput");
        }

        LCA_TOPIC("AlertMessage", 1, 0);
    };
}

#endif