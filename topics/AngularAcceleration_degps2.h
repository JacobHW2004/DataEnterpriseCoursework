#ifndef ANGULARACCELERATION_DEGPS2_H
#define ANGULARACCELERATION_DEGPS2_H

namespace Topics {

struct AngularAcceleration_degps2
{
   //degps2 - degrees per second squared
   double pitchRate_degps2{0};
   double rollRate_degps2{0};
   double yawRate_degps2{0};
   bool isValid{false};   
   
   AngularAcceleration_degps2() {};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(pitchRate_degps2, "pitchRate_degps2");
      archive.Serialise(rollRate_degps2, "rollRate_degps2");
      archive.Serialise(yawRate_degps2, "yawRate_degps2");
      archive.Serialise(isValid, "isValid");
  }

   LCA_TOPIC("AngularAcceleration_degps2", 1, 0)
   
};

}  // namespace Topics
#endif