if(NOT TARGET CircularBuffer)
	project (CircularBuffer)

	add_library (${PROJECT_NAME} INTERFACE)

	find_package(Threads REQUIRED)

	target_include_directories (${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
	target_link_libraries(${PROJECT_NAME} INTERFACE Threads::Threads)

	if (${COMMON_TESTS})
		add_subdirectory (Test)
	endif(${COMMON_TESTS})
endif()