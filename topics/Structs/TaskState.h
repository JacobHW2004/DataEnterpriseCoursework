#ifndef TASKSTATE_H
#define TASKSTATE_H

#include <string>
#include <cstdint>

namespace Common {

    enum class TaskState : std::uint8_t
    {
        DEAD,
        ALIVE,
        SUSPENDED
    };

    static std::string taskStateToString(TaskState taskState)
    {
        std::string result {""};
        switch (taskState)
        {
            case Common::TaskState::ALIVE :
                result = "Alive";
                break;
            case Common::TaskState::SUSPENDED : 
                result = "Suspended";
                break;
            case Common::TaskState::DEAD :
            default: 
                result = "Dead";
                break;

        }
        return result;
    }

} // namespace Common

#endif