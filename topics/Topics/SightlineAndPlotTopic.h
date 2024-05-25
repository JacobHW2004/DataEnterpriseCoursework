#ifndef SIGHTLINEANDPLOTTOPIC_H
#define SIGHTLINEANDPLOTTOPIC_H

#include "Fabric/Utils/LCA_Macros.h"
#include "Plot.h"

#include <string>
#include <vector>

namespace Topics {
    
class SightlineAndPlotTopic {
public:   
    double scanAzimuth_rad      {0.0}; //radians
    double scanElevation_rad    {0.0}; //radians
    std::vector<Plot> plots     {};

   template <class T>
   void Serialise(T& archive) {
       archive.Serialise(scanAzimuth_rad, "scanAzimuth_rad");
       archive.Serialise(scanElevation_rad, "scanElevation_rad");
       archive.Serialise(plots, "plot", "plots");
   }

   LCA_TOPIC("SightlineAndPlotTopic", 1, 0)
};

}  // namespace Topics

#endif