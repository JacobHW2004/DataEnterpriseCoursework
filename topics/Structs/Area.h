#ifndef AREA_H
#define AREA_H

#include "SIMeter.h"
#include "SIRadian.h"
#include "Fabric/Utils/LCA_Macros.h"


namespace Topics {

struct Area
    {
        
        /**
         * @brief topic used to describe an Area as defined within the ICD
         */

        SI::SIRadian azimuthHalfwidth {};
        SI::SIRadian azimuthCentre {};
        SI::SIMeter planLower {};
        SI::SIMeter planUpper {};

        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {

            double azHalf { azimuthHalfwidth() };
            double azCentre { azimuthCentre() };
            double planL { planLower() };
            double planU { planUpper() };

            archive.Serialise(azHalf, "azimuthHalfwidth");
            archive.Serialise(azCentre, "azimuthCentre");
            archive.Serialise(planL, "planLower");
            archive.Serialise(planU, "planUpper");

            azimuthHalfwidth = azHalf;
            azimuthCentre = azCentre;
            planLower = planL;
            planUpper = planU;

        }

        LCA_TOPIC("Area", 1, 0)

    };

} // namespace Topics

#endif

