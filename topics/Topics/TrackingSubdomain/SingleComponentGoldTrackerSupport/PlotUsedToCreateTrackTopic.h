#ifndef PLOT_USED_TO_CREATE_TRACK_TOPIC_H
#define PLOT_USED_TO_CREATE_TRACK_TOPIC_H

#include "Fabric/Utils/LCA_Macros.h"
namespace Topics {

    class PlotUsedToCreateTrackTopic {
    public:

        std::uint32_t plot_id{ 0 };
        std::uint32_t track_id{ 0 };

        PlotUsedToCreateTrackTopic() = default;
        PlotUsedToCreateTrackTopic(std::uint32_t plot_id, std::uint32_t track_id)
            : plot_id(plot_id),
              track_id(track_id)
        {}

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(plot_id, "plot_id");
            archive.Serialise(track_id, "track_id");
        }

        LCA_TOPIC("PlotUsedToCreateTrackTopic", 1, 0);
    };

}
#endif