#ifndef NAVIGATION_OFFSET_H
#define NAVIGATION_OFFSET_H
#include "SIDegree.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

struct NavigationOffset
{
   SI::SIDegree offset{ 0.0 };

   bool operator==(const NavigationOffset& other) const {
	   return offset == other.offset ;
   }

   template <class T>
   void Serialise(T& archive) {

	   /* Temporary variables to allow serialization of SI Degrees*/
	   double offsetDouble{ offset() };

       archive.Serialise(offsetDouble, "offset");

	   /* Temporary trick to get SIDegrees to serialise */
	   offset = offsetDouble;

  }

   LCA_TOPIC("NavigationOffset", 1, 0)
};

}  // namespace Topics

#endif