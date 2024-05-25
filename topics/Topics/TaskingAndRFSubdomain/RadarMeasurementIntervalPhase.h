#ifndef RADAR_MEASUREMENT_INTERVAL_PHASE_H
#define RADAR_MEASUREMENT_INTERVAL_PHASE_H

#include "Fabric/Utils/LCA_Macros.h"
#include "Tick.h"

#include <cstdint>

namespace Topics{

    struct RadarMeasurementIntervalPhase
    {
        /**
         * @brief Topic to hold the characteristics of a specific RMI phase setup within a given burst
         * 
         */
        
        std::uint32_t numberOfPris{ 0 };
        Tick samplingStart{ 0, 0.0 };
        Tick samplingEnd{ 0, 0.0 };

        /**
        * @brief Serialise/deserialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {

            archive.Serialise(numberOfPris, "numberOfPris");
            archive.Serialise(samplingStart, "samplingStart");
            archive.Serialise(samplingEnd, "samplingEnd");

        }

        LCA_TOPIC("RadarMeasurementIntervalPhase", 1, 0)
    };

}   //end namespace Topics

#endif