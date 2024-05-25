#ifndef VERTICALVECLOCITYALTITUDE_H
#define VERTICALVECLOCITYALTITUDE_H

namespace Topics {

struct VerticalVelocityAltitude
{
   //m - meters
   //mps - meters per second
   double barometricAltitude_m{0};
   double velocityVertical_mps{0};
   bool isValid{false};
 
   VerticalVelocityAltitude() {};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(barometricAltitude_m, "barometricAltitude_m");
      archive.Serialise(velocityVertical_mps, "velocityVertical_mps");
      archive.Serialise(isValid, "isValid");
   }

   LCA_TOPIC("VerticalVelocityAltitude", 1, 0)
   
};

}  // namespace Topics

#endif