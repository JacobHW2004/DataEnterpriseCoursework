#ifndef ALTITUDE_M_H
#define ALTITUDE_M_H

namespace Topics {

struct Altitude_m
{
   //m - meters
   double altitude_m{0};
   bool isValid{false};

   Altitude_m() {};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(altitude_m, "altitude_m");
      archive.Serialise(isValid, "isValid");
   }

   LCA_TOPIC("Altitude_m", 1, 0)
   

};

}  // namespace Topics

#endif