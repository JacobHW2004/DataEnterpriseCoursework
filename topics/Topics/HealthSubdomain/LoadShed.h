#ifndef LOAD_SHED_H
#define LOAD_SHED_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
    struct LoadShed
    {
		/*Explanation added for clarity
		* TRUE = Load Shed {Open Circuit: Reduced Power is demanded}
		* FALSE = De-assertion of Load Shed (Short circuit: Reduced power is not demanded)
		*/
        bool loadShedInput{ true };

        template <class T>
        void Serialise(T& archive)
        {
            archive.Serialise(loadShedInput, "loadShedInput");
        }

        LCA_TOPIC("LoadShed", 1, 0);
    };
}

#endif