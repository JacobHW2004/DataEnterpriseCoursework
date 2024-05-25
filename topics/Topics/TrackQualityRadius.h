#ifndef TRACK_QUALITY_RADIUS_H
#define TRACK_QUALITY_RADIUS_H

#include <cstdint>
#include "SIMeter.h"
#include "SIMeterPerSecond.h"
#include "Fabric/Utils/LCA_Macros.h"


namespace Topics {

/**
* @brief Topic provides a means of storing x/z radius positions for track task qualities.
*
*/
struct TrackQualityRadius {

    
    SI::SIMeter xRadiusPosition{ 0.0 };
    SI::SIMeter zRadiusPosition{ 0.0 };
    SI::SIMeterPerSecond xRadiusVelocity{ 0.0 };
    SI::SIMeterPerSecond zRadiusVelocity{ 0.0 };

    /**
    * @brief Topic Constructor with parameters
    */
    TrackQualityRadius(SI::SIMeter aXRadiusPosition, SI::SIMeter aZRadiusPosition, SI::SIMeterPerSecond aXRadiusVelocity, SI::SIMeterPerSecond aZRadiusVelocity) :
    
            xRadiusPosition{aXRadiusPosition},
            zRadiusPosition{aZRadiusPosition},
            xRadiusVelocity{aXRadiusVelocity},
            zRadiusVelocity{aZRadiusVelocity}
        {};

    /**
    * @brief Default constructor
    */
    TrackQualityRadius() :
        xRadiusPosition{0.0},
        zRadiusPosition{0.0},
        xRadiusVelocity{0.0},
        zRadiusVelocity{0.0}
    {};

    /**
    * @brief Serialise function required for communications
    */
    template <class T>
    void Serialise(T& archive) {

        double xRadiusPos {xRadiusPosition()};
        double zRadiusPos {zRadiusPosition()};
        double xRadiusVel {xRadiusVelocity()};
        double zRadiusVel {zRadiusVelocity()};

        archive.Serialise(xRadiusPos, "xRadiusPosition");
        archive.Serialise(zRadiusPos, "zRadiusPosition");
        archive.Serialise(xRadiusVel, "xRadiusVelocity");
        archive.Serialise(zRadiusVel, "zRadiusVelocity");

        // Following required for setting up values after deserialisation
        xRadiusPosition = xRadiusPos;
        zRadiusPosition = zRadiusPos;
        xRadiusVelocity = xRadiusVel;
        zRadiusVelocity = zRadiusVel;
    }

    LCA_TOPIC("TrackQualityRadius", 1, 0)
 
};

}  // namespace Topics

#endif