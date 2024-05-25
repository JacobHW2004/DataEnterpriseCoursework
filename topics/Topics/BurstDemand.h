#ifndef BURST_DEMAND_H
#define BURST_DEMAND_H
#include "Fabric/Utils/LCA_Macros.h"

#include "AntennaBeamCharacteristics.h"
#include "Fabric/Utils/LCA_Macros.h"
#include "FrameContext.h"
#include "RadarMeasurementIntervalPhase.h"
#include "Tick.h"

#include <cstdint>

namespace Topics {


    struct BurstDemand
    {
        /**
         * @brief Topic struct to hold the representation of a burst demand
         * 
         */
        
        FrameContext frameContext;
        std::uint32_t dwellID{ 0 };
        Tick pulseRepetitionInterval{ 0, 0.0 };
        AntennaBeamCharacteristics antennaBeam;
        RadarMeasurementIntervalPhase rmiPhase;
        std::uint32_t numberOfCsdPris{ 0 };
        Tick samplingInterval{ 0, 0.0 };
        std::uint32_t txPulseWidth{ 0 };
        std::uint32_t numberOfBurstsInDwell{ 0 };
        

        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {

            archive.Serialise(frameContext, "frameContext");
            archive.Serialise(dwellID, "dwellID");
            archive.Serialise(pulseRepetitionInterval, "pulseRepetitionInterval");
            archive.Serialise(antennaBeam, "antennaBeam");
            archive.Serialise(rmiPhase, "rmiPhase");
            archive.Serialise(numberOfCsdPris, "numberOfCsdPris");
            archive.Serialise(samplingInterval, "samplingInterval");
            archive.Serialise(txPulseWidth, "txPulseWidth");
            archive.Serialise(numberOfBurstsInDwell, "numberOfBurstsInDwell");
        }
        LCA_TOPIC("BurstDemand", 2, 0)


    };

} // namespace Topics

#endif

