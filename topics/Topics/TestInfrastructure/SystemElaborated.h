#ifndef SYSTEM_ELABORATED_H
#define SYSTEM_ELABORATED_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

struct SystemElaborated
{
   bool elaborated{false};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(elaborated, "elaborated");
  }

   LCA_TOPIC("SystemElaborated", 1, 0)
   

};

}  // namespace Topics

#endif