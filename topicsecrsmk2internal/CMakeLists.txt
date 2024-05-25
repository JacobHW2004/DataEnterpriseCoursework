cmake_minimum_required(VERSION 3.16.4)

if(NOT TARGET TopicsEcrsMk2Internal)

	if(NOT DOCUMENTATION_PATH)
		set(DOCUMENTATION_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Docs)
	endif()

	if(NOT TARGET SIunits)
		add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/si-units)
	endif()

  if (NOT TARGET TopicsEcrsMk2WeaponSystem)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/topicsecrsmk2weaponsystem)
  endif()

	project(TopicsEcrsMk2Internal)
	set(CMAKE_CXX_STANDARD 14)
	set(CMAKE_CXX_STANDARD_REQUIRED True)

	file(GLOB topics_sources CONFIGURE_DEPENDS
			 ${CMAKE_CURRENT_SOURCE_DIR}/Topics/*.h
			 ${CMAKE_CURRENT_SOURCE_DIR}/Topics/EcrsMk2ClientSubdomain/*.h
			 ${CMAKE_CURRENT_SOURCE_DIR}/Topics/EcrsMk2ClientSubdomain/TrackDeletion/*.h
			 ${CMAKE_CURRENT_SOURCE_DIR}/Topics/*.cpp)

	add_library(${PROJECT_NAME} STATIC ${topics_sources})

	target_link_libraries(${PROJECT_NAME} PUBLIC SIunits)
	target_link_libraries(${PROJECT_NAME} PUBLIC TopicsEcrsMk2WeaponSystem)

	target_include_directories (
    ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
	  ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics"
	  ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/EcrsMk2ClientSubdomain"
	  ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/EcrsMk2ClientSubdomain/TrackDeletion"
	  ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/topicsecrsmk2weaponsystem/Topics/EcrsMk2ClientSubdomain"
	  ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/topicsecrsmk2weaponsystem/Structs"
    )

  # For stand-alone exe build
	add_executable(${PROJECT_NAME}_runtime  "${CMAKE_CURRENT_SOURCE_DIR}/Topics/Topics.cpp")

	target_link_libraries(${PROJECT_NAME}_runtime PRIVATE ${PROJECT_NAME})
	target_link_libraries(${PROJECT_NAME}_runtime PRIVATE SIunits)
	target_link_libraries(${PROJECT_NAME}_runtime PRIVATE TopicsEcrsMk2WeaponSystem)

	target_include_directories(${PROJECT_NAME}_runtime PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()