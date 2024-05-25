cmake_minimum_required(VERSION 3.16.4)

if(NOT TARGET Topics)

	if(NOT DOCUMENTATION_PATH)
		set(DOCUMENTATION_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Docs)
	endif()

	if(NOT TARGET SIunits)
		add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/si-units)
	endif()

	project (Topics)
	set(CMAKE_CXX_STANDARD 14)
	set(CMAKE_CXX_STANDARD_REQUIRED True)

	file(GLOB topics_sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Structs/*.h
											   ${CMAKE_CURRENT_SOURCE_DIR}/Topics/*.h
											   ${CMAKE_CURRENT_SOURCE_DIR}/Topics/HealthSubdomain/*.h
											   ${CMAKE_CURRENT_SOURCE_DIR}/Topics/TrackingSubdomain/*.h
											   ${CMAKE_CURRENT_SOURCE_DIR}/Topics/TrackingSubdomain/SingleComponentGoldTrackerSupport/*.h
                                               ${CMAKE_CURRENT_SOURCE_DIR}/Topics/TranslationSubdomain/*.h
											   ${CMAKE_CURRENT_SOURCE_DIR}/Topics/SignalProcessingSubdomain/*.h
											   ${CMAKE_CURRENT_SOURCE_DIR}/Topics/SimulationSubdomain/*.h
											   ${CMAKE_CURRENT_SOURCE_DIR}/Topics/NavigationSubdomain/*.h
											   ${CMAKE_CURRENT_SOURCE_DIR}/Topics/MathsSubdomain/*.h
											   ${CMAKE_CURRENT_SOURCE_DIR}/Topics/*.cpp                                          
											   ${CMAKE_CURRENT_SOURCE_DIR}/Topics/STANAG_4607/*.h
											   ${CMAKE_CURRENT_SOURCE_DIR}/Topics/STANAG_Tracker/*.h
											   ${CMAKE_CURRENT_SOURCE_DIR}/Topics/TestInfrastructure/*.h
											   ${CMAKE_CURRENT_SOURCE_DIR}/Topics/TestSolutionSubdomain/*.h
                         					   ${CMAKE_CURRENT_SOURCE_DIR}/Topics/SarAtrSubdomain/*.h
											   ${CMAKE_CURRENT_SOURCE_DIR}/Topics/TaskingAndRFSubdomain/*.h


)

	add_library(${PROJECT_NAME} STATIC ${topics_sources})

	target_link_libraries(${PROJECT_NAME} PUBLIC SIunits)

	target_include_directories (${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
								${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Structs"
								${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics"
								${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/STANAG_Tracker"
								${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/STANAG_4607"
								${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/TestInfrastructure"
								${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/HealthSubdomain"
								${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/TrackingSubdomain"
								${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/TrackingSubdomain/SingleComponentGoldTrackerSupport"
                                ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/TranslationSubdomain"
								${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/SignalProcessingSubdomain"
								${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/SimulationSubdomain"
								${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/NavigationSubdomain"
								${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/TestSolutionSubdomain"
								${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/MathsSubdomain"
								${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/SarAtrSubdomain"
								${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Topics/TaskingAndRFSubdomain"
)
	# For stand-alone exe build
	add_executable(${PROJECT_NAME}_runtime  "${CMAKE_CURRENT_SOURCE_DIR}/Topics/Topics.cpp")

	target_link_libraries(${PROJECT_NAME}_runtime PRIVATE ${PROJECT_NAME})
	target_link_libraries(${PROJECT_NAME}_runtime PRIVATE SIunits)

	target_include_directories(${PROJECT_NAME}_runtime PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()