#ifndef APSC_OP_COMMAND_H
#define APSC_OP_COMMAND_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
    struct APSCOperationalCommand
    {
		// Pertains to an "ASPC alert condition" (true=asserted, false=de-asserted)
        bool ALERT_POWER{ false };
		
        template <class T>
        void Serialise(T& archive)
        {
            archive.Serialise(ALERT_POWER, "ALERT_POWER");
        }

        LCA_TOPIC("APSCOperationalCommand", 1, 0);
    };
}

#endif