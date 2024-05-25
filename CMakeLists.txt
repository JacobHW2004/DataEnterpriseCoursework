cmake_minimum_required(VERSION 3.16.4)

Project(CommandChecker)

if(WIN32)
    # similar to compiler flag -fPIC
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
elseif(VXWORKS)
    set(CMAKE_CXX_FLAGS "-fPIC")
else()
    set(CMAKE_CXX_FLAGS "-pthread -fPIC")
endif()

add_subdirectory(catch2)
add_subdirectory(concurrentutilities/Sleeper)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    #standalone build

    add_subdirectory(si-units)
    add_subdirectory(nsi-units)
    add_subdirectory(TopicsEcrsMk2Internal)
    add_subdirectory(topics)

    if(NOT DEFINED LcaEnvName)
        set(LcaEnvName LCA_5_3_0_Proto)
    endif()

    if(NOT DEFINED LCA_LOG_TYPE)
        set (LCA_LOG_TYPE NoLogging)
    endif()

    if (NOT DEFINED CONTAINER_ID)
        set (CONTAINER_ID SingleComponent)
    endif()

    if (DEFINED ENV{${LcaEnvName}})
        file(TO_CMAKE_PATH "$ENV{${LcaEnvName}}" LCA_DIR)
        message("LCA_DIR : ${LCA_DIR}")
    else()
        message(FATAL_ERROR "LCA environment variable is not set")
    endif() 
    
    set(USE_SCHEDULER "false")

    # ContainerName is used by the LCA cmake
    set(ContainerName ${CONTAINER_ID}) 

    # this line is required for unit testing
    file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bin/results)

    # Build a .dll (on Windows)
    option(BUILD_SHARED_LIBS "Build Components and LCA as shared libraries" ON)

    # Pull in CMake scripts
    include(scripts/CMake/CustomTargets.cmake)
    include(scripts/CMake/MiscFunctions.cmake)

    project_setup()

    # similar to compiler flag -fPIC
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)

    # Collect topology stubs, used for e.g. PUBLISH_SUBSCRIBE macros.
    file(GLOB_RECURSE fabric_user_sources CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/System/LCA_UserFiles/Fabric/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/System/LCA_UserFiles/Fabric/*.cpp)

    #Add LCA Parts
    add_subdirectory("${LCA_DIR}/ContainerFramework/Fabric"    ${CONTAINER_ID}_FabricBuild)
    add_subdirectory("${LCA_DIR}/ContainerFramework/Container" ${CONTAINER_ID}_ContainerBuild)
    add_subdirectory("${LCA_DIR}/ContainerFramework/Logging"   ${CONTAINER_ID}_LoggingBuild)
    add_subdirectory("${LCA_DIR}/ContainerFramework/Scheduler"   ${CONTAINER_ID}_ScheduleBuild)

    target_link_libraries(${CONTAINER_ID}_Container PUBLIC ${CONTAINER_ID}_Logging)
    target_link_libraries(${CONTAINER_ID}_Fabric    PUBLIC ${CONTAINER_ID}_Logging)
    target_link_libraries(${ContainerName}_Fabric   PUBLIC ${ContainerName}_Schedule)
    target_link_libraries(${CONTAINER_ID}_Fabric    PRIVATE TopicsEcrsMk2Internal)
    target_link_libraries(${CONTAINER_ID}_Fabric    PRIVATE SIunits)
    target_link_libraries(${CONTAINER_ID}_Fabric    PRIVATE NSIunits)
    target_link_libraries(${ContainerName}_Schedule PUBLIC  ${ContainerName}_Logging)
    target_include_directories(${ContainerName}_Schedule PRIVATE "${LCA_DIR}/ContainerFramework/Memory")    
    
    set_property(TARGET ${CONTAINER_ID}_Container PROPERTY EXCLUDE_FROM_ALL true)

    if(VXWORKS)
        target_link_libraries(${CONTAINER_ID}_Fabric PRIVATE dl)
    elseif(UNIX)
        set(THREADS_PREFER_PTHREAD_FLAG ON)
        find_package(Threads REQUIRED)
        target_link_libraries(${CONTAINER_ID}_Fabric PRIVATE Threads::Threads)
    endif()

    business_logic(${PROJECT_NAME})
    #black_box_test(${PROJECT_NAME})
    lca_target_minimum_links(${PROJECT_NAME})

    # code coverage.. only for Clang-Windows currently
    if(DEFINED ENV{COVERAGE_TOOLS_LIB} AND DEFINED ENV{COVERAGE_TOOLS_VERSION})
      if(NOT VXWORKS AND WIN32)
        file(TO_CMAKE_PATH $ENV{COVERAGE_TOOLS_LIB}/$ENV{COVERAGE_TOOLS_VERSION} COVERAGE_TOOLS_DIR)
        if("${CMAKE_C_COMPILER_ID}" MATCHES "(Apple)?[Cc]lang" OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "(Apple)?[Cc]lang")
          message("COVERAGE_TOOLS_DIR : ${COVERAGE_TOOLS_DIR}")
          if(EXISTS ${COVERAGE_TOOLS_DIR})
            include("${COVERAGE_TOOLS_DIR}/CodeCoverage.cmake")
            set(CODE_COVERAGE true)
            target_code_coverage(${PROJECT_NAME})
          endif()
        endif()
      endif()
    endif()

else()
    business_logic(${PROJECT_NAME})
    #if (BUILD_BLACK_BOX)
    #    black_box_test(${PROJECT_NAME})
    #endif()

    lca_target_minimum_links(${PROJECT_NAME})
endif()

# Add in the Sleeper
target_link_libraries(${PROJECT_NAME} PUBLIC Sleeper NSIunits TopicsEcrsMk2Internal)

target_include_directories(
  ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/TopicsEcrsMk2Internal/Topics/EcrsMk2ClientSubdomain"
  ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/TopicsEcrsMk2Internal/topicsecrsmk2weaponsystem/Topics/EcrsMk2ClientSubdomain"
  ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/TopicsEcrsMk2Internal/topicsecrsmk2weaponsystem/Structs"
  ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/si-units/Public"
  ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/nsi-units/Public"
)