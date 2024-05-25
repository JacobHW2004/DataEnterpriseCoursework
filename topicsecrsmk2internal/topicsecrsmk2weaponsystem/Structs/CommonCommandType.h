#ifndef COMMON_COMMAND_TYPE
#define COMMON_COMMAND_TYPE

#include <string>

namespace Common
{

	enum class CommandType : uint8_t
	{
		CREATE,
		RESUME,
		DELETION,
		SUSPEND,
		MAINTAIN,
		NO_TASK,
		MODIFY
	};
	
	static std::string commandTypeToString(CommandType commandType)
	{
		std::string result {""};
		switch (commandType)
		{
			case Common::CommandType::RESUME :
				result = "Resume";
				break;
			case Common::CommandType::DELETION :
				result = "Deletion";
				break;
			case Common::CommandType::SUSPEND : 
				result = "Suspend";
				break;
			case Common::CommandType::MAINTAIN :
				result = "Maintain";
				break;
			case Common::CommandType::MODIFY :
				result = "Modify";
				break;
			default :
				result = "No Task";
				break;
		}
		return result;
	}

}
#endif // COMMON_COMMAND_TYPE
