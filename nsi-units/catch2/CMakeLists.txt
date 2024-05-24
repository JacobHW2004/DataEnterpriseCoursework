if(NOT TARGET Catch2 )
	project (Catch2)
	add_library(${PROJECT_NAME} INTERFACE)
	target_include_directories (${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

	# Extract the version of Catch2 from the headerfile - it lives on the second line.
	# This ensures the active version of Catch2 is visible in the build log.
	file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/catch.hpp VER_NUM LIMIT_COUNT 2)
	list(POP_FRONT VER_NUM)
	message("Version" ${VER_NUM})
endif()