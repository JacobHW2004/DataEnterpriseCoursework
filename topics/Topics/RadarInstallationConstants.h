#ifndef RADAR_INSTALLATION_CONSTANTS_H
#define RADAR_INSTALLATION_CONSTANTS_H

#include "SIRadian.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

/** @brief This topic class provides a selection of constant values related to RadarInstallation */
class RadarInstallationConstants {
public:
     
    /** @brief Repositioner Cant Angle for the specific aircraft installation.*/
    SI::SIRadian antennaCantAngle{};

    /** @brief Represents ground static pitch mounting angle of the antenna.*/
    SI::SIRadian pitchMountingAngle{};

    /** @brief For fixed repositioner.*/
    SI::SIRadian maximumAngleOffBoresight{};

    /** @brief Field of view radius for the receiver.*/
    SI::SIRadian iFoVRadius{};
    
    /** @brief Serialise function required for communications. */
    template <class T>
    void Serialise(T& archive) {
        /** @brief Repositioner Cant Angle for the specific aircraft installation.*/
        double antennaCantAngleDouble{antennaCantAngle()};

        /** @brief Represents ground static pitch mounting angle of the antenna.*/
        double pitchMountingAngleDouble{pitchMountingAngle()};

        /** @brief For fixed repositioner.*/
        double maximumAngleOffBoresightDouble{maximumAngleOffBoresight()};

        /** @brief Field of view radius for the receiver.*/
        double iFoVRadiusDouble{iFoVRadius()};

        archive.Serialise(antennaCantAngleDouble, "antennaCantAngle");
        archive.Serialise(pitchMountingAngleDouble, "pitchMountingAngle");
        archive.Serialise(maximumAngleOffBoresightDouble, "maximumAngleOffBoresight");
        archive.Serialise(iFoVRadiusDouble, "iFoVRadius");

        antennaCantAngle = antennaCantAngleDouble;
        pitchMountingAngle = pitchMountingAngleDouble;
        maximumAngleOffBoresight = maximumAngleOffBoresightDouble;
        iFoVRadius = iFoVRadiusDouble;
    }

    LCA_TOPIC("RadarInstallationConstants", 1, 0)

 
};

}  // namespace Topics

#endif