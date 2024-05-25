
#ifndef RadarTaskType_H
#define RadarTaskType_H

#include <cstdint>

namespace Common {

enum class RadarTaskCategoryType : std::uint8_t
{
	INVALID_CATEGORY,
	VOLUME_SEARCH,
	ELECTRONIC_SURVEILLANCE_SEARCH,
	COUNT
};

} // namespace Common
   
#endif
