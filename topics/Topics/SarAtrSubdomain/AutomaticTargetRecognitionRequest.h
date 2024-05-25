//*******************************************************************************
//
// PROJECT  : QQ LCA Integration
//
//
// parasoft-begin-suppress AUTOSAR-A2_3_1-a "Starteam required tags"
// $Workfile: AutomaticTargetRecognitionRequest.h$
// $Revision: 3$
//       $Id: AutomaticTargetRecognitionRequest.h,v 1.2, 2021-11-03 09:32:11Z, Wares, Alan (Mr)$
// $NoKeywords$
// parasoft-end-suppress AUTOSAR-A2_3_1-a "Starteam required tags"
//
//! @file
//! @copyright COPYRIGHT @ QinetiQ Ltd 2021
//! @brief This file contains the AutomaticTargetRecognitionRequest topic declaration.
//
//********************************************************************************

//********************************************************************************
//LCA elements have been added by Leonardo
//********************************************************************************
#ifndef AUTOMATICTARGETRECOGNITIONREQUEST_H
#define AUTOMATICTARGETRECOGNITIONREQUEST_H

#include "Fabric/Utils/LCA_Macros.h"

#include <cstdint>
#include <vector>
#include <string>

namespace Topics {

//! @brief A topic to initiate ATR processing and supply the required parameters.
struct AutomaticTargetRecognitionRequest
{
    //! @brief Unique identifier for the task.
    std::uint32_t taskId;

    //! @brief One or more target types to search for. 
    std::vector<std::string> targetTypes;

    //! @brief Default constructor.
    AutomaticTargetRecognitionRequest() noexcept :
        taskId{ 0U } {};

    //! @brief Constructor.
    //! @param aTaskId Unique identifier for the task.
    //! @param aTargetTypes One or more target types to search for.
    AutomaticTargetRecognitionRequest(const std::uint32_t aTaskId, const std::vector<std::string>& aTargetTypes) :
        taskId(aTaskId),
        targetTypes(aTargetTypes) {};

    template <typename T>
    void Serialise (T& archive) {
        archive.Serialise(taskId, "taskId");
        archive.Serialise(targetTypes, "targetType", "targetTypes");
    }

    LCA_TOPIC("AutomaticTargetRecognitionRequest", 1, 0)
};

}  // namespace Topics

#endif