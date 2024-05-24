#ifndef SIGHTLINE_H
#define SIGHTLINE_H

#include "Fabric/Utils/LCA_Macros.h"
#include "FrameOfReference.h"
#include "SIRadian.h"

namespace Topics {
    
    struct Sightline
    {
        SI::SIRadian azimuth {0.0};
        SI::SIRadian elevation {0.0};
        FrameOfReference nativeFrameOfReference {FrameOfReference::FRAME_1};

        bool operator==(const Sightline& other) const {
            return azimuth == other.azimuth &&
                    elevation == other.elevation &&
                    nativeFrameOfReference == other.nativeFrameOfReference;
        }

        template <typename T>
        void Serialise (T& archive) {
            
            /* Temporary variables to allow serialization of SIRadians */
            double azimuthDouble{ azimuth() };
            double elevationDouble{ elevation() };

            archive.Serialise(azimuthDouble, "azimuth");
            archive.Serialise(elevationDouble, "elevation");
            archive.Serialise(nativeFrameOfReference, "nativeFrameOfReference");

            /* Temporary trick to get SIRadian to serialise */
            azimuth = azimuthDouble;
            elevation = elevationDouble;
        }

        LCA_TOPIC("Sightline", 1, 0)
    };

}

#endif
