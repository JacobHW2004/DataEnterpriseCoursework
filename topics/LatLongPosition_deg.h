#ifndef LATLONGPOSITION_DEG_H
#define LATLONGPOSITION_DEG_H

namespace Topics {

struct LatLongPosition_deg
{
   //deg - degrees
   double latitude_deg{0};
   double longitude_deg{0};
   bool isValid{false};
   

   LatLongPosition_deg() {};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(latitude_deg, "latitude_deg");
      archive.Serialise(longitude_deg, "longitude_deg");
      archive.Serialise(isValid, "isValid");
  }

   LCA_TOPIC("LatLongPosition_deg", 1, 0)
   

};

}  // namespace Topics

#endif
