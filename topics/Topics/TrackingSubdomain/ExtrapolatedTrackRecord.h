#ifndef EXTRAPOLATED_TRACK_RECORD_H
#define EXTRAPOLATED_TRACK_RECORD_H

#include <cstdint>

#include "SISecond.h"
#include "TrackRecord.h"

#include "Fabric/Utils/LCA_Macros.h"


namespace Topics{

class ExtrapolatedTrackRecord {
public:

    SI::SISecond        extrapolation_time  {0.0};
    Topics::TrackRecord track_record        {};
    
    ExtrapolatedTrackRecord() = default;

    ExtrapolatedTrackRecord(SI::SISecond extrapolation_time,
                            TrackRecord track_record)
    : extrapolation_time(extrapolation_time),
      track_record(track_record) 
    {}
    
    template <class T>
    void Serialise(T& archive) {

        /* Temporary variables to allow serialization of SI-unit members */
        double extrapolation_time_double{ extrapolation_time() };

        archive.Serialise(extrapolation_time_double,"extrapolation_time");
        archive.Serialise(track_record,             "track_record");

        /* After serialisation write values to SI-unit class members  */
        extrapolation_time      = SI::SISecond(extrapolation_time_double);

    }

    LCA_TOPIC("ExtrapolatedTrackRecord",1,0);
};

}
#endif