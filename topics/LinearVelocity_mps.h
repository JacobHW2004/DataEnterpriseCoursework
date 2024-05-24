#ifndef LINEARVELOCITY_MPS_H
#define LINEARVELOCITY_MPS_H

namespace Topics {

struct LinearVelocity_mps
{
   //mps - meter per second
   double linearVelocityX_mps{0};
   double linearVelocityY_mps{0};
   double linearVelocityZ_mps{0};
   bool isValid{false};
   

   LinearVelocity_mps() {};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(linearVelocityX_mps, "linearVelocityX_mps");
      archive.Serialise(linearVelocityY_mps, "linearVelocityY_mps");
      archive.Serialise(linearVelocityZ_mps, "linearVelocityZ_mps");
      archive.Serialise(isValid, "isValid");
   }

   LCA_TOPIC("LinearVelocity_mps", 1, 0)
   

};

}  // namespace Topics

#endif
