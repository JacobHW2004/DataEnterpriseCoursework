#ifndef REPLAY_SUPPORT_PLOT_REPORT
#define REPLAY_SUPPORT_PLOT_REPORT
#include <cstdint>
#include <vector>

#include "Fabric/Utils/LCA_Macros.h"
#include "ReplaySupport_PlotParameters.h"

namespace Topics {
    namespace TrackingDomainReplaySupport {

        class ReplaySupport_PlotReport {
        public:

            std::uint8_t dwell_type{ 0 };
            double       target_amplitude{ 0.0 };
            double       SNR{ 0.0 };

            std::vector<double> ownship_position_vector{ 0.0, 0.0, 0.0 }; //Length 3
            std::vector<double> ownship_velocity_vector{ 0.0, 0.0, 0.0 }; //Length 3

            ReplaySupport_PlotParameters plot_parameters;

            ReplaySupport_PlotReport() = default;

            ReplaySupport_PlotReport(
                std::uint8_t dwell_type,
                double target_amplitude,
                double SNR,
                const std::vector<double>& ownship_position_vector,
                const std::vector<double>& ownship_velocity_vector,
                ReplaySupport_PlotParameters plot_parameters)

            : dwell_type(dwell_type),
              target_amplitude(target_amplitude),
              SNR(SNR),
              ownship_position_vector(ownship_position_vector),
              ownship_velocity_vector(ownship_velocity_vector),
              plot_parameters(plot_parameters)

            {}

            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(dwell_type, "dwell_type");
                archive.Serialise(target_amplitude, "target_amplitude");
                archive.Serialise(SNR, "SNR");
                archive.Serialise(ownship_position_vector, "position", "ownship_position_vector");
                archive.Serialise(ownship_velocity_vector, "velocity", "ownship_velocity_vector");
                archive.Serialise(plot_parameters, "plot_parameters");
            }

            LCA_TOPIC("ReplaySupport_PlotReport", 1, 0);
        };
    }

}

#endif