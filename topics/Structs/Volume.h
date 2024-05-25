#ifndef VOLUME_H
#define VOLUME_H

#include "Frame.h"
#include "FrameOfReference.h"
#include "Fabric/Utils/LCA_Macros.h"


namespace Topics {

struct Volume
{
	Volume() = default;

	Volume(const Volume &v) : aFrame(v.aFrame), rangeUpper(v.rangeUpper), rangeLower(v.rangeLower), frameOfReference(v.frameOfReference) {}

	Volume(Frame aFrameIn, double rangeUpperIn, double rangeLowerIn, FrameOfReference frameOfReferenceIn) :
		aFrame(aFrameIn),
		rangeUpper(rangeUpperIn),
		rangeLower(rangeLowerIn),
        frameOfReference(frameOfReferenceIn)
	{}

	inline bool operator==(Volume comp) {
		return ((comp.rangeLower == rangeLower) && (comp.rangeUpper == rangeUpper) &&
			(comp.aFrame.azCentre == aFrame.azCentre) && (comp.aFrame.elCentre == aFrame.elCentre) &&
			(comp.aFrame.azHalfWidth == aFrame.azHalfWidth) && (comp.aFrame.elHalfWidth == aFrame.elHalfWidth) &&
            (comp.frameOfReference == frameOfReference));
		}
	
	inline bool operator!=(Volume comp) {
        return !(comp == *this);
	}

	Frame aFrame;
    double rangeUpper{ 0.0 };
	double rangeLower{ 0.0 };
    FrameOfReference frameOfReference{ FrameOfReference::FRAME_2 };

	/**
    * @brief Serialise function required for communications
    */
    template <class T>
    void Serialise(T& archive) {

        archive.Serialise(aFrame, "aFrame");
        archive.Serialise(rangeUpper, "rangeUpper");
        archive.Serialise(rangeLower, "rangeLower");
        archive.Serialise(frameOfReference, "frameOfReference");

    }
	LCA_TOPIC("Volume", 1, 0)
};

} // namespace Topics

#endif

