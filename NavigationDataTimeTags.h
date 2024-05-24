#ifndef TIMETAG_S_H
#define TIMETAG_S_H

namespace Topics {

struct NavigationDataTimeTags
{
   //s - seconds
   double angles_s{0};
   double angularAcceleration_s{0};
   double barometricAltitude_s{0};
   double linearAcceleration_s{0};
   double presentPosition_s{0};
   double velocityGeod_s{0};
   double velocityLinear_s{0};
   bool isValid{false};
   
   NavigationDataTimeTags() {};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(angles_s, "angles_s");
      archive.Serialise(angularAcceleration_s, "angularAcceleration_s");
      archive.Serialise(barometricAltitude_s, "barometricAltitude_s");
      archive.Serialise(linearAcceleration_s, "linearAcceleration_s");
      archive.Serialise(presentPosition_s, "presentPosition_s");
      archive.Serialise(velocityGeod_s, "velocityGeod_s");
      archive.Serialise(velocityLinear_s, "velocityLinear_s");
      archive.Serialise(isValid, "isValid");
  }

   LCA_TOPIC("NavigationDataTimeTags", 1, 0)
   
};

}  // namespace Topics

#endif