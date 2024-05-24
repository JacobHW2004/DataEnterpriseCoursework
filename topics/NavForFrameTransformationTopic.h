#ifndef NAVFORFRAMETRANSFORMATIONTOPIC_H
#define NAVFORFRAMETRANSFORMATIONTOPIC_H

#include "Fabric/Utils/LCA_Macros.h"

#include <string>

namespace Topics {


class NavForFrameTransformationTopic {
public:
    
    // The aircraft heading is defined as the angle between the True North (Frame 1) and the projection 
    // of the aircraft X-axis (Frame 4) on the horizontal plane local  to the instantaneous Frame 1 origin. 
    // Positive as a clockwise rotation of the X-axis from the geographic North axis when looking down on the horizontal plane.
    double heading_rad {0};
    
    // The bank angle is defined as the angle through which the aircraft must be rotated about the body X-axis 
    // to bring the body Y-axis back to the local horizontal with the aircraft right way up. Positive when an anti-clockwise 
    //rotation about the body X-axis is required to bring the body Y-axis back to the local horizontal.
    double bank_rad {0};
    
    // The pitch_rad is defined as the angle through which the aircraft must be rotated to bring the body X-axis 
    // back to the horizontal. The inclination angle is measured positive when the nose of the aircraft is above the 
    // horizontal. The maximum and minimum values of inclination angle will be + and - 90 degrees respectively.
    double pitch_rad {0};
    
    // Represents the ground static harmonisation bank error due to installation misalignment + the 
    // dynamic flight static harmonisation roll error  due to forces on the aircraft structure. Nose up is positive, in 
    // radians range -0.005 to +0.005.
    // Not used for this MVP.
    double harmBankCorrection_rad{0};
    
    // Represents the ground static harmonisation pitch error due to installation misalignment + the 
    // dynamic flight static harmonisation pitch error  due to forces on the aircraft structure. Nose up is positive, in 
    // radians range -0.005 to +0.005.
    // Not used for this MVP.  
    double harmPitchCorrection_rad{0};
    
    // Represents the ground static harmonisation heading error due to installation misalignment + the dynamic 
    // flight static harmonisation yaw error  due to forces on the aircraft structure. Nose up is positive, in radians range 
    // -0.005 to +0.005.
    // Not used for this MVP.
    double harmHeadingCorrection_rad{0};
     
    // Not used for this MVP.
    double polarisationAngle_rad{0};

    // Not used for this MVP.
    double repositionerRollAngle_rad{0};
    
    // Indicates the time at which aircraft present position was measured.
    double NavTimeCalculated_s {0};


   NavForFrameTransformationTopic() noexcept {};

   template <class T>
   void Serialise(T& archive) {
       archive.Serialise(heading_rad, "heading_rad");
       archive.Serialise(bank_rad, "bank_rad");
       archive.Serialise(pitch_rad, "pitch_rad");
       archive.Serialise(harmBankCorrection_rad, "harmBankCorrection_rad");       
       archive.Serialise(harmPitchCorrection_rad, "harmPitchCorrection_rad");
       archive.Serialise(harmHeadingCorrection_rad, "harmHeadingCorrection_rad");
       archive.Serialise(polarisationAngle_rad, "polarisationAngle_rad");
       archive.Serialise(repositionerRollAngle_rad, "repositionerRollAngle_rad");
       archive.Serialise(NavTimeCalculated_s, "NavTimeCalculated_s");
   }

   LCA_TOPIC("NavForFrameTransformationTopic", 1, 0)


 
};

}  // namespace Topics

#endif
