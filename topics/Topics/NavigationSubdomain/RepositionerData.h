#ifndef REPOSITIONER_DATA_H
#define REPOSITIONER_DATA_H

#include "SIRadian.h"
#include <chrono>

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    class RepositionerData {
    public:

        /** @brief Defines the rotation angle of the AESA plane in Frame 5.
        */
        SI::SIRadian polarisationAngle{ 0.0 };

        /** @brief The demanded clockwise angular offset angle of the AESA from its reference position, 
        * where the reference position (Zero) is the position of the Repositioner where the AESA is facing up (mechanical boresight at 0°). 
        * The direction of rotation is determined when looking in the direction of the positive X-axis in Frame 5.
        */
        SI::SIRadian rollAngle{ 0.0 };
        
        /** @brief Indicates the time at which these measurements were taken */
        std::chrono::system_clock::time_point timeCalculated{ std::chrono::system_clock::duration::zero() };

        RepositionerData() = default;
        RepositionerData(SI::SIRadian aPolarisationAngle, SI::SIRadian aRollAngle, std::chrono::system_clock::time_point aTimeCalculated):
            polarisationAngle(aPolarisationAngle),
            rollAngle(aRollAngle), 
            timeCalculated(aTimeCalculated)
        {}

        template <class T>
        void Serialise(T& archive) {

            /* Temporary variables to allow serialisation and deserialisation of SIRadians */
            double polarisationAngleDouble{ polarisationAngle() };
            double rollAngleDouble{ rollAngle() };
            uint64_t timeSinceEpoch{ static_cast<uint64_t>(timeCalculated.time_since_epoch().count()) };

            archive.Serialise(polarisationAngleDouble, "polarisationAngle");
            archive.Serialise(rollAngleDouble, "rollAngle");
            archive.Serialise(timeSinceEpoch, "timeCalculated");

            /* After deserialisation convert back to SIRadians */
            polarisationAngle = polarisationAngleDouble;
            rollAngle = rollAngleDouble;

            /* Convert back to Chrono */
            std::chrono::system_clock::duration const durationSinceLastEpoch(timeSinceEpoch);
            std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch);
            timeCalculated = timePointSinceLastEpoch;
     
        }

        LCA_TOPIC("RepositionerData", 1, 0);
    };

}

#endif