#ifndef TRACK_EXTRAPOLATION_RESPONSE_H
#define TRACK_EXTRAPOLATION_RESPONSE_H
#include <cstdint>
#include <vector>

#include "ExtrapolatedTrackRecord.h"
#include "Fabric/Utils/LCA_Macros.h"



namespace Topics {

    enum class TrackExtrapolationOutcome {
        SUCCESS,
        OLD_TIMETAG,
        INVALID_TIMETAG,
        NOT_EXTANT
    };

    class TrackExtrapolationResponse {
    public:

        ExtrapolatedTrackRecord extrapolated_track;
        TrackExtrapolationOutcome outcome =  TrackExtrapolationOutcome::SUCCESS;

        TrackExtrapolationResponse() = default;
        TrackExtrapolationResponse(ExtrapolatedTrackRecord extrapolated_track,
            TrackExtrapolationOutcome outcome)

        : extrapolated_track(extrapolated_track),
          outcome(outcome)
        {}

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(extrapolated_track, "extrapolated_track");
            archive.Serialise(outcome, "outcome");
        }

        LCA_TOPIC("TrackExtrapolationResponse", 1, 0);
    };
}

#endif