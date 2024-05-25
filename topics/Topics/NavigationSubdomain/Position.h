#ifndef POSITION_H
#define POSITION_H

#include "Fabric/Utils/LCA_Macros.h"
#include "FrameOfReference.h"
#include "SIMeter.h"

namespace Topics {
    struct Position
    {
        SI::SIMeter positionX{0.0};
        SI::SIMeter positionY{0.0};
        SI::SIMeter positionZ{0.0};
        FrameOfReference frameOfReference{ FrameOfReference::FRAME_1 };

        Position() = default;

        Position(const FrameOfReference& aFrameOfReference) :
            positionX(0.0),
            positionY(0.0),
            positionZ(0.0),
            frameOfReference(aFrameOfReference)
        {}

        Position(const SI::SIMeter& aPositionX, const SI::SIMeter& aPositionY, const SI::SIMeter& aPositionZ, const FrameOfReference& aFrameOfReference) :
            positionX(aPositionX),
            positionY(aPositionY),
            positionZ(aPositionZ),
            frameOfReference(aFrameOfReference)
        {}

        bool operator==(const Position& other) const
        {
            return (frameOfReference == other.frameOfReference &&
                      positionX() == other.positionX() &&
                      positionY() == other.positionY() &&
                      positionZ() == other.positionZ());
        }

        template <class T>
        void Serialise(T& archive) 
        {
            double posX {positionX()};
            double posY {positionY()};
            double posZ {positionZ()};

            archive.Serialise(posX, "positionX");
            archive.Serialise(posY, "positionY");
            archive.Serialise(posZ, "positionZ");
            archive.Serialise(frameOfReference, "frameOfReference");

            positionX = posX;
            positionY = posY;
            positionZ = posZ;

        }

        LCA_TOPIC("Position", 1, 0)
    };
}  // namespace Topics

#endif