#ifndef LINSTOPIC_H
#define LINSTOPIC_H

#include "Fabric/Utils/LCA_Macros.h"
#include <string>


#include "Acceleration_mps.h"
#include "AttitudeRate_degps.h"
#include "Bank_deg.h"
#include "Inclination_deg.h"
#include "LatLongPosition_deg.h"
#include "LinearVelocity_mps.h"
#include "TrueHeading.h"
//local
#include "AngularAcceleration_degps2.h"
#include "DirectionCosineMatrix.h"
#include "GeodVelocity_mps.h"
#include "NavigationDataTimeTags.h"
#include "VerticalVelocityAltitude.h"


namespace Topics {

class LinsTopic
{
public:

 
   double                     mtimeCalculated_s{0};
   unsigned int               mDataValidityWord{0};
   Acceleration_mps           mBodyLinearAcceleration{};
   AttitudeRate_degps         mRollPitchYawRate{};
   Bank_deg                   mBank{};
   Inclination_deg            mInclination{};
   LatLongPosition_deg        mLatLongPosition{};
   LinearVelocity_mps         mLinearVelocity{};
   TrueHeading_deg            mTrueHeading{};

   AngularAcceleration_degps2 mRollPitchYawAccelerationRate{};
   DirectionCosineMatrix      mDirectionCosineMatrix{};
   GeodVelocity_mps           mGeodVelocity{};
   NavigationDataTimeTags     mTimeTags{};
   VerticalVelocityAltitude   mVerticalVelocityAltitude{};

   LinsTopic() {};

   template <class T>
   void Serialise(T& archive) {
       archive.Serialise(mtimeCalculated_s, "mtimeCalculated_s");
       archive.Serialise(mDataValidityWord, "mDataValidityWord"); 
       archive.Serialise(mBodyLinearAcceleration, "mBodyLinearAcceleration");      
       archive.Serialise(mRollPitchYawRate, "mRollPitchYawRate");
       archive.Serialise(mBank,"mBank");
       archive.Serialise(mInclination, "mInclination");
       archive.Serialise(mLatLongPosition, "mLatLongPosition");
       archive.Serialise(mLinearVelocity, "mLinearVelocity");
       archive.Serialise(mTrueHeading, "mTrueHeading");
       archive.Serialise(mRollPitchYawAccelerationRate, "mRollPitchYawAccelerationRate");
       archive.Serialise(mDirectionCosineMatrix, "mDirectionCosineMatrix");
       archive.Serialise(mGeodVelocity, "mGeodVelocity");
       archive.Serialise(mTimeTags, "mTimeTags");
       archive.Serialise(mVerticalVelocityAltitude, "mVerticalVelocityAltitude");
   
   }

   LCA_TOPIC("LinsTopic", 1, 0)

};

}  // namespace Topics

#endif