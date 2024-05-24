#ifndef GEO_LLA_REFERENCED_VOLUME
#define GEO_LLA_REFERENCED_VOLUME

#include "SIDegree.h"
#include "SIMeter.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics 
{
    struct GeoLLAReferencedVolume
    {
        
        /**
         * @brief topic used to describe a volume that is geo referenced (uses Lat/Long/Alt not the Leo Frames of reference)
         */

        SI::SIDegree latitude {};
        SI::SIDegree longitude {};
        SI::SIMeter altitude {};
        SI::SIDegree azimuthLeft {};
        SI::SIDegree azimuthRight {};
        SI::SIDegree elevationLower {};
        SI::SIDegree elevationUpper {};
        SI::SIMeter rangeHalfwidth {};

        inline bool operator==(GeoLLAReferencedVolume comp)
        {
            return ((latitude == comp.latitude) &&
                    (longitude == comp.longitude) &&
                    (altitude() == comp.altitude()) &&
                    (azimuthLeft == comp.azimuthLeft) &&
                    (azimuthRight == comp.azimuthRight) &&
                    (elevationLower == comp.elevationLower) &&
                    (elevationUpper == comp.elevationUpper) &&
                    (rangeHalfwidth() == comp.rangeHalfwidth())
                    );
        }

        inline bool operator!=(GeoLLAReferencedVolume comp)
        {
            return !(comp == *this);
        }

        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {

            double lat { latitude() };
            double lon { longitude() };
            double alt { altitude() };
            double azL { azimuthLeft() };
            double azR { azimuthRight() };
            double elL { elevationLower() };
            double elU { elevationUpper() };
            double range{ rangeHalfwidth() };

            archive.Serialise(lat, "latitude");
            archive.Serialise(lon, "longitude");
            archive.Serialise(alt, "altitude");
            archive.Serialise(azL, "azimuthLeft");
            archive.Serialise(azR, "azimuthRight");
            archive.Serialise(elL, "elevationLower");
            archive.Serialise(elU, "elevationUpper");
            archive.Serialise(range, "rangeHalfwidth");

            latitude = lat;
            longitude = lon;
            altitude = alt;
            azimuthLeft = azL;
            azimuthRight = azR;
            elevationLower = elL;
            elevationUpper = elU;
            rangeHalfwidth = range;

        }
        LCA_TOPIC("GeoLLAReferencedVolume", 1, 0)

    };

}   //namespace Topics

#endif