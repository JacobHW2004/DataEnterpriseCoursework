#ifndef TICK_H
#define TICK_H

#include "Fabric/Utils/LCA_Macros.h"

#include <cstdint>

namespace Topics {

    struct Tick
    {
        /**
         * @brief Topic struct to hold the representation of a Tick (period of time unit)
         * 
         */
        std::uint32_t value{ 0 };
        double conversionFactor{ 0 };

        Tick(const std::uint32_t& aValue, const double& aConversionFactor) : 
            value{aValue},
            conversionFactor{aConversionFactor}
        {};

        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {
            
            archive.Serialise(value, "value");
            archive.Serialise(conversionFactor, "conversionFactor");

        }  

        LCA_TOPIC("Tick", 1, 0)   

    };

}

#endif