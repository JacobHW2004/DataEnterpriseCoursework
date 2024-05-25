//*******************************************************************************
//
// PROJECT  : QQ LCA Integration
//
//
// parasoft-begin-suppress AUTOSAR-A2_3_1-a "Starteam required tags"
// $Workfile: AutomaticTargetRecognitionProgress.h$
// $Revision: 4$
//       $Id: AutomaticTargetRecognitionProgress.h,v 1.3, 2021-11-03 09:32:11Z, Wares, Alan (Mr)$
// $NoKeywords$
// parasoft-end-suppress AUTOSAR-A2_3_1-a "Starteam required tags"
//
//! @file
//! @copyright COPYRIGHT @ QinetiQ Ltd 2021
//! @brief This file contains the AutomaticTargetRecognitionProgress topic declaration.
//
//********************************************************************************

//********************************************************************************
//LCA elements have been added by Leonardo
//********************************************************************************
#ifndef AUTOMATICTARGETRECOGNITIONPROGRESS_H
#define AUTOMATICTARGETRECOGNITIONPROGRESS_H

#include "Fabric/Utils/LCA_Macros.h"

#include <cstdint>

namespace Topics {

//! @brief A topic that provides the number of targets found and percentage progress.
struct AutomaticTargetRecognitionProgress
{
    //! @brief Unique identifier for the task.
    std::uint32_t taskId;

    //! @brief Task percentage progress.
    std::uint32_t percentageComplete;

    //! @brief Number of targets found.
    std::uint32_t targetCount;

    //! @brief Default constructor.
    AutomaticTargetRecognitionProgress() noexcept :
        taskId{ 0U },
        percentageComplete{ 0U },
        targetCount{ 0U } {};
    
    //! @brief Constructor.
    //! @param aTaskId Unique identifier for the task.
    //! @param aPercentageComplete Task percentage progress (currently limited to either 0 or 100).
    //! @param aTargetCount Number of targets found.
    AutomaticTargetRecognitionProgress(const std::uint32_t aTaskId, const std::uint32_t aPercentageComplete, const std::uint32_t aTargetCount) noexcept :
        taskId{ aTaskId },
        percentageComplete{ aPercentageComplete },
        targetCount{ aTargetCount } {};

    template <typename T>
    void Serialise (T& archive) {
        archive.Serialise(taskId, "taskId");
        archive.Serialise(percentageComplete, "percentageComplete");
        archive.Serialise(targetCount, "targetCount");
    }

    LCA_TOPIC("AutomaticTargetRecognitionProgress", 1, 0)
};

}  // namespace Topics

#endif