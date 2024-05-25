#ifndef DEMANDED_ELEVATIONS_H
#define DEMANDED_ELEVATIONS_H

#include <string>
#include "FrameOfReference.h"
#include "SIRadian.h"
#include "Fabric/Utils/LCA_Macros.h"
#include <vector>

namespace Topics {

struct [[deprecated]] DemandedElevations
{
    FrameOfReference frameOfReference{ FrameOfReference::FRAME_1 };
    std::vector<SI::SIRadian> demandElevations{};

    template <class T>
    void Serialise(T& archive) 
    {
        /* Non-topic classes except fundamental types cannot be serialised
        * instead we convert SIUnits type to their fundamental type.
        */
        std::vector<double> elevations{};
        for (const SI::SIRadian demandElevation : demandElevations)
        {
            elevations.push_back(demandElevation());
        }

        archive.Serialise(frameOfReference, "frameOfReference");
        archive.Serialise(elevations,"demandElevation", "demandElevations");

        /* Ensure vector doesn't have duplicates. */
        demandElevations.clear();
        
        /* After serialisation convert elevations back to SIRadians */
        for (const double demandElevation : elevations)
        {
            demandElevations.push_back(SI::SIRadian(demandElevation));
        }
    }

    LCA_TOPIC("DemandElevations", 1, 0)

};

}  // namespace Topics

#endif