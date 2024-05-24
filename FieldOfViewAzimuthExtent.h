#ifndef FIELD_OF_VIEW_AZIMUTH_EXTENT_H
#define FIELD_OF_VIEW_AZIMUTH_EXTENT_H

#include <string>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

struct [[deprecated]] FieldOfViewAzimuthExtent
{

    float fieldOfViewAzimuthHalfwidth{0.0};
    float fieldOfViewAzimuthCentre{0.0};
    bool  demandHasExtent{false};

    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(fieldOfViewAzimuthHalfwidth, "fieldOfViewAzimuthHalfwidth");
        archive.Serialise(fieldOfViewAzimuthCentre, "fieldOfViewAzimuthCentre");
        archive.Serialise(demandHasExtent, "demandHasExtent");
    }

    LCA_TOPIC("FieldOfViewAzimuthExtent", 1, 0)

};

}  // namespace Topics

#endif