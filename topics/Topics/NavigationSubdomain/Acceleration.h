#ifndef ACCELERATION_H
#define ACCELERATION_H

#include "SIMeterPerSecondSquared.h"
#include "Fabric/Utils/LCA_Macros.h"
#include "FrameOfReference.h"
#include <string>

namespace Topics {
   struct Acceleration
   {
      SI::SIMeterPerSecondSquared accelerationX{0.0};
      SI::SIMeterPerSecondSquared accelerationY{0.0};
      SI::SIMeterPerSecondSquared accelerationZ{0.0};
      FrameOfReference frameOfReference{ FrameOfReference::FRAME_1 };

      Acceleration() = default;     //maintaining the default constructor

      Acceleration(const FrameOfReference& aFrameOfReference) :
         accelerationX(0.0),
         accelerationY(0.0),
         accelerationZ(0.0),
         frameOfReference(aFrameOfReference)
      {}

      Acceleration(const SI::SIMeterPerSecondSquared& aAccelerationX, const SI::SIMeterPerSecondSquared& aAccelerationY, const SI::SIMeterPerSecondSquared& aAccelerationZ, const FrameOfReference& aFrameOfReference) :
          accelerationX(aAccelerationX),
          accelerationY(aAccelerationY),
          accelerationZ(aAccelerationZ),
          frameOfReference(aFrameOfReference)
      {}

      bool operator==(const Acceleration& other) const
      {
          return (frameOfReference == other.frameOfReference && 
                  accelerationX() == other.accelerationX() &&
                  accelerationY() == other.accelerationY() && 
                  accelerationZ() == other.accelerationZ());
      }

      template <class T>
      void Serialise(T& archive) 
      {
         double accelX {accelerationX()};
         double accelY {accelerationY()};
         double accelZ {accelerationZ()};

         archive.Serialise(accelX, "accelerationX");
         archive.Serialise(accelY, "accelerationY");
         archive.Serialise(accelZ, "accelerationZ");
         archive.Serialise(frameOfReference, "frameOfReference");

         accelerationX = accelX;
         accelerationY = accelY;
         accelerationZ = accelZ;
      }

      LCA_TOPIC("Acceleration", 1, 0)
   };
}  // namespace Topics

#endif