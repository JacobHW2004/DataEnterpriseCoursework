#ifndef PLOT_STATUS_H
#define PLOT_STATUS_H

#include "Fabric/Utils/LCA_Macros.h"
#include "TrackingDomainPlot.h"

namespace Topics {

    enum class PlotStatusType : uint8_t {
        UNCORRELATED_NOT_USED                    = 1,
        UNCORRELATED_USED_TO_FORM_NEW_TRACK      = 2,
        UNASSOCIATED_NOT_USED                    = 3,
        UNASSOCIATED_USED_TO_FORM_NEW_TRACK      = 4,
        ASSOCIATED_NOT_USED                      = 5,
        ASSOCIATED_USED_TO_UPDATE_EXISTING_TRACK = 6

    };

    class PlotStatus {
    public:

        Topics::Tracking::Plot plot{};
        PlotStatusType         status{ PlotStatusType::UNCORRELATED_NOT_USED };

        PlotStatus() = default;

        PlotStatus(Topics::Tracking::Plot aPlot,
                   PlotStatusType         aStatus) :

            plot(aPlot),
            status(aStatus)
        {}

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(plot,   "plot");
            archive.Serialise(status, "status");
        } 

        LCA_TOPIC("PlotStatus", 2, 0);
    };
}


#endif