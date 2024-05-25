#ifndef WIND_H
#define WIND_H

namespace Topics {

struct Wind 
{
   //deg - degress
   //kt - knots
   double direction_deg{0};
   double speed_kt{0};
   bool isValid{false};

   Wind() {};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(direction_deg, "direction_deg");
      archive.Serialise(speed_kt, "speed_kt");
      archive.Serialise(isValid, "isValid");
  }

   LCA_TOPIC("Wind", 1, 0)
   
};

}  // namespace Topics

#endif