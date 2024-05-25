#ifndef FIELD_OF_VIEW_AZIMUTH_EXTENTS_H
#define FIELD_OF_VIEW_AZIMUTH_EXTENTS_H

#include <string>
#include "FieldOfViewAzimuthExtent.h"
#include "Fabric/Utils/LCA_Macros.h"
#include <vector>

namespace Topics {

struct [[deprecated]] FieldOfViewAzimuthExtents
{
    std::vector<FieldOfViewAzimuthExtent> fieldOfViewAzimuthExtents{};

    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(fieldOfViewAzimuthExtents,"fovAzimuthExtent", "fieldOfViewAzimuthExtents");
    }

    LCA_TOPIC("FieldOfViewAzimuthExtents", 1, 0)

};

}  // namespace Topics

#endif