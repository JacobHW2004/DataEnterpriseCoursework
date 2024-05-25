#ifndef TIME_TO_COMPLETE_REPORT_H
#define TIME_TO_COMPLETE_REPORT_H

#include "SISecond.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

/** @brief This topic class provides the estimated time to complete one full iteration of a volume. */
class TimeToCompleteReport {
public:

    /** @brief The task the volume relates to. */
    std::int32_t internalTaskID{0};

    /** @brief Estimated time to complete one full iteration of the demanded volume. */
    SI::SISecond timeToComplete {0.0};
    
    /** @brief Serialise function required for communications. */
    template <class T>
    void Serialise(T& archive) {

        /* Temporary variable to allow serialization of SI-unit member */
        double timeToCompleteDouble{ timeToComplete() };

        archive.Serialise(internalTaskID, "internalTaskID");
        archive.Serialise(timeToCompleteDouble, "timeToComplete");

        timeToComplete = SI::SISecond(timeToCompleteDouble);
    }

    LCA_TOPIC("TimeToCompleteReport", 1, 0)

};

}  // namespace Topics

#endif