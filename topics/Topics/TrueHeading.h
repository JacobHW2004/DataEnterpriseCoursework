#ifndef TRUEHEADING_DEG_H
#define TRUEHEADING_DEG_H

namespace Topics {

struct TrueHeading_deg
{
   //deg - degrees
   double trueHeading_deg{0};
   bool isValid{false};
   
   TrueHeading_deg() {};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(trueHeading_deg, "trueHeading_deg");
      archive.Serialise(isValid, "isValid");
   }

   LCA_TOPIC("TrueHeading_deg", 1, 0)
   

};

}  // namespace Topics

#endif