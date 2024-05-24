// RegistrationTopic.h : Defines a Registration Topic for components to announce their available capabilties

#ifndef REGISTRATION_TOPIC_H_
#define REGISTRATION_TOPIC_H_

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {
    
    enum class ProcessingCapability{
        
        MPRF_WAVEFORM
        
    }; // enum class ProcessingCapability
    
    class RegistrationTopic {
    public:
    
        // id, location, and ProcessingCapability have been added to demo functionality.
        // Their purpose and names will evolve going forward. 
        std::uint32_t id{ 0 };
        std::uint32_t location{ 0 };
        ProcessingCapability processingCapability{ ProcessingCapability::MPRF_WAVEFORM };
    
        template <class T>
        void Serialise(T& archive) {
            
            archive.Serialise(id,                   "id");
            archive.Serialise(location,             "location");
            archive.Serialise(processingCapability, "processingCapability");
        
        } // void Serialise(T& archive)
    
    LCA_TOPIC("RegistrationTopic", 1, 0);
        
    }; // class RegistrationTopic
    
} // namespace Topics

#endif // #ifndef REGISTRATION_TOPIC_H_
