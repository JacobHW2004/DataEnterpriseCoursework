cmake_minimum_required(VERSION 3.16.4)

if(NOT TARGET SIunits)
	project(SIunits)
	set(CMAKE_CXX_STANDARD 17)
	set(CMAKE_CXX_STANDARD_REQUIRED True)

	option(BUILD_SDC_TESTS "Controls if the tests for SDC repos will be built. Defaults to ON unless specified otherwise" ON)

    # Put all binaries in the same folder. MSVC puts binaries in build type folder by default
    if(WIN32 OR UNIX)
        set(OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    else()
        set(OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
    endif()

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})
	
	file(GLOB si_sources CONFIGURE_DEPENDS
		Public/*.h
		Public/Test*.cpp
		Private/*.cpp
	)

	#Build the Library
	add_library(${PROJECT_NAME} STATIC ${si_sources})
	target_include_directories(${PROJECT_NAME} PUBLIC Public)

	if(BUILD_SDC_TESTS)
		file(MAKE_DIRECTORY ${OUTPUT_DIRECTORY}/results)

		enable_testing()

		if(NOT TARGET CmakeScripts)
			add_subdirectory(scripts/CMake)
			endif()

		if(NOT TARGET Catch2)
			add_subdirectory(Catch2)
		endif()

		add_subdirectory(Tests)
	endif()
endif()