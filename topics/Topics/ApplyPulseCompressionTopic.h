#ifndef APPLY_PULSE_COMPRESSION_H
#define APPLY_PULSE_COMPRESSION_H

#include <vector>
#include <cstdint>

#include "Fabric/Utils/LCA_Macros.h"

#include "IQData.h"
#include "SyntheticWaveform.h"
#include "WindowType.h"
#include "WaveformMetadata.h"

namespace Topics {

class ApplyPulseCompressionTopic {
public:

    IQData            iq_data;
    SyntheticWaveform waveform;
    WindowType        doppler_window = WindowType::WindowType_rectwin;
    std::uint32_t     fftSize{ 0 };
    std::uint32_t     prf{ 0 };

    SipTopics::WaveformMetadata metadata;

    ApplyPulseCompressionTopic() {};

    ApplyPulseCompressionTopic(IQData iqDataIn, SyntheticWaveform waveformIn, std::uint32_t fftSizeIn, std::uint32_t prfIn, SipTopics::WaveformMetadata metadataIn) :
        iq_data(iqDataIn),
        waveform(waveformIn),
        fftSize(fftSizeIn),
        prf(prfIn),
        metadata(metadataIn){};

    template <class T>
    void Serialise(T& archive) {
            archive.Serialise(iq_data,        "iq_data");
            archive.Serialise(waveform,       "waveform");
            archive.Serialise(doppler_window, "doppler_window");
            archive.Serialise(fftSize,        "fftSize");
            archive.Serialise(prf,            "prf");
            archive.Serialise(metadata,       "metadata");

    }

    LCA_TOPIC("ApplyPulseCompressionTopic", 1, 0)
 
};

}  // namespace Topics

#endif