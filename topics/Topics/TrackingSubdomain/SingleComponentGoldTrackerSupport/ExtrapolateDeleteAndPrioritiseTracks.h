#ifndef EXTRAPOLATE_DELETE_AND_PRIORITISE_TRACKS_H
#define EXTRAPOLATE_DELETE_AND_PRIORITISE_TRACKS_H
#include <algorithm>
#include <cstdint>
#include <vector>
#include "Fabric/Utils/LCA_Macros.h"
#include "OwnshipAndFrame0Nav.h"

namespace Topics {
namespace MVP_Tracking {
// Namespace for preliminary topics that drive the MVP single-component tracker in command form

class ExtrapolateDeleteAndPrioritiseTracks {
public:
    std::uint32_t message_diagnostic_id {0};
    double        extrapolation_time    {0.0};

    OwnshipAndFrame0Nav nav_data {};

    std::vector<double> quality_deletion_threshold_vector {}; // length 0-70
    
    ExtrapolateDeleteAndPrioritiseTracks() = default;
    ExtrapolateDeleteAndPrioritiseTracks(std::uint32_t message_diagnostic_id,
                                         double extrapolation_time,
                                         const OwnshipAndFrame0Nav& nav_data,
                                         const std::vector<double>& quality_deletion_threshold_vector)
        : message_diagnostic_id(message_diagnostic_id),
          extrapolation_time(extrapolation_time),
          nav_data(nav_data),
          quality_deletion_threshold_vector(quality_deletion_threshold_vector)
    {}

    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(message_diagnostic_id, "message_diagnostic_id");
        archive.Serialise(extrapolation_time, "extrapolation_time");
        archive.Serialise(nav_data, "nav_data");
        archive.Serialise(quality_deletion_threshold_vector,"threshold","quality_deletion_threshold_vector");
    }

    LCA_TOPIC("ExtrapolateDeleteAndPrioritiseTracks",1,0);
};

}
}

#endif