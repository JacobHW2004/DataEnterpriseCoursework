
#ifndef DWELL_H
#define DWELL_H
#include "Fabric/Utils/LCA_Macros.h"
#include "SIRadian.h"
#include "Sightline.h"

#include <cstdint>

namespace Topics {

struct Dwell
{
	std::int32_t internalTaskID{0};
	Sightline sightline{};
	SI::SIRadian beamHalfWidth{0.0};
	std::string waveformID{""};

	bool operator==(const Dwell& other) const {
		return internalTaskID == other.internalTaskID && 
			   sightline == other.sightline && 
			   beamHalfWidth == other.beamHalfWidth &&
			   waveformID == other.waveformID;
	}

	/**
    * @brief Serialise function required for communications
    */
    template <class T>
	void Serialise(T& archive) {

		/* Temporary variables to allow serialization of SIRadians */
		double beamHalfWidthDouble{ beamHalfWidth() };

		archive.Serialise(internalTaskID, "internalTaskID");
		archive.Serialise(sightline, "sightline");
		archive.Serialise(beamHalfWidthDouble, "beamHalfWidth");
		archive.Serialise(waveformID, "waveformID");

		/* Temporary trick to get SIRadian to serialise */
		beamHalfWidth = beamHalfWidthDouble;
	}
	LCA_TOPIC("Dwell", 1, 0)


};

} // namespace Topics

#endif

