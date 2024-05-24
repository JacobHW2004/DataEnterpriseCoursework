#ifndef FEILD_OF_VIEW_H
#define FEILD_OF_VIEW_H
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

/**
 * @brief This struct represents the radars field of view which is stored here as an ellipse
 * 
 */
struct FieldOfView
{

    FieldOfView() = default;

	FieldOfView(float azCentre, float elCentre, float azHalfWidth, float elHalfwidth) :
		azCentre(azCentre),
		elCentre(elCentre),
		azHalfWidth(azHalfWidth),
        elHalfWidth(elHalfwidth)
	{}

    float azCentre;
    float azHalfWidth;
    float elCentre;
    float elHalfWidth;

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

    LCA_TOPIC("FieldOfView", 1, 0)

};

} // namespace Topics

#endif

