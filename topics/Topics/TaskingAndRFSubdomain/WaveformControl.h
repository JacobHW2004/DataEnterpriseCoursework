#ifndef WAVEFORM_CONTROL_H
#define WAVEFORM_CONTROL_H

#include <stdint.h>

namespace Topics
{
    constexpr uint32_t MAX_NUMBER_OF_PULSES { 128 };
    constexpr uint32_t MAX_NUMBER_OF_CHIRPS {   1 };
    
    struct WaveformControl
    {
        // TIQDG Radar Data
        float     wavelength;
        uint32_t  sumPatternType;
        uint32_t  guardPatternType;
        uint32_t  numberOfChannels;
        
        // TIQDG Waveform Data
        uint32_t  prfId;
        float     bandwidth;
        uint32_t  filterType;
        float     rx;
        float     digitiserRate;
        uint32_t  numBits;
        uint32_t  numPrfs;
        float     tx;
        float     prf;
        uint32_t  startRangeGate;
        uint32_t  endRangeGate;
        uint32_t  invalidRangeGates;
        uint32_t  fftSize;
        uint32_t  csd;
        uint32_t  pulseCompStart;
        uint32_t  pulseCompEnd;
        float     pulseCompRatio;
        float     sampleInterval;
        float     pulsePhase[MAX_NUMBER_OF_PULSES];
        uint32_t  numChirps;
        uint32_t  chirpList[MAX_NUMBER_OF_CHIRPS];
        uint32_t  chirp;
        float     oversamplingFactor;
        float     numSamples;
        float     pulseAmp[MAX_NUMBER_OF_PULSES];
        uint32_t  rangeSamples;
        uint32_t  pris;
        uint32_t  bcsd;
        uint32_t  channelConfiguration;
        
        float     beamAzimuth;
        float     beamElevation;
        float     beamHalfwidth;
    };
}

#endif
