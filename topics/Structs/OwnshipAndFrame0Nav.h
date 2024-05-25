#ifndef OWNSHIP_AND_FRAME_0_NAV_H
#define OWNSHIP_AND_FRAME_0_NAV_H
#include <vector>
#include <cstdint>

#include "Fabric/Utils/LCA_Macros.h"
namespace Topics{

class OwnshipAndFrame0Nav {
public:
    std::vector<double> ownship_position  {0.0,0.0,0.0}; // length 3
    std::vector<double> ownship_velocity  {0.0,0.0,0.0}; // length 3
    double frame0_origin_lat              {0.0};
    double frame0_origin_long             {0.0};
    double frame0_origin_alt              {0.0};
    double frame0_origin_time             {0.0};
    std::uint32_t frame0_origin_update_id {0};

    OwnshipAndFrame0Nav() = default;
    OwnshipAndFrame0Nav(const std::vector<double>& ownship_position,
                       const std::vector<double>& ownship_velocity,
                       double frame0_origin_lat,
                       double frame0_origin_long,
                       double frame0_origin_alt,
                       double frame0_origin_time,
                       std::uint32_t frame0_origin_update_id)
        : ownship_position(ownship_position),
          ownship_velocity(ownship_velocity),
          frame0_origin_lat(frame0_origin_lat),
          frame0_origin_long(frame0_origin_long),
          frame0_origin_alt(frame0_origin_alt),
          frame0_origin_time(frame0_origin_time),
          frame0_origin_update_id(frame0_origin_update_id)
    {}

    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(ownship_position, "coordinate","ownship_position");
        archive.Serialise(ownship_velocity, "velocity_component", "ownship_velocity");
        archive.Serialise(frame0_origin_lat, "frame0_origin_lat");
        archive.Serialise(frame0_origin_long, "frame0_origin_long");
        archive.Serialise(frame0_origin_alt, "frame0_origin_alt");
        archive.Serialise(frame0_origin_time, "frame0_origin_time");
        archive.Serialise(frame0_origin_update_id, "frame0_origin_update_id");
    }

    LCA_TOPIC("OwnshipAndFrame0Nav",1,0);
};

}
#endif