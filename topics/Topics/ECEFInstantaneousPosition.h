#ifndef ECEF_INSTANTANEOUS_POSITION_H
#define ECEF_INSTANTANEOUS_POSITION_H

#include "Fabric/Utils/LCA_Macros.h"
#include <string>

#include "Acceleration.h"
#include "LinearVelocity.h"
#include "Position.h"

namespace Topics {

/**
 * @brief ECEFInstantaneousPosition is the EarthCentredEarthFixed version of the Instantaneous Position.
 *        ECEF is a cartesian spatial reference system that represents locations in the vicinity of the Earth as X, Y, and Z measurements from its center of mass.
 * 
 */
class ECEFInstantaneousPosition
{
public:  

   /* This data indicates the time at which aircraft present position was measured. */
   uint64_t navTimeTag_s{0U};

   Position ownshipPosition{};
   LinearVelocity ownshipVelocity{};
   Acceleration ownshipAcceleration{};


   ECEFInstantaneousPosition() {};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(navTimeTag_s, "navTimeTag_s");
      archive.Serialise(ownshipPosition,"ownshipPosition");
      archive.Serialise(ownshipVelocity, "ownshipVelocity");
      archive.Serialise(ownshipAcceleration, "ownshipAcceleration");
   }

   LCA_TOPIC("ECEFInstantaneousPosition", 1, 0)
   
};

}  // namespace Topics

#endif