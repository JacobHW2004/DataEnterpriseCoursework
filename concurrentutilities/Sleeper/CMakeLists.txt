if(NOT TARGET Sleeper)
	add_library(Sleeper STATIC Private/Sleeper.cpp
							   Public/Sleeper.h )

	target_include_directories(Sleeper PUBLIC Public)

	if (${COMMON_TESTS})
		add_subdirectory (Test)
	endif(${COMMON_TESTS})
	
endif()