#ifndef UV_SIGHTLINE_H
#define UV_SIGHTLINE_H

#include "Fabric/Utils/LCA_Macros.h"
#include "FrameOfReference.h"
#include "FloatEqualityChecker.h"

namespace Topics {

    struct UVSightline
    {
        double sightlineU{ 0.0 };
        double sightlineV{ 0.0 };
        FrameOfReference nativeFrameOfReference{ Topics::FrameOfReference::FRAME_6 };

        bool operator==(const UVSightline& other) const {
            return SI::floatEqualityChecker::AlmostEqual(sightlineU, other.sightlineU, 1e-6) &&
                SI::floatEqualityChecker::AlmostEqual(sightlineV, other.sightlineV, 1e-6) &&
                nativeFrameOfReference == other.nativeFrameOfReference;
        }

        template <typename T>
        void Serialise(T& archive) {

            archive.Serialise(sightlineU, "sightlineU");
            archive.Serialise(sightlineV, "sightlineV");
            archive.Serialise(nativeFrameOfReference, "nativeFrameOfReference");
        }

        LCA_TOPIC("UVSightline", 1, 0)
    };

}

#endif