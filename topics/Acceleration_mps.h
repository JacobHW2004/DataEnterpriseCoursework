#ifndef ACCELERATION_MPS_H
#define ACCELERATION_MPS_H

#include "Fabric/Utils/LCA_Macros.h"
#include <string>

namespace Topics {

struct Acceleration_mps
{
   //mps2 = meters per second squared
   double accelerationX_mps2{0};
   double accelerationY_mps2{0};
   double accelerationZ_mps2{0};
   bool isValid{false}; 

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(accelerationX_mps2, "accelerationX_mps2");
      archive.Serialise(accelerationY_mps2, "accelerationY_mps2");
      archive.Serialise(accelerationZ_mps2, "accelerationZ_mps2");
      archive.Serialise(isValid, "isValid");
  }

   LCA_TOPIC("Acceleration_mps", 1, 0)
};

}  // namespace Topics

#endif