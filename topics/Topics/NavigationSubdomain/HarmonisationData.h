#ifndef HARMONISATION_DATA_H
#define HARMONISATION_DATA_H

#include "SIRadian.h"
#include <chrono>

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    class HarmonisationData {
    public:
        /** @brief Represents the ground static harmonisation bank error due to installation misalignment + the 
        * dynamic flight static harmonisation roll error  due to forces on the aircraft structure. Nose up is positive, in 
        * radians range -0.005 to +0.005. 
        */
        SI::SIRadian bankCorrection{ 0.0 };

        /** @brief Represents the ground static harmonisation pitch error due to installation misalignment + the 
        * dynamic flight static harmonisation pitch error  due to forces on the aircraft structure. Nose up is positive, in 
        * radians range -0.005 to +0.005. 
        */
        SI::SIRadian pitchCorrection{ 0.0 };


        /** @brief Represents the ground static harmonisation heading error due to installation misalignment + the dynamic 
        * flight static harmonisation yaw error  due to forces on the aircraft structure. Nose up is positive, in radians range 
        * -0.005 to +0.005.
        */
        SI::SIRadian headingCorrection{ 0.0 };

        /** @brief Indicates the time at which these measurements were taken */
        std::chrono::system_clock::time_point timeCalculated{ std::chrono::system_clock::duration::zero() };

        HarmonisationData() = default;
        HarmonisationData(SI::SIRadian aBankCorrection, SI::SIRadian aPitchCorrection, SI::SIRadian aHeadingCorrection,  std::chrono::system_clock::time_point aTimeCalculated):
            bankCorrection(aBankCorrection),
            pitchCorrection(aPitchCorrection),
            headingCorrection(aHeadingCorrection), 
            timeCalculated(aTimeCalculated)
        {}

        template <class T>
        void Serialise(T& archive) {

            /* Temporary variables to allow serialisation and deserialisation of SIRadians */
            double bankCorrectionDouble{ bankCorrection() };
            double pitchCorrectionDouble{ pitchCorrection() };
            double headingCorrectionDouble{ headingCorrection() };
            uint64_t timeSinceEpoch{ static_cast<uint64_t>(timeCalculated.time_since_epoch().count()) };

            archive.Serialise(bankCorrectionDouble, "bankCorrection");
            archive.Serialise(pitchCorrectionDouble, "pitchCorrection");
            archive.Serialise(headingCorrectionDouble, "headingCorrection");
            archive.Serialise(timeSinceEpoch, "timeCalculated");

            /* After deserialisation convert back to SIRadians */
            bankCorrection = bankCorrectionDouble;
            pitchCorrection = pitchCorrectionDouble;
            headingCorrection = headingCorrectionDouble;

            /* Convert back to Chrono */
            std::chrono::system_clock::duration const durationSinceLastEpoch(timeSinceEpoch);
            std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch);
            timeCalculated = timePointSinceLastEpoch;

        }

        LCA_TOPIC("HarmonisationData", 1, 0);
    };

}

#endif