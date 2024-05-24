#ifndef IQ_GENERATION_DATA_H
#define IQ_GENERATION_DATA_H

#include <cstdint>

#include "Fabric/Utils/LCA_Macros.h"
#include "FilterType.h"
#include "SIHertz.h"
#include "UVSightline.h"

namespace Topics {
    
    struct IQGenerationData
    {
        /**
         * @brief Topic to hold the fields required to drive the IQ data generation for a burst
         * 
         */

        std::uint32_t numPrfs{ 0 };                 /// The total number of PRFs in the current dwell
        SI::SIHertz digitiserRate{ 0.0 };
        std::uint32_t numBits{ 0 };                 /// Max length that can be output by the digitiser
        SI::SIHertz bandwidth{ 0.0 };
        UVSightline beamSightline {};
        double receivePulseWidth{ 0.0 };
        std::uint32_t numberOfChannels{ 0 };
        std::uint32_t channelConfiguration{ 0 };
        FilterType filterType { FilterType::GAUSSIAN };

        IQGenerationData() {};

        template<class T>
        void Serialise(T& archive)
        {
            double digitiserRateDouble{ digitiserRate() };
            double bandwidthDouble{ bandwidth() };

            
            archive.Serialise(numPrfs, "numPrfs");
            archive.Serialise(digitiserRateDouble, "digitiserRate");
            archive.Serialise(numBits, "numBits");
            archive.Serialise(bandwidthDouble, "bandwidth");
            archive.Serialise(beamSightline, "beamSightline");
            archive.Serialise(receivePulseWidth, "rxPulseWidth");
            archive.Serialise(numberOfChannels, "numberOfChannels");
            archive.Serialise(channelConfiguration, "channelConfiguration");
            archive.Serialise(filterType, "filterType");

            digitiserRate = SI::SIHertz{ digitiserRateDouble };
            bandwidth = SI::SIHertz{ bandwidthDouble };
        }

        LCA_TOPIC("IQGenerationData", 2, 0)

    };

} //end namespace Topics

#endif
