#ifndef ELIGIBILITY_H
#define ELIGIBILITY_H

#include "Fabric/Utils/LCA_Macros.h"

#include <cstdint>

namespace Topics {

struct Eligibility
{
   std::int32_t internalTaskID{0};
   bool isEligible{false};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(internalTaskID, "internalTaskID");
      archive.Serialise(isEligible, "isEligible");
  }

   LCA_TOPIC("Eligibility", 1, 0)
   

};

}  // namespace Topics

#endif