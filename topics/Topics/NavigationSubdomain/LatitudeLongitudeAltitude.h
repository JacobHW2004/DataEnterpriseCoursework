#ifndef LATITUDE_LONGITUDE_ALTITUDE_H
#define LATITUDE_LONGITUDE_ALTITUDE_H

#include "Fabric/Utils/LCA_Macros.h"
#include "SIDegree.h"
#include "SIMeter.h"
#include "SIRadian.h"

namespace Topics 
{

    struct LatitudeLongitudeAltitude
    {
        /**
         * @brief topic used to describe a position in Latitude, Longitide and Altitude
         */
        
        SI::SIDegree latitude { 0.0 };
        SI::SIDegree longitude{ 0.0 };
        SI::SIMeter  altitude { 0.0 };

        LatitudeLongitudeAltitude() = default;

        LatitudeLongitudeAltitude(const SI::SIDegree& aLatitude, const SI::SIDegree& aLongitude, const SI::SIMeter& aAltitude) :
            latitude(aLatitude),
            longitude(aLongitude),
            altitude(aAltitude)
        {}

        LatitudeLongitudeAltitude(const SI::SIRadian& aLatitude, const SI::SIRadian& aLongitude, const SI::SIMeter& aAltitude) :
            latitude(aLatitude.toDegree()),
            longitude(aLongitude.toDegree()),
            altitude(aAltitude)
        {}

        SI::SIRadian getLatitudeInRadians() const {

            return SI::SIRadian(latitude);
        }

        SI::SIRadian getLongitudeInRadians() const {

            return SI::SIRadian(longitude);
        }

        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {

            double lat { latitude() };
            double lon { longitude() };
            double alt { altitude() };

            archive.Serialise(lat, "latitude");
            archive.Serialise(lon, "longitude");
            archive.Serialise(alt, "altitude");

            latitude = lat;
            longitude = lon;
            altitude = alt;

        }

        LCA_TOPIC("LatitudeLongitudeAltitude", 1, 0)
    };

}   //end namespace Topics

#endif