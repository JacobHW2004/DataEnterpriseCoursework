#ifndef WEIGHT_ON_WHEELS_H
#define WEIGHT_ON_WHEELS_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
    struct WeightOnWheels
    {
		// If true, the plane should be on the ground, if false, in the air
        bool wowInput{ true };
		
        template <class T>
        void Serialise(T& archive)
        {
            archive.Serialise(wowInput, "wowInput");
        }

        LCA_TOPIC("weightOnWheels", 1, 0);
    };
}

#endif