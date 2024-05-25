#ifndef EFABUSMESSAGE_H
#define EFABUSMESSAGE_H

#include "Fabric/Utils/LCA_Macros.h"

#include <cstdint>
#include <vector>

namespace Topics
{
    struct EFABusMessage
    {
        std::vector<std::uint16_t> busMessageWords{};

        template <typename T>
        void Serialise(T& archive)
        {
            archive.Serialise(busMessageWords, "busMessageWord", "busMessageWords");
        }

        LCA_TOPIC("EFABusMessage", 1, 0)
    };
}

#endif
