#ifndef OWNSHIPPOSITIONVELOCITYANDACCELERATION_H
#define OWNSHIPPOSITIONVELOCITYANDACCELERATION_H

#include "Fabric/Utils/LCA_Macros.h"

#include <string>
#include "Acceleration_mps.h"
#include "Altitude_m.h"
#include "LatLongPosition_deg.h"
#include "LinearVelocity_mps.h"


namespace Topics {

class OwnshipPositionVelocityAndAcceleration
{
public:  

   /* This data indicates the time at which aircraft present position was measured. */
   double              mNavTimeTag_s{0};
   /* The best estimate of geographic latitude, Longitude available from such navigation (in degrees)  */   
   LatLongPosition_deg mOwnshipPosition{};
   /* The best estimate of Altitude available from the navigation source (in meters)  */    
   Altitude_m          mOwnshipAltitude{};
   /* The best available linear velocity along the X,Y,Z-axis of the aircraft in Frame 4. */   
   LinearVelocity_mps  mOwnshipVelocity{};
   /* The total acceleration (inertial and gravitational) experienced by an accelerometer aligned along the X,Y,Z-axis of the aircraft (Frame 4) */   
   Acceleration_mps    mOwnshipAcceleration{};
   
   /* Addition of frame 0 origin values & timestamp for Gold Tracker Integration */
   double mFrame0_OriginLat{0};
   double mFrame0_OriginLong{0};
   double mFrame0_OriginAlt{0};
   double mFrame0_OriginTime{0};

   OwnshipPositionVelocityAndAcceleration() {};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(mNavTimeTag_s, "mNavTimeTag_s");
      archive.Serialise(mOwnshipAcceleration,"mOwnshipAcceleration");
      archive.Serialise(mOwnshipAltitude, "mOwnshipAltitude");
      archive.Serialise(mOwnshipVelocity, "mOwnshipVelocity");
      archive.Serialise(mOwnshipPosition,"mOwnshipPosition");
	   archive.Serialise(mFrame0_OriginLat, "mFrame0_OriginLat");
	   archive.Serialise(mFrame0_OriginLong, "mFrame0_OriginLong");
	   archive.Serialise(mFrame0_OriginAlt, "mFrame0_OriginAlt");
	   archive.Serialise(mFrame0_OriginTime, "mFrame0_OriginTime");
   }

   LCA_TOPIC("OwnshipPositionVelocityAndAcceleration", 1, 0)
   

};

}  // namespace Topics

#endif
