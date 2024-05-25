#ifndef CORRELATED_PLOT_H
#define CORRELATED_PLOT_H

#include "Fabric/Utils/LCA_Macros.h"
#include "TrackingDomainPlot.h"

namespace Topics {
    namespace TrackCorrelation {
        class CorrelatedPlot {
        public:

            Topics::Tracking::Plot plot{};

            CorrelatedPlot() = default;
            CorrelatedPlot(Topics::Tracking::Plot plot)

                : plot(plot)
            {}

            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(plot, "plot");
            }

            LCA_TOPIC("CorrelatedPlot", 1, 0);
        };
    }
}

#endif
