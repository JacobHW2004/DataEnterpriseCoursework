// WaveformControl.h : Defines the Waveform Control Topic 
#ifndef WAVEFORM_CONTROL_TOPIC_H
#define WAVEFORM_CONTROL_TOPIC_H

#include <stdint.h>

#include "Fabric/Utils/LCA_Macros.h"

#include "WaveformControl.h"

namespace Topics 
{
    class WaveformControlTopic {
    
    private:
        WaveformControl waveformControl;
    
    public:
        WaveformControlTopic() :
            waveformControl {0}
        {}
        
        
        WaveformControlTopic(const WaveformControl &structWaveformControl) :
            waveformControl{structWaveformControl}
        {}
        
        
        WaveformControl getWaveformControl() const 
        {
            return waveformControl;
        }
        
        
        template<class T>
        void Serialise(T& archive)
        {
            archive.Serialise(waveformControl.wavelength,            "wavelength");
            archive.Serialise(waveformControl.sumPatternType,        "sumPatternType");
            archive.Serialise(waveformControl.guardPatternType,      "guardPatternType");
            archive.Serialise(waveformControl.numberOfChannels,      "numberOfChannels");
            
            archive.Serialise(waveformControl.prfId,                 "prfId");
            archive.Serialise(waveformControl.bandwidth,             "bandwidth");
            archive.Serialise(waveformControl.filterType,            "filterType");
            archive.Serialise(waveformControl.rx,                    "rx");
            archive.Serialise(waveformControl.digitiserRate,         "digitiserRate");
            archive.Serialise(waveformControl.numBits,               "numBits");
            archive.Serialise(waveformControl.numPrfs,               "numPrfs");
            archive.Serialise(waveformControl.tx,                    "tx");
            archive.Serialise(waveformControl.prf,                   "prf");
            archive.Serialise(waveformControl.startRangeGate,        "startRangeGate");
            archive.Serialise(waveformControl.endRangeGate,          "endRangeGate");
            archive.Serialise(waveformControl.invalidRangeGates,     "invalidRangeGates");
            archive.Serialise(waveformControl.fftSize,               "fftSize");
            archive.Serialise(waveformControl.csd,                   "csd");
            archive.Serialise(waveformControl.pulseCompStart,        "pulseCompStart");
            archive.Serialise(waveformControl.pulseCompEnd,          "pulseCompEnd");
            archive.Serialise(waveformControl.pulseCompRatio,        "pulseCompRatio");
            archive.Serialise(waveformControl.sampleInterval,        "sampleInterval");
            for (uint8_t p = 0; p < MAX_NUMBER_OF_PULSES; p++)
            {
                archive.Serialise(waveformControl.pulsePhase[p],     "pulsePhase[" + std::to_string(p) + "]");
            }
            archive.Serialise(waveformControl.numChirps,             "numChirps");
            for (uint8_t c = 0; c < MAX_NUMBER_OF_CHIRPS; c++)
            {
                archive.Serialise(waveformControl.chirpList[c],      "chirpList[" + std::to_string(c) + "]");
            }
            archive.Serialise(waveformControl.chirp,                 "chirp");
            archive.Serialise(waveformControl.oversamplingFactor,    "oversamplingFactor");
            archive.Serialise(waveformControl.numSamples,            "numSamples");
            for (uint8_t p = 0; p < MAX_NUMBER_OF_PULSES; p++)
            {
                archive.Serialise(waveformControl.pulseAmp[p],       "pulseAmp[" + std::to_string(p) + "]");
            }
            archive.Serialise(waveformControl.rangeSamples,          "rangeSamples");
            archive.Serialise(waveformControl.pris,                  "pris");
            archive.Serialise(waveformControl.bcsd,                  "bcsd");
            archive.Serialise(waveformControl.channelConfiguration,  "channelConfiguration");
            
            archive.Serialise(waveformControl.beamAzimuth,           "beamAzimuth");
            archive.Serialise(waveformControl.beamElevation,         "beamElevation");
            archive.Serialise(waveformControl.beamHalfwidth,         "beamHalfwidth");
        }
        
        
        LCA_TOPIC("WaveformControlTopic", 0, 1)
    };
}
#endif
