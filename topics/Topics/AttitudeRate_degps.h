#ifndef ATTITUDERATE_DEGPS_H
#define ATTITUDERATE_DEGPS_H

namespace Topics {

struct AttitudeRate_degps
{
   //degps - degree per second
   double pitchRate_degps{0};
   double rollRate_degps{0};
   double yawRate_degps{0};
   bool isValid{false};


   AttitudeRate_degps() {};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(pitchRate_degps, "pitchRate_degps");
      archive.Serialise(rollRate_degps, "rollRate_degps");
      archive.Serialise(yawRate_degps, "yawRate_degps");
      archive.Serialise(isValid, "isValid");
  }

   LCA_TOPIC("AttitudeRate_degps", 1, 0)
   

};

}  // namespace Topics

#endif