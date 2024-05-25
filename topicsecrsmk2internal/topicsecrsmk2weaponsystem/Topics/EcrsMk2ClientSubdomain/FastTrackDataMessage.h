#ifndef FAST_TRACK_DATA_MESSAGE_H
#define FAST_TRACK_DATA_MESSAGE_H

#include "Fabric/Utils/LCA_Macros.h"
#include "FastTrackData.h"
#include <array>
#include <vector>
#include <cstdint>

namespace Topics
{
    namespace FastTrackData
    {
   
        /**
        * @brief this topic is a strongly typed one to one mapping of a Rate 1 Track Data Message from within the RADAR103-AC-HAT-MESS-1 from
        * ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
        * DRL No:  1.17
        * Issue: A
        */
        struct FastTrackDataMessage
        {
  
            std::array<FastTrackData, 8> TRACK_SLOTS {};
            std::array<std::uint16_t, 100> RDRT_TF_XXX_TRK_IDENT {};

            bool operator==(const FastTrackDataMessage& other) const
            {
                return
                TRACK_SLOTS == other.TRACK_SLOTS &&
                RDRT_TF_XXX_TRK_IDENT == other.RDRT_TF_XXX_TRK_IDENT;
            }

            bool operator!=(const FastTrackDataMessage& other) const
            {
                return !(*this == other);
            }

            /**
            * @brief Serialise function required for communications
            */
            template <class T>
            void Serialise(T &archive)
            {
                for (std::uint8_t i{ 0 }; i < TRACK_SLOTS.size(); i++)
                {
                    archive.Serialise(TRACK_SLOTS[i], ("TRACK_SLOTS" + std::to_string(i)));
                }
                
                for (std::uint8_t i{ 0 }; i < RDRT_TF_XXX_TRK_IDENT.size(); i++)
                {
                    archive.Serialise(RDRT_TF_XXX_TRK_IDENT[i],
                        ("RDRT_TF_" + std::to_string(i+1) + "_TRK_IDENT"));
                }
                
            }

            LCA_TOPIC("FastTrackDataMessage", 1, 0)
        };

    }
} // namespace Topics

#endif