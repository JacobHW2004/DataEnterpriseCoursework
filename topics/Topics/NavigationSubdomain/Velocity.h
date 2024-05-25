#ifndef VELOCITY_H
#define VELOCITY_H

#include "Fabric/Utils/LCA_Macros.h"
#include "FrameOfReference.h"
#include "SIMeterPerSecond.h"

namespace Topics
{

    struct Velocity
    {

        /**
         * @brief topic used to describe a velocity in x, y, z as well as a frame of reference
         */

        SI::SIMeterPerSecond velocityX{0.0};
        SI::SIMeterPerSecond velocityY{0.0};
        SI::SIMeterPerSecond velocityZ{0.0};
        FrameOfReference frameOfReference{ FrameOfReference::FRAME_1 };

        Velocity() = default;     //maintaining the default constructor

        Velocity(const FrameOfReference& aFrameOfReference) :
            velocityX(0.0),
            velocityY(0.0), 
            velocityZ(0.0),
            frameOfReference(aFrameOfReference)
        {}

        Velocity(const SI::SIMeterPerSecond& aVelocityX, const SI::SIMeterPerSecond& aVelocityY, const SI::SIMeterPerSecond& aVelocityZ, const FrameOfReference& aFrameOfReference) :
            velocityX(aVelocityX),
            velocityY(aVelocityY), 
            velocityZ(aVelocityZ),
            frameOfReference(aFrameOfReference)
        {}

        bool operator==(const Velocity& other) const
        {
            return (frameOfReference == other.frameOfReference && 
                    velocityX() == other.velocityX() &&
                    velocityY() == other.velocityY() &&
                    velocityZ() == other.velocityZ());
        }

        template <class T>
        void Serialise(T& archive) 
        {
            double velX {velocityX()};
            double velY {velocityY()};
            double velZ {velocityZ()};

            archive.Serialise(velX, "velocityX");
            archive.Serialise(velY, "velocityY");
            archive.Serialise(velZ, "velocityZ");
            archive.Serialise(frameOfReference, "frameOfReference");

            //Following required for setting up values after deserialisation
            velocityX = velX;
            velocityY = velY;
            velocityZ = velZ;
        }

        LCA_TOPIC("Velocity", 1, 0)



    };

}       //End namespace Topics

#endif