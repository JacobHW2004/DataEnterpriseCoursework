#ifndef LEONARDOCOMPONENTARCH_CONTAINERFRAMEWORK_LCA_MACROS_H
#define LEONARDOCOMPONENTARCH_CONTAINERFRAMEWORK_LCA_MACROS_H
#pragma once

#include <cstddef>
#include <string>

using ComponentId = std::string ;
using ComponentName = std::string ;
using ComponentVersionMajor = std::uint32_t ;
using ComponentVersionMinor = std::uint32_t ;

using TopicId = std::string ;
using TopicVersionMajor = std::uint32_t ;
using TopicVersionMinor = std::uint32_t ;

//Operating System Switch Support
#if defined(_WIN64)
#define LCA_OS_WINDOWS_64BIT
#define LCA_OS_WINDOWS
#elif defined(_WIN32) //64-bit Windows also defines _WIN32, so this has to be a stacked if/else
#define LCA_OS_WINDOWS_32BIT
#define LCA_OS_WINDOWS
#define LCA_ENABLE_UNIT_TEST_FUNCTIONALITY
#elif defined(__linux__) //"linux" and "__linux" obsolete
#define LCA_OS_LINUX
//Not a test environment
#elif defined(__VXWORKS__)
#define LCA_OS_VXWORKS
//Not a test environment
#else
static_assert(false, "Qicr does not support this operating system");
#endif

#define LCA_TOPIC(ID, VERSION_MAJOR, VERSION_MINOR) const static TopicId getID() {\
	return ID;\
}\
 const static TopicVersionMajor getLCA_TopicVersionMajor() noexcept{\
	return VERSION_MAJOR;\
}\
 const static TopicVersionMinor getLCA_TopicVersionMinor() noexcept{\
	return VERSION_MINOR;\
}\
const std::string GetSerialisationName() const {\
	return ID;\
}

#define LCA_COMPONENT_VERSION(VERSION_MAJOR, VERSION_MINOR) ComponentVersionMajor _EXPORT getLCA_ComponentVersionMajor() {\
	return VERSION_MAJOR;\
}\
ComponentVersionMinor _EXPORT getLCA_ComponentVersionMinor() {\
	return VERSION_MINOR;\
}

template<typename T, std::size_t N>
constexpr std::size_t array_size(const T(&)[N]) { return N; }
#endif //LEONARDOCOMPONENTARCH_CONTAINERFRAMEWORK_LCA_MACROS_H