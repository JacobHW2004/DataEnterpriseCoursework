#ifndef CONFIGURATION_DATA_AAU_H
#define CONFIGURATION_DATA_AAU_H

#include <stdint.h>
#include "ConfigurationData.h"

namespace Topics
{
    namespace EcrsMK2
    {
        namespace WarmUP
        {
            class ConfigurationDataAAU 
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

                LCA_TOPIC("ConfigurationDataAAU", 1, 0)
            };
        }
    }
}

#endif