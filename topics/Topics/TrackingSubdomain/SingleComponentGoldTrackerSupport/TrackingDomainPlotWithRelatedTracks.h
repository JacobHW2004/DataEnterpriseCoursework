#ifndef TRACKING_DOMAIN_PLOT_WITH_RELATED_TRACKS_H
#define TRACKING_DOMAIN_PLOT_WITH_RELATED_TRACKS_H
#include <vector>
#include <cstdint>

#include "TrackingDomainPlot.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {
    namespace Tracking {

class PlotWithRelatedTracks {
public:
    Plot plot{};

    std::uint16_t              no_of_related_tracks {0};
    std::vector<std::uint32_t> track_id_vector      {}; // length 0-500

    PlotWithRelatedTracks() = default;
    PlotWithRelatedTracks(Plot plot,
                          std::uint16_t no_of_related_tracks,
                          const std::vector<std::uint32_t>& track_id_vector)
        : plot(plot),
          no_of_related_tracks(no_of_related_tracks),
          track_id_vector(track_id_vector)
    {}

    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(plot,"plot");
        archive.Serialise(no_of_related_tracks,"no_of_related_tracks");
        archive.Serialise(track_id_vector,"track_id","track_id_vector");
    }

    LCA_TOPIC("Tracking::PlotWithRelatedTracks",1,0);
};

}
}
#endif