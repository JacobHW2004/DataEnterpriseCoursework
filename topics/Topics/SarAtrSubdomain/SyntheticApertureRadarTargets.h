//*******************************************************************************
//
// PROJECT  : QQ LCA Integration
//
//
// parasoft-begin-suppress AUTOSAR-A2_3_1-a "Starteam required tags"
// $Workfile: SyntheticApertureRadarTargets.h$
// $Revision: 4$
//       $Id: SyntheticApertureRadarTargets.h,v 1.3, 2021-11-15 16:19:16Z, Wares, Alan (Mr)$
// $NoKeywords$
// parasoft-end-suppress AUTOSAR-A2_3_1-a "Starteam required tags"
//
//! @file
//! @copyright COPYRIGHT @ QinetiQ Ltd 2021
//! @brief This file contains the SyntheticApertureRadarTargets topic declaration.
//
//********************************************************************************

//********************************************************************************
//LCA elements have been added by Leonardo
//********************************************************************************
#ifndef SYNTHETICAPERTURERADARTARGETS_H
#define SYNTHETICAPERTURERADARTARGETS_H

#include "Fabric/Utils/LCA_Macros.h"

#include <cstdint>
#include <vector>
#include "SyntheticApertureRadarTarget.h"

namespace Topics {

//! @brief A topic that provides data on one to many targets for a requested task.
struct SyntheticApertureRadarTargets
{
    //! @brief Unique identifier for the task.
    std::uint32_t taskId;

    //! @brief A collection of targets.
    std::vector<Topics::SyntheticApertureRadarTarget> targets;

    //! @brief Default constructor.
    SyntheticApertureRadarTargets() noexcept :
        taskId{ 0U } {};

    //! @brief Constructor.
    //! @param aTaskID Unique identifier for the task.
    //! @param aTargets A collection of targets.
    SyntheticApertureRadarTargets(const std::uint32_t aTaskID, const std::vector<Topics::SyntheticApertureRadarTarget>& aTargets) :
        taskId{ aTaskID },
        targets{ aTargets } {};

    template <typename T>
    void Serialise (T& archive) {
        archive.Serialise(taskId, "taskId");
        archive.Serialise(targets, "target", "targets");
    }

    LCA_TOPIC("SyntheticApertureRadarTargets", 1, 0)
};

}  // namespace Topics

#endif