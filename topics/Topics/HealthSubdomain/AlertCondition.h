#ifndef ALERT_CONDITION_H
#define ALERT_CONDITION_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
    struct AlertCondition
    {
        bool alertCondition{ false };

        template <class T>
        void Serialise(T& archive)
        {
            archive.Serialise(alertCondition, "alertCondition");
        }

        LCA_TOPIC("AlertCondition", 1, 0);
    };
}

#endif