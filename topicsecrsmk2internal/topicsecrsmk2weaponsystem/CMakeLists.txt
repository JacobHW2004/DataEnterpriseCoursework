cmake_minimum_required(VERSION 3.16.4)

if(NOT TARGET TopicsEcrsMk2WeaponSystem)

	if(NOT DOCUMENTATION_PATH)
		set(DOCUMENTATION_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Docs)
	endif()

	if(NOT TARGET SIunits)
		add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/si-units)
	endif()

	if(NOT TARGET NSIunits)
		add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/nsi-units)
	endif()	

	project (TopicsEcrsMk2WeaponSystem)
	set(CMAKE_CXX_STANDARD 14)
	set(CMAKE_CXX_STANDARD_REQUIRED True)

	file(GLOB topics_sources CONFIGURE_DEPENDS
       ${CMAKE_CURRENT_SOURCE_DIR}/Structs/*.h
			 ${CMAKE_CURRENT_SOURCE_DIR}/Topics/*.h
			 ${CMAKE_CURRENT_SOURCE_DIR}/Topics/EcrsMk2ClientSubdomain/*.h
			 ${CMAKE_CURRENT_SOURCE_DIR}/Topics/EcrsMk2ClientSubdomain/MateSignals/*.h
			 ${CMAKE_CURRENT_SOURCE_DIR}/Topics/EcrsMk2ClientSubdomain/PlotReporting/*.h
			 ${CMAKE_CURRENT_SOURCE_DIR}/Topics/EcrsMk2ClientSubdomain/TrackDeletion/*.h
			 ${CMAKE_CURRENT_SOURCE_DIR}/Topics/*.cpp)

  #Temporarily remove these topics because of Build errors (seem to be unused in PX solution)
  list(REMOVE_ITEM topics_sources 
        ${CMAKE_CURRENT_SOURCE_DIR}/Topics/EcrsMk2ClientSubdomain/LinsTopic.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Topics/EcrsMk2ClientSubdomain/NavComputerTopic.h)

	add_library(${PROJECT_NAME} STATIC ${topics_sources})

	target_link_libraries(${PROJECT_NAME} PUBLIC SIunits)
	target_link_libraries(${PROJECT_NAME} PUBLIC NSIunits)

	target_include_directories (
       ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
			 ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Structs"
			 ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics"
			 ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/EcrsMk2ClientSubdomain"
			 ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/EcrsMk2ClientSubdomain/MateSignals"
			 ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/EcrsMk2ClientSubdomain/PlotReporting"
			 ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/EcrsMk2ClientSubdomain/TrackDeletion"
			 ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/si-units/Public"
       )

  # For stand-alone exe build
	add_executable(${PROJECT_NAME}_runtime  "${CMAKE_CURRENT_SOURCE_DIR}/Topics/Topics.cpp")

	target_link_libraries(${PROJECT_NAME}_runtime PRIVATE ${PROJECT_NAME})
	target_link_libraries(${PROJECT_NAME}_runtime PRIVATE SIunits)
	target_link_libraries(${PROJECT_NAME}_runtime PRIVATE NSIunits)

	target_include_directories(${PROJECT_NAME}_runtime PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()