#ifndef ATTITUDE_H
#define ATTITUDE_H

#include "SIRadian.h"
#include "FrameOfReference.h"

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    class Attitude {
    public:
        SI::SIRadian heading{ 0.0 };
        SI::SIRadian pitch{ 0.0 };
        SI::SIRadian bank{ 0.0 };
        FrameOfReference frameOfReference{ FrameOfReference::FRAME_1 };

        Attitude() = default;
        Attitude(SI::SIRadian aHeading, SI::SIRadian aPitch, SI::SIRadian aBank, FrameOfReference aFrameOfReference = FrameOfReference::FRAME_1):
            heading(aHeading),
            pitch(aPitch),
            bank(aBank),
            frameOfReference(aFrameOfReference)
        {}

        template <class T>
        void Serialise(T& archive) {

            /* Temporary variables to allow serialisation and deserialisation of SIRadians */
            double headingDouble{ heading() };
            double pitchDouble{ pitch() };
            double bankDouble{ bank() };

            archive.Serialise(headingDouble, "heading");
            archive.Serialise(pitchDouble,   "pitch");
            archive.Serialise(bankDouble,    "bank");
            archive.Serialise(frameOfReference, "frameOfReference");

            /* After deserialisation convert back to SIRadians */
            heading = headingDouble;
            pitch   = pitchDouble;
            bank    = bankDouble;
        }

        LCA_TOPIC("Attitude", 1, 0);
    };

}

#endif