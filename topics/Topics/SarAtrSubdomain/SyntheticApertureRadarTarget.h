//*******************************************************************************
//
// PROJECT  : QQ LCA Integration
//
//
// parasoft-begin-suppress AUTOSAR-A2_3_1-a "Starteam required tags"
// $Workfile: SyntheticApertureRadarTarget.h$
// $Revision: 7$
//       $Id: SyntheticApertureRadarTarget.h,v 1.6, 2021-11-16 15:01:52Z, Wares, Alan (Mr)$
// $NoKeywords$
// parasoft-end-suppress AUTOSAR-A2_3_1-a "Starteam required tags"
//
//! @file
//! @copyright COPYRIGHT @ QinetiQ Ltd 2021
//! @brief This file contains the SyntheticApertureRadarTarget topic declaration.
//
//********************************************************************************

//********************************************************************************
//LCA elements have been added by Leonardo
//********************************************************************************
#ifndef SYNTHETICAPERTURERADARTARGET_H
#define SYNTHETICAPERTURERADARTARGET_H

#include "Fabric/Utils/LCA_Macros.h"

#include <cstdint>
#include <string>
#include "PixelPosition.h"

namespace Topics {

//! @brief A topic that indicates confidence and pixel location on an identified target.
struct SyntheticApertureRadarTarget
{
    //! @brief Unique identifier for the related task.
    std::uint32_t taskId;

    //! @brief Degree of match.  
    float confidence;

    //! @brief The target position in pixels relative to the top, left corner of the source SAR image.
    Topics::PixelPosition position;

    //! @brief The type of target.
    std::string targetType;

    //! @brief Default constructor.
    SyntheticApertureRadarTarget() :
        taskId{ 0U },
        confidence{ 0.0F },
        position{ 0U,0U },
        targetType{ "Undefined target type" } {};

    //! @brief Constructor.
    //! @param ataskId Unique identifier for the related task.
    //! @param aConfidence Degree of match.
    //! @param aPosition The target position in pixels relative to the top, left corner of the source SAR image.
    //! @param aTargetType The type of target.
    SyntheticApertureRadarTarget(const std::uint32_t ataskId, const float aConfidence, const Topics::PixelPosition& aPosition, const std::string& aTargetType) :
        taskId{ ataskId },
        confidence{ aConfidence },
        position{ aPosition },
        targetType{ aTargetType } {};

    template <typename T>
    void Serialise (T& archive) {
        archive.Serialise(taskId, "taskId");
        archive.Serialise(confidence, "confidence");
        archive.Serialise(position, "position");
        archive.Serialise(targetType, "targetType");
    }

    LCA_TOPIC("SyntheticApertureRadarTarget", 1, 0)
};

}  // namespace Topics

#endif

