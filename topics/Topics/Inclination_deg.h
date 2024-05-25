#ifndef INCLINATION_DEG_H
#define INCLINATION_DEG_H

namespace Topics {

struct Inclination_deg
{
   //deg - degrees
   double inclination_deg{0};
   bool isValid{false};  


   Inclination_deg() {};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(inclination_deg, "inclination_deg");
      archive.Serialise(isValid, "isValid");
  }

   LCA_TOPIC("Inclination_deg", 1, 0)
   

};

}  // namespace Topics

#endif