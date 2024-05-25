#ifndef PLOT_H
#define PLOT_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

struct Plot {
    double plotAzimuth_rad      {0.0}; //radians
    double plotElevation_rad    {0.0}; //radians
    double plotRange_m          {0.0}; //meters

    template <class T>
    void Serialise(T& archive)
    {    
        archive.Serialise(plotAzimuth_rad,      "plotAzimuth_rad");
        archive.Serialise(plotElevation_rad,    "plotElevation_rad");
        archive.Serialise(plotRange_m,          "plotRange_m");

    }

    LCA_TOPIC("Plot", 1, 0)
};
    
}
#endif