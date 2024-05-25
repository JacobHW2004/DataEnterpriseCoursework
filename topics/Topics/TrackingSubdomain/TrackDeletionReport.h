#ifndef TRACK_DELETION_REPORT
#define TRACK_DELETION_REPORT

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics {

    enum class DeletionOutcome : uint8_t {
        SUCCESSFUL              = 0,
        UNSUCCESSFUL_INVALID_ID = 1,
        LCA_ERROR_NO_RESPONSE   = 2
    };

    class TrackDeletionReport {
    public:


        TrackDeletionReport() = default;
        TrackDeletionReport(std::uint32_t track_id, DeletionOutcome outcome) : track_id(track_id), outcome(outcome) 
        {}

        std::uint32_t   track_id{ 0 };
        DeletionOutcome outcome{ DeletionOutcome::UNSUCCESSFUL_INVALID_ID };

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(track_id, "track_id");
            archive.Serialise(outcome,  "outcome");
        }

        LCA_TOPIC("TrackDeletionReport", 1, 0)

    };

}


#endif
