#ifndef RDMAP_REQUEST_TOPIC_H
#define RDMAP_REQUEST_TOPIC_H

#include <string>
#include "Fabric/Utils/LCA_Macros.h"
#include "IQData.h"
#include "SyntheticWaveform.h"

#include "WindowType.h"
#include "WaveformMetadata.h"

namespace Topics {

    class ApplyCoherentIntegrationTopic {
    public:

        IQData              iq_data;
        SyntheticWaveform   waveform;
        double              prf  {0};
        WindowType          doppler_window = WindowType::WindowType_rectwin;

        SipTopics::WaveformMetadata metadata;


        ApplyCoherentIntegrationTopic() = default;

        ApplyCoherentIntegrationTopic(const IQData& iq, const SyntheticWaveform& synthetic_waveform, double pulse_repetition_freq, const WindowType& doppler_window_func, SipTopics::WaveformMetadata metadata_in) :
            iq_data(iq),
            waveform(synthetic_waveform),
            prf(pulse_repetition_freq),
            doppler_window(doppler_window_func),
            metadata(metadata_in) {};


        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(iq_data, "iq_data");
            archive.Serialise(waveform, "waveform");
            archive.Serialise(prf, "pulse_repetition_frequency");
            archive.Serialise(doppler_window, "doppler_window");
            archive.Serialise(metadata, "metadata");
        }

        LCA_TOPIC("ApplyCoherentIntegrationTopic", 1, 0)

    };

}  // namespace Topics

#endif