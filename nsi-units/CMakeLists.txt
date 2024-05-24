cmake_minimum_required(VERSION 3.16.4)

if(NOT TARGET NSIunits)
	project (NSIunits)
	set(CMAKE_CXX_STANDARD 14)
	set(CMAKE_CXX_STANDARD_REQUIRED True)

    # Put all binaries in the same folder. MSVC puts binaries in build type folder by default
    if(WIN32)
        set(OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    else()
        set(OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
    endif()

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})
	
	file (MAKE_DIRECTORY ${OUTPUT_DIRECTORY}/results)

	enable_testing()

	file(GLOB nsi_sources CONFIGURE_DEPENDS
		Public/*.h
		Private/*.cpp
	)

	#Build the Library
	add_library(${PROJECT_NAME} STATIC ${nsi_sources})
	target_include_directories(${PROJECT_NAME} PUBLIC Public)

	#Create the executable
	set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME}_runtime)

	target_link_libraries(${PROJECT_NAME} PUBLIC SIunits)
	target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/si-units/Public/")

	add_subdirectory (si-units)
	add_subdirectory (scripts/CMake)
	add_subdirectory (catch2)
	add_subdirectory (Tests)
endif()