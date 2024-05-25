#ifndef RESPONSE_CODE_H
#define RESPONSE_CODE_H

#include <cstdint>

namespace Topics
{
	namespace TestSolutionTopics
	{
		enum class ResponseCode : std::uint8_t
		{
			RequestOK,
			RequestFail,
			RequestUnsupported
		};
	}
}
#endif