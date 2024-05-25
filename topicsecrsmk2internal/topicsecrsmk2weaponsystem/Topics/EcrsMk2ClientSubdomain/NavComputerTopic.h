#ifndef NAVCOMPUTERTOPIC_H
#define NAVCOMPUTERTOPIC_H

#include "Fabric/Utils/LCA_Macros.h"

#include <string>

#include "Acceleration_mps.h"
#include "AttitudeRate_degps.h"
#include "Bank_deg.h"
#include "Inclination_deg.h"
#include "LatLongPosition_deg.h"
#include "LinearVelocity_mps.h"
#include "TrueHeading.h"
#include "Altitude_m.h"
#include "Velocity_mps.h"
#include "Wind.h"

namespace Topics {

class NavComputerTopic
{
public:  

   double              mtimeCalculated_s{0};
   unsigned int        mDataValidityWord{0};
   double              mBestNCTimeTagAccel_s{0};
   /* This data indicates the time at which aircraft present position was measured. */   
   double              mBestNCTimeTagData_s{0};
   bool                mInDataDegraded{false};

   /* The total acceleration (inertial and gravitational) experienced by an accelerometer aligned along the X,Y,Z-axis of the aircraft (Frame 4) */
   Acceleration_mps    mBestBodyAcceleration{};
   AttitudeRate_degps  mBestRollPitchYawRate{};
   Bank_deg            mBestBank{};
   Inclination_deg     mBestInclination{};
   /* The best estimate of geographic latitude, Longitude available from such navigation (in Degrees)  */   
   LatLongPosition_deg mBestLatLongPosition{};
   /* The best available linear velocity along the X,Y,Z-axis of the aircraft in Frame 4. */
   LinearVelocity_mps  mBestLinearVelocity{};
   TrueHeading_deg     mBestTrueHeading{};
   Altitude_m          mBestTrueAltitude{};
   /* The best available easterly component of the aircraft terrestrial velocity in Frame 1 */
   Velocity_mps        mBestVelocityEast{};
   /* The best available northerly component of the aircraft terrestrial velocity in Frame 1 */
   Velocity_mps        mBestVelocityNorth{};
   /* The best available vertical velocity information in Frame 1 */
   Velocity_mps        mBestVelocityVertical{};
   Wind                mBestWind{};

   NavComputerTopic() {};

   template <class T>
   void Serialise(T& archive) {
       archive.Serialise(mtimeCalculated_s, "mtimeCalculated_s");
       archive.Serialise(mDataValidityWord, "mDataValidityWord");
       archive.Serialise(mBestNCTimeTagAccel_s, "mBestNCTimeTagAccel_s");
       archive.Serialise(mBestNCTimeTagData_s, "mBestNCTimeTagData_s");       
       archive.Serialise(mInDataDegraded, "mInDataDegraded");
       archive.Serialise(mBestBodyAcceleration, "mBestBodyAcceleration");
       archive.Serialise(mBestRollPitchYawRate,"mBestRollPitchYawRate");
       archive.Serialise( mBestBank, "mBestBank");
       archive.Serialise( mBestInclination,"mBestInclination");
       archive.Serialise( mBestLatLongPosition,"mBestLatLongPosition");
       archive.Serialise( mBestLinearVelocity ,"mBestLinearVelocity");
       archive.Serialise(mBestTrueHeading,"mBestTrueHeading");
       archive.Serialise( mBestTrueAltitude,"mBestTrueAltitude");
       archive.Serialise(mBestVelocityEast,"mBestVelocityEast");
       archive.Serialise(mBestVelocityNorth,"mBestVelocityNorth");
       archive.Serialise( mBestVelocityVertical, "mBestVelocityVertical");
       archive.Serialise(mBestWind,"mBestWind");
                           
   }

   LCA_TOPIC("NavComputerTopic", 1, 0)
   

};

}  // namespace Topics

#endif