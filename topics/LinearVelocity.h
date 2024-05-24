#ifndef LINEAR_VELOCITY_H
#define LINEAR_VELOCITY_H

#include "SIMeterPerSecond.h"
#include "Fabric/Utils/LCA_Macros.h"
#include <string>

namespace Topics 
{
    struct LinearVelocity
    {
        SI::SIMeterPerSecond linearVelocityX{0.0};
        SI::SIMeterPerSecond linearVelocityY{0.0};
        SI::SIMeterPerSecond linearVelocityZ{0.0};

        LinearVelocity() {};

        template <class T>
        void Serialise(T& archive) 
        {
            double velocityX {linearVelocityX()};
            double velocityY {linearVelocityY()};
            double velocityZ {linearVelocityZ()};

            archive.Serialise(velocityX, "linearVelocityX");
            archive.Serialise(velocityY, "linearVelocityY");
            archive.Serialise(velocityZ, "linearVelocityZ");

            linearVelocityX = velocityX;
            linearVelocityY = velocityY;
            linearVelocityZ = velocityZ;
        }

        LCA_TOPIC("LinearVelocity", 1, 0)
    };
}  // namespace Topics

#endif
