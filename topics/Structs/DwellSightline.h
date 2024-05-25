
#ifndef DWELLSIGHTLINE_H
#define DWELLSIGHTLINE_H
#include "Fabric/Utils/LCA_Macros.h"


namespace Topics {
	
///@deprecated This topic is now deprecated, please use Dwell.h and Sightline.h
struct DwellSightline
{
	float azimuth;
	float elevation;
	float beamHalfWidth;

	bool operator==(const DwellSightline& other) const {
		return azimuth == other.azimuth && elevation == other.elevation && 
			beamHalfWidth == other.beamHalfWidth;
	}

	/**
    * @brief Serialise function required for communications
    */
    template <class T>
	void Serialise(T& archive) {
		archive.Serialise(azimuth, "azimuth");
		archive.Serialise(elevation, "elevation");
		archive.Serialise(beamHalfWidth, "beamHalfWidth");
	}
	LCA_TOPIC("DwellSightline", 1, 0)


};

} // namespace Topics

#endif
