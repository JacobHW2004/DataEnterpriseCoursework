cmake_minimum_required(VERSION 3.10)
project(ConcurrentUtilities VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
enable_testing()

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    set(COMMON_TESTS true)
endif()

# Put all binaries in the same folder. MSVC puts binaries in build type folder by default
if(WIN32)
    set(OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
else()
    set(OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

if(NOT TARGET Catch2)
    add_subdirectory(catch2)
endif()

add_subdirectory(ConcurrentQueue)
add_subdirectory(Sleeper)
add_subdirectory(CircularBuffer)
