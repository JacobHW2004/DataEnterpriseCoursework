//*******************************************************************************
//
// PROJECT  : QQ LCA Integration
//
//
// parasoft-begin-suppress AUTOSAR-A2_3_1-a "Starteam required tags"
// $Workfile: PixelPosition.h$
// $Revision: 4$
//       $Id: PixelPosition.h,v 1.3, 2021-11-03 09:32:11Z, Wares, Alan (Mr)$
// $NoKeywords$
// parasoft-end-suppress AUTOSAR-A2_3_1-a "Starteam required tags"
//
//! @file
//! @copyright COPYRIGHT @ QinetiQ Ltd 2021
//! @brief This file contains the PixelPosition topic declaration.
//
//********************************************************************************

//********************************************************************************
//LCA elements have been added by Leonardo
//********************************************************************************
#ifndef PIXELPOSITION_H
#define PIXELPOSITION_H

#include "Fabric/Utils/LCA_Macros.h"

#include <cstdint>

namespace Topics {

//! @brief A topic that indicates a pixel location in a SAR image relative to the top left corner.
struct PixelPosition
{
    //! @brief Pixel location on the x plane relative to the left edge of the SAR image.
    std::uint32_t x;

    //! @brief Pixel location on the y plane relative to the top edge of the SAR image.
    std::uint32_t y;

    //! @brief Default constructor.
    PixelPosition() noexcept :
        x{ 0U },
        y{ 0U } {};

    //! @brief Constructor.
    //! @param aX Pixel location on the x plane relative to the left edge of the SAR image.
    //! @param aY Pixel location on the y plane relative to the top edge of the SAR image.
    PixelPosition(const std::uint32_t aX, const std::uint32_t aY) noexcept :
        x{ aX },
        y{ aY } {};

    template <typename T>
    void Serialise (T& archive) {
        archive.Serialise(x, "x");
        archive.Serialise(y, "y");
    }

    LCA_TOPIC("PixelPosition", 1, 0)
};

}  // namespace Topics

#endif