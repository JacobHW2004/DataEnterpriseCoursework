#ifndef BURST_IQ_SAMPLES_DATA_TOPIC_H
#define BURST_IQ_SAMPLES_DATA_TOPIC_H

#include <cstdint>
#include <vector>

#include "Fabric/Utils/LCA_Macros.h"
#include "FrameContext.h"
#include "ComplexFloat.h"
#include "RadarDataOrientation.h"

namespace Topics {

    class BurstIQSamplesDataTopic {
    public:

        /**
        * @brief Topic class to hold representation of IQ data for the Sum, Guard and Diff Channels
        */

        FrameContext  burst                  {};
        std::uint32_t numRangeGates          { 0 };
        std::uint32_t numPris                { 0 };
        RadarDataOrientation dataOrientation {};

        // Vectors used as size unknown at compile time and to avoid templates for serialisation
        // Ptrs cannot be used as data will cross containers and hardware
        std::vector<Topics::ComplexFloat> sumIqData  {};
        std::vector<Topics::ComplexFloat> guardIqData{};
        std::vector<Topics::ComplexFloat> diffUIqData  {};
        std::vector<Topics::ComplexFloat> diffVIqData  {};

        //  Default constuctor provided for LCA. Recommend initialising with another constructor as to improve efficiency
        BurstIQSamplesDataTopic() = default; 

        BurstIQSamplesDataTopic(FrameContext burstContext,
            std::uint32_t numRangeGates,
            std::uint32_t numPris,
            RadarDataOrientation dataOrientation,
            std::vector<Topics::ComplexFloat> &sumIqData,
            std::vector<Topics::ComplexFloat> &guardIqData,
            std::vector<Topics::ComplexFloat> &diffUIqData,
            std::vector<Topics::ComplexFloat> &diffVIqData) :
            burst(burstContext),
            numRangeGates(numRangeGates),
            numPris(numPris),
            dataOrientation(dataOrientation),
            sumIqData(sumIqData),
            guardIqData(guardIqData),
            diffUIqData(diffUIqData),
            diffVIqData(diffVIqData)
        {};

        /** Constructor with default construction of vectors to allow user to reduce data copies.
        *   Reserves the size of the vectors to numRangeGates * numPris.
        */
        BurstIQSamplesDataTopic(FrameContext burstContext,
            std::uint32_t numRangeGates,
            std::uint32_t numPris,
            RadarDataOrientation dataOrientation) :
            burst(burstContext),
            numRangeGates(numRangeGates),
            numPris(numPris),
            dataOrientation(dataOrientation)
        {
            uint64_t numRangeGates64 = static_cast<uint64_t>(numRangeGates);
            uint64_t numPris64 = static_cast<uint64_t>(numPris);
            sumIqData.reserve(numRangeGates64 * numPris64);
            guardIqData.reserve(numRangeGates64 * numPris64);
            diffUIqData.reserve(numRangeGates64 * numPris64);
            diffVIqData.reserve(numRangeGates64 * numPris64);
        };

        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(burst,           "burst");
            archive.Serialise(numRangeGates,   "numRangeGates");
            archive.Serialise(numPris,         "numPris");
            archive.Serialise(dataOrientation, "dataOrientation");

            archive.Serialise(sumIqData,   "sumIqSample",   "sumIqSamples");
            archive.Serialise(guardIqData, "guardIqSample", "guardIqSamples");
            archive.Serialise(diffUIqData, "diffUIqSample", "diffUIqSamples");
            archive.Serialise(diffVIqData, "diffVIqSample", "diffVIqSamples");

        } // void Serialise(T& archive)

        LCA_TOPIC("BurstIQSamplesDataTopic", 3, 0)

    }; // class BurstIQSamplesDataTopic

}  // namespace Topics

#endif // #ifndef BURST_IQ_SAMPLES_DATA_TOPIC_H