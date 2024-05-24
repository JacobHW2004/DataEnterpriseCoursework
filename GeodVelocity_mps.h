#ifndef GEODVELOCITY_MPS_H
#define GEODVELOCITY_MPS_H

namespace Topics {

struct GeodVelocity_mps
{
   //mps - meters per second
   double velocityEast_mps {0};
   double velocityNorth_mps {0};
   bool isValid {false};
   
   GeodVelocity_mps() {};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(velocityEast_mps, "velocityEast_mps");
      archive.Serialise(velocityNorth_mps, "velocityNorth_mps");
      archive.Serialise(isValid, "isValid");
  }

   LCA_TOPIC("GeodVelocity_mps", 1, 0)
    
};

}  // namespace Topics

#endif