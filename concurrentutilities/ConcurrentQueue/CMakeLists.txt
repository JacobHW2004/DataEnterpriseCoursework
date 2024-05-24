if(NOT TARGET ConcurrentQueue)
	add_library (ConcurrentQueue INTERFACE)

	target_include_directories (ConcurrentQueue INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

	find_package(Threads REQUIRED)
	target_link_libraries(ConcurrentQueue INTERFACE Threads::Threads)

	if (${COMMON_TESTS})
		add_subdirectory (Test)
	endif(${COMMON_TESTS})
endif()