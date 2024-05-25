#ifndef FRAME_H
#define FRAME_H
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {


struct Frame
{
    double azCentre{ 0.0 };
    double azHalfWidth{ 0.0 };
    double elCentre{ 0.0 };
    double elHalfWidth{ 0.0 };

	bool operator==(const Frame& other) const {
		return azCentre == other.azCentre && azHalfWidth == other.azHalfWidth &&
			elCentre == other.elCentre && elHalfWidth == other.elHalfWidth;
	}

	bool operator!=(const Frame& other) const {
		return azCentre != other.azCentre && azHalfWidth != other.azHalfWidth &&
			elCentre != other.elCentre && elHalfWidth != other.elHalfWidth;
	}

	/**
    * @brief Serialise function required for communications
    */
    template <class T>
    void Serialise(T& archive) {

        archive.Serialise(azCentre, "azCentre");
        archive.Serialise(azHalfWidth, "azHalfWidth");
        archive.Serialise(elCentre, "elCentre");
		archive.Serialise(elHalfWidth, "elHalfWidth");

    }
    LCA_TOPIC("Frame", 1, 0)

};

} // namespace Topics

#endif

