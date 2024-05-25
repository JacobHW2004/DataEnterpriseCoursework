#ifndef IQ_DATA_H
#define IQ_DATA_H
#include <vector>
#include <cstdint>

#include "Fabric/Utils/LCA_Macros.h"
namespace Topics{

class IQData {
public:
    std::vector<double> iq_samples{};
    std::uint32_t num_range_gates   {0};
    std::uint32_t num_doppler_bins  {0};


    IQData() = default;
    IQData(const std::vector<double>& iq_samples,
            std::uint32_t num_doppler_bins,
            std::uint32_t num_range_gates)
        : iq_samples(iq_samples),
        num_doppler_bins(num_doppler_bins),
        num_range_gates(num_range_gates)
    {}

    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(iq_samples, "iqd", "iq_samples");
        archive.Serialise(num_doppler_bins, "num_doppler_bins");
        archive.Serialise(num_range_gates, "num_range_gates");
    }

    LCA_TOPIC("IQData",1,0);
};

}
#endif