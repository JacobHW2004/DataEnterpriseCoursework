#ifndef WAVEFORMMETADATA_H
#define WAVEFORMMETADATA_H

#include "Fabric/Utils/LCA_Macros.h"

#include "ChannelId.h"
#include "UVSightline.h"

#include "SIRadian.h"
#include "SIHertz.h"

namespace Topics {
    namespace SipTopics {

        class WaveformMetadata {
        public:

            std::uint32_t  burstId{ 0 };
            std::uint32_t  dwellId{ 0 };
            std::uint32_t  burstInDwellIndex { 0 };
            SI::SIHertz    prf{ 0.0 };
            std::uint16_t  numberOfPulses{ 0 };
            ChannelID      channelId{};
            UVSightline    sightline{};
            SI::SIRadian   beamHalfWidth{ 0.0 };
            std::uint32_t  numberOfRangeGates{ 0 };
            std::uint32_t  numberOfDopplerBins{ 0 };
            float          wavelength { 0.0 };
            float          rangeGateWidth { 0.0 };
            std::uint32_t  numberOfFoldedRangeGates { 0 };
            WaveformMetadata() = default;

            WaveformMetadata(std::uint32_t burstId, std::uint32_t dwellId, std::uint32_t burstInDwellIndex, SI::SIHertz prf, std::uint16_t numberOfPulses, ChannelID channelId,
                             UVSightline sightline, SI::SIRadian beamHalfWidth, std::uint32_t numberOfRangeGates, std::uint32_t numberOfDopplerBins, float wavelengthIn, float rangeGateWidthIn, std::uint32_t numberOfFoldedRangeGatesIn) :
                burstId(burstId),
                dwellId(dwellId),
                burstInDwellIndex(burstInDwellIndex),
                prf(prf),
                numberOfPulses(numberOfPulses),
                channelId(channelId),
                sightline(sightline),
                beamHalfWidth(beamHalfWidth),
                numberOfRangeGates(numberOfRangeGates),
                numberOfDopplerBins(numberOfDopplerBins),
                wavelength(wavelengthIn),
                rangeGateWidth(rangeGateWidthIn),
                numberOfFoldedRangeGates(numberOfFoldedRangeGatesIn)
            {}

            template <class T>
            void Serialise(T& archive) {
                
                /* Temporary variables to allow serialization of SI-unit members */
                double prfDouble{ prf() };
                double beamHalfwidthDouble{ beamHalfWidth() };

                archive.Serialise(burstId,             "burstId");
                archive.Serialise(dwellId,             "dwellId");
                archive.Serialise(burstInDwellIndex,   "burstInDwellIndex");
                archive.Serialise(prfDouble,           "prf");
                archive.Serialise(numberOfPulses,      "numberOfPulses");
                archive.Serialise(channelId,           "channelId");
                archive.Serialise(sightline,           "sightline");
                archive.Serialise(beamHalfwidthDouble, "beamHalfWidth");
                archive.Serialise(numberOfRangeGates,  "numberOfRangeGates");
                archive.Serialise(numberOfDopplerBins, "numberOfDopplerBins");
                archive.Serialise(wavelength,          "wavelength");
                archive.Serialise(rangeGateWidth,      "rangeGateWidth");
                archive.Serialise(numberOfFoldedRangeGates, "numberOfFoldedRangeGates");
                
                /* After serialisation write values to SI-unit class members  */
                prf           = SI::SIHertz(prfDouble);
                beamHalfWidth = SI::SIRadian(beamHalfwidthDouble);

            }

            LCA_TOPIC("WaveformMetadata", 2, 0)

        }; // class WaveformMetadata

    }  // namespace SipTopics
}  // namespace Topics

#endif