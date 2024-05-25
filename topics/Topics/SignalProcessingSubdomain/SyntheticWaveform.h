#ifndef SYNTHETIC_WAVEFORM_H
#define SYNTHETIC_WAVEFORM_H
#include <vector>
#include <cstdint>

#include "Fabric/Utils/LCA_Macros.h"
namespace Topics{

class SyntheticWaveform {
public:

    double pulse_length              { 0.0 };
    double pulse_bandwidth           { 0.0 };
    double sampling_frequency        { 0.0 };
    double centre_frequency          { 0.0 };
    double amplitude_scale_factor     { 0.0 };


    SyntheticWaveform() = default;
    SyntheticWaveform(double pulse_length,
            double pulse_bandwidth,
            double sampling_frequency,
            double centre_frequency,
            double amplitude_scale_factor)
        : pulse_length(pulse_length),
        pulse_bandwidth(pulse_bandwidth),
        sampling_frequency(sampling_frequency),
        centre_frequency(centre_frequency),
        amplitude_scale_factor(amplitude_scale_factor){}

    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(pulse_length, "pulse_length");
        archive.Serialise(pulse_bandwidth, "pulse_bandwidth");
        archive.Serialise(sampling_frequency, "sampling_frequency");
        archive.Serialise(centre_frequency, "centre_frequency");
        archive.Serialise(amplitude_scale_factor, "amplitude_scale_factor");
    }

    LCA_TOPIC("SyntheticWaveform",1,0);
};

}
#endif