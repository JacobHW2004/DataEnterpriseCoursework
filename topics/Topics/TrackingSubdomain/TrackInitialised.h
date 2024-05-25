#ifndef TRACK_INITIALISED_H
#define TRACK_INITIALISED_H

#include "Fabric/Utils/LCA_Macros.h"

#include "TrackRecord.h"
#include "AssociationToken.h"

namespace Topics {

    class TrackInitialised {
    public:

        TrackRecord      initialisedTrack{};
        AssociationToken associationToken{};

        TrackInitialised() = default;

        TrackInitialised(const TrackRecord& aTrackRecord, const AssociationToken& anAssociationToken) : 
            initialisedTrack(aTrackRecord),
            associationToken(anAssociationToken)
        {}

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(initialisedTrack, "initialisedTrack");
            archive.Serialise(associationToken, "associationToken");
        }

        LCA_TOPIC("TrackInitialised", 1, 0);
    };

}

#endif
