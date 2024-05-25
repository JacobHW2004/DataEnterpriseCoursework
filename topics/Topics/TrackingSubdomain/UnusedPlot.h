#ifndef UNUSED_PLOT_H
#define UNUSED_PLOT_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics {

    enum class UnusedReason : uint8_t {
        NO_AVAILABLE_TRACKS = 1,
        NO_RESPONSES        = 2
    };

    class UnusedPlot {
    public:

        std::uint32_t plot_id{ 0 };
        UnusedReason  reason{ UnusedReason::NO_AVAILABLE_TRACKS }; 

        UnusedPlot() = default;

        UnusedPlot(std::uint32_t plot_id,
                   UnusedReason  reason) : 

            plot_id(plot_id),
            reason(reason)
        {}

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(plot_id, "plot_id");
            archive.Serialise(reason,  "reason");
        }

        LCA_TOPIC("UnusedPlot", 1, 0);

    };
}


#endif