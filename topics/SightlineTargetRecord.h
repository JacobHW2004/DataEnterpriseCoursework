#ifndef SIGHTLINE_TARGET_RECORD_H
#define SIGHTLINE_TARGET_RECORD_H

#include <array>
#include <cstdint>

#include "Fabric/Utils/LCA_Macros.h"
#include "Sightline.h"
#include "SIMeter.h"
#include "SIMeterPerSecond.h"
#include "SIMeterSquaredPerSecondSquared.h"
#include "SISecond.h"

namespace Topics {

    constexpr std::uint8_t MAXIMUM_NUMBER_OF_RANGE_RATES{ 4U };

    class SightlineTargetRecord {

    public:

        Topics::Sightline       sightline{};
        std::uint8_t            numberOfRangeRates{ 0 };
        SI::SIMeter             range{ 0.0 };
        // rangeRates and rateUncertainties are both initialised to hold the same number of value
        std::array<SI::SIMeterPerSecond, MAXIMUM_NUMBER_OF_RANGE_RATES>               rangeRates{ SI::SIMeterPerSecond(0.0), SI::SIMeterPerSecond(0.0), SI::SIMeterPerSecond(0.0), SI::SIMeterPerSecond(0.0) };
        std::array<SI::SIMeterSquaredPerSecondSquared, MAXIMUM_NUMBER_OF_RANGE_RATES> rateUncertainties{ SI::SIMeterSquaredPerSecondSquared(0.0), SI::SIMeterSquaredPerSecondSquared(0.0), SI::SIMeterSquaredPerSecondSquared(0.0), SI::SIMeterSquaredPerSecondSquared(0.0) };
        
        SI::SISecond            detectionTime{ 0.0 };
        float                   amplitude{ 0.0 };
        float                   snr{ 0.0 };

        SightlineTargetRecord() = default;

        SightlineTargetRecord(
            Topics::Sightline       sightline,
            std::uint8_t            numberOfRangeRates,
            SI::SIMeter             range,
            std::array<SI::SIMeterPerSecond, MAXIMUM_NUMBER_OF_RANGE_RATES>                 rangeRates,
            std::array<SI::SIMeterSquaredPerSecondSquared, MAXIMUM_NUMBER_OF_RANGE_RATES>   rateUncertainties,
            SI::SISecond    detectionTime,
            float           amplitude,
            float           snr
        )
            :sightline(sightline),
            numberOfRangeRates(numberOfRangeRates),
            range(range),
            rangeRates(rangeRates),
            rateUncertainties(rateUncertainties),
            detectionTime(detectionTime),
            amplitude(amplitude),
            snr(snr)
        {}

        template <class T>
        void Serialise(T& archive) {
            double doubleRange{ range() };
            double doubleDetectionTime{ detectionTime() };

            std::array<double, MAXIMUM_NUMBER_OF_RANGE_RATES> rangeRateDouble{};
            std::array<double, MAXIMUM_NUMBER_OF_RANGE_RATES> rateUncertaintiesDouble{};
            
            archive.Serialise(sightline, "sightline");
            archive.Serialise(numberOfRangeRates, "numberOfRangeRates");
            archive.Serialise(doubleRange, "range");

            for (std::uint8_t i{ 0 }; i < MAXIMUM_NUMBER_OF_RANGE_RATES; i++) {

                rangeRateDouble[i] = rangeRates[i]();

                archive.Serialise(rangeRateDouble[i], "rangeRate[" + std::to_string(i) + "]");
            }

            for (std::uint8_t i{ 0 }; i < MAXIMUM_NUMBER_OF_RANGE_RATES; i++) {

                rateUncertaintiesDouble[i] = rateUncertainties[i]();

                archive.Serialise(rateUncertaintiesDouble[i], "rateUncertainties[" + std::to_string(i) + "]");
            }

            archive.Serialise(doubleDetectionTime, "detectionTime");
            archive.Serialise(amplitude, "amplitude");
            archive.Serialise(snr, "snr");

            // Assign back to SIUnits for de-serialisation
            range = doubleRange;
            detectionTime = doubleDetectionTime;

            for (std::uint8_t i{ 0 }; i < MAXIMUM_NUMBER_OF_RANGE_RATES; i++) {

                rangeRates[i] = rangeRateDouble[i];
                rateUncertainties[i] = rateUncertaintiesDouble[i];
            }
        }

        LCA_TOPIC("SightlineTargetRecord", 1, 0);
    };
}
#endif
