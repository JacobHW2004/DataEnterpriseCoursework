#ifndef ECHO_TEST_LOG_TOPIC_H
#define ECHO_TEST_LOG_TOPIC_H

#include <string>
#include "Fabric/Utils/LCA_Macros.h"

namespace TestingInfrastructure {

/**
* @brief Topic This is responsible for allowing a log message to be sent to the repeater results component
*
*/
struct EchoTestLogTopic {
 public:

    // Just holds a log message
    std::string logMessage;

    /**
    * @brief Serialise function required for communications
    */
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(logMessage, "logMessage");
    }
    LCA_TOPIC("EchoTestLogTopic", 1, 0)

};

}  // namespace Topics

#endif