#ifndef SIP_TARGET_RECORD_H
#define SIP_TARGET_RECORD_H
#include <vector>
#include <cstdint>

#include "Fabric/Utils/LCA_Macros.h"

#include "SIMeterSquaredPerSecondSquared.h"
#include "SISecond.h"
#include "SIMeter.h"
#include "SIMeterPerSecond.h"
#include "SIMeterSquared.h"
#include "UVSightline.h"
#include "UVMonopulseCorrection.h"

namespace Topics {
    namespace SipTopics {

        class SipTargetRecord {
        public:
            std::uint32_t targetId{ 0U };
            std::uint32_t dwellId { 0U };
            std::uint32_t modeId  { 0U };
            SI::SISecond  detectionTime{ 0.0F };

            float         amplitude{ 0.0F };
            float         snr{ 0.0F };
            float         snrNormalised{ 0.0F };

            SI::SIMeter                          range{ 0.0F };
            SI::SIMeterSquared                   rangeVariance{ 0.0F };
            SI::SIMeterPerSecond                 rangeRate{ 0.0F };
            SI::SIMeterSquaredPerSecondSquared   rangeRateVariance{ 0.0F };

            std::uint32_t numberOfAlarms{ 0 };

            // Sightline information for each alarm. Sightlines are per alarm rather than per burst
            // as there can be multiple contributing alarms in each burst and this saves time tying
            // the alarm to the corresponding burst sightline.  
            std::vector<UVSightline>           alarmSightlines{};
            std::vector<UVMonopulseCorrection> monopulseCorrections{};

            // This is currently diagnostic information
            std::uint32_t numberOfAltitudeLineAlarms{ 0U };
            std::uint32_t numberOfGroundMoverAlarms { 0U };

            std::vector<std::uint32_t> alarmIds{};
            std::vector<std::uint32_t> alarmBurstIds{};
            std::vector<std::uint32_t> alarmRangeGates{};
            std::vector<std::uint32_t> alarmDopplerBins{};

            SipTargetRecord() = default;

            SipTargetRecord(
                std::uint32_t targetId,
                std::uint32_t dwellId,
                std::uint32_t modeId,
                SI::SISecond  detectionTime,

                float         amplitude,
                float         snr,
                float         snrNormalised,

                SI::SIMeter                        range,
                SI::SIMeterSquared                 rangeVariance,
                SI::SIMeterPerSecond               rangeRate,
                SI::SIMeterSquaredPerSecondSquared rangeRateVariance,

                std::vector<UVSightline>           alarmSightlines,
                std::vector<UVMonopulseCorrection> monopulseCorrections,

                std::uint32_t numberOfAlarms,
                std::uint32_t numberOfAltitudeLineAlarms,
                std::uint32_t numberOfGroundMoverAlarms,

                std::vector<std::uint32_t> alarmIds,
                std::vector<std::uint32_t> alarmBurstIds,
                std::vector<std::uint32_t> alarmRangeGates,
                std::vector<std::uint32_t> alarmDopplerBins
            )
                :targetId(targetId),
                dwellId(dwellId),
                modeId(modeId),
                detectionTime(detectionTime),

                amplitude(amplitude),
                snr(snr),
                snrNormalised(snrNormalised),

                range(range),
                rangeVariance(rangeVariance),
                rangeRate(rangeRate),
                rangeRateVariance(rangeRateVariance),

                alarmSightlines(alarmSightlines),
                monopulseCorrections(monopulseCorrections),

                numberOfAlarms(numberOfAlarms),
                numberOfAltitudeLineAlarms(numberOfAltitudeLineAlarms),
                numberOfGroundMoverAlarms(numberOfGroundMoverAlarms),

                alarmIds(alarmIds),
                alarmBurstIds(alarmBurstIds),
                alarmRangeGates(alarmRangeGates),
                alarmDopplerBins(alarmDopplerBins)
            {}

            template <class T>
            void Serialise(T& archive) {

                double doubleDetectionTime{ detectionTime() };
                double doubleRange{ range() };
                double doubleRangeVariance{ rangeVariance() };
                double doubleRangeRate{ rangeRate() };
                double doubleRangeRateVariance{ rangeRateVariance() };

                archive.Serialise(targetId, "targetId");
                archive.Serialise(dwellId, "dwellId");
                archive.Serialise(modeId, "modeId");
                archive.Serialise(doubleDetectionTime, "detectionTime");

                archive.Serialise(amplitude, "amplitude");
                archive.Serialise(snr, "snr");
                archive.Serialise(snrNormalised, "snrNormalised");

                archive.Serialise(doubleRange, "range");
                archive.Serialise(doubleRangeVariance, "rangeVariance");
                archive.Serialise(doubleRangeRate, "rangeRate");
                archive.Serialise(doubleRangeRateVariance, "rangeRateVariance");

                archive.Serialise(alarmSightlines, "alarmSightline", "alarmSightlines");
                archive.Serialise(monopulseCorrections, "monopulseCorrection", "monopulseCorrections");

                archive.Serialise(numberOfAlarms, "numberOfAlarms");
                archive.Serialise(numberOfAltitudeLineAlarms, "numberOfAltitudeLineAlarms");
                archive.Serialise(numberOfGroundMoverAlarms, "numberOfGroundMoverAlarms");

                archive.Serialise(alarmIds, "alarmId", "alarmIds");
                archive.Serialise(alarmBurstIds, "alarmBurstId", "alarmBurstIds");
                archive.Serialise(alarmRangeGates, "alarmRangeGate", "alarmRangeGates");
                archive.Serialise(alarmDopplerBins, "alarmDopplerBin", "alarmDopplerBins");

                // Assign back to SIUnits for de-serialisation
                detectionTime     = doubleDetectionTime;
                range             = doubleRange;
                rangeVariance     = doubleRangeVariance;
                rangeRate         = doubleRangeRate;
                rangeRateVariance = doubleRangeRateVariance;
            }

            LCA_TOPIC("SipTargetRecord", 3, 0);
        };
    }
}
#endif