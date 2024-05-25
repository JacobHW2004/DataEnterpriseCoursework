#ifndef VELOCITY_MPS_H
#define VELOCITY_MPS_H

namespace Topics {

struct Velocity_mps
{
   //mps -  meters per second
   double velocity_mps{0};
   bool isValid{false};

 
   Velocity_mps() {};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(velocity_mps, "Velocity_mps");
      archive.Serialise(isValid, "isValid");
  }

   LCA_TOPIC("Velocity_mps", 1, 0)
   
};

}  // namespace Topics
   
#endif