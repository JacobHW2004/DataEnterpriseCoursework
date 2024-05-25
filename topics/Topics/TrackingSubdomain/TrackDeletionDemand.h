#ifndef TRACK_DELETION_DEMAND
#define TRACK_DELETION_DEMAND

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics {

    class TrackDeletionDemand {
    public:

        TrackDeletionDemand() = default;
        TrackDeletionDemand(std::uint32_t track_id): track_id(track_id)
        {}

        std::uint32_t track_id{ 0 };

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(track_id, "track_id");
        }

        LCA_TOPIC("TrackDeletionDemand", 1, 0)

    };

}


#endif