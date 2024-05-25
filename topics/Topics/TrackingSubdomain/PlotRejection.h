#ifndef PLOT_REJECTION_H
#define PLOT_REJECTION_H

#include "PlotRejectionReason.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {
    class PlotRejection {
    public:

        std::uint32_t       plot_id          {0};
        PlotRejectionReason rejection_reason {PlotRejectionReason::OLD_TIMETAG};

        PlotRejection() = default;
        PlotRejection(std::uint32_t       plot_id,
                      PlotRejectionReason rejection_reason)

        : plot_id(plot_id),
          rejection_reason(rejection_reason)
        {}

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(plot_id,          "plot_id");
            archive.Serialise(rejection_reason, "rejection_reason");
        }

        LCA_TOPIC("PlotRejection", 1, 0);
    };
}

#endif