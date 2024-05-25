#ifndef CONFIGURATION_DATA_AESA_H
#define CONFIGURATION_DATA_AESA_H

#include <stdint.h>
#include "ConfigurationData.h"

namespace Topics
{
    namespace EcrsMK2
    {
        namespace WarmUP
        {
            class ConfigurationDataAESA 
            {
                public: 

                ConfigurationData configurationData {};

                /**
                * @brief Serialise function required for communications
                */
                template <class T>
                void Serialise(T& archive)
                {
            
                    archive.Serialise(configurationData, "configurationData");
                }

                LCA_TOPIC("ConfigurationDataAESA", 1, 0)
            };
        }
    }
}

#endif