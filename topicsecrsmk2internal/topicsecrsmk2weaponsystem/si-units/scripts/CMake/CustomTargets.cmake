# Glob for source files and create a business logic target, test target and lca target.
# Param 1: The component name (eg. VolumeSearch)
# Assumptions : Folder structure should look like this
#               MyComponent 
#               ├───CMakeLists.txt
#               ├───LCAMessaging
#               ├───Private
#               ├───Public
#               └───Test
#              C++ files use only the extensions .cpp & .h.
function(add_component Component)

if(NOT TARGET ${Component})
    business_logic(${Component})
    black_box_test(${Component})
endif()
    lca_target(${Component})
    #white_box_test(${Component})
endfunction (add_component)

# Glob for source files and create a business logic target,and lca target.
# Param 1: The component name (eg. VolumeSearch)
# Assumptions : Folder structure should look like this
#               MyComponent 
#               ├───CMakeLists.txt
#               ├───LCAMessaging
#               ├───Private
#               ├───Public
#              C++ files use only the extensions .cpp & .h.
function(add_test_component Component)
if(NOT TARGET ${Component})
    business_logic(${Component})
endif()
    lca_target(${Component})
endfunction (add_test_component)

# Business logic Tgt: Set include directories. VS folder
function(business_logic Component)

    if(NOT TARGET ${Component})
        if( NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Public OR NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Private)
            message(FATAL_ERROR "${Component} business logic target failed because no Public or Private folder")
        endif()

        file(GLOB_RECURSE component_source CONFIGURE_DEPENDS Public/*.h
                                                    Private/*.h
                                                    Private/*.cpp)

        add_library (${Component} STATIC ${component_source})  
        
        target_include_directories(${Component} PUBLIC Public)

        #Collects any subdirectories under Public and adds them as a target include
        SUBDIRLIST(SUB_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Public)
        FOREACH(subdir ${SUB_DIRS})
            target_include_directories(${Component} PUBLIC Public/${subdir})
        ENDFOREACH()

        #Collects any subdirectories under Private and adds them as a target includes
        target_include_directories(${Component} PRIVATE Private)
        SUBDIRLIST(SUB_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Private)
        FOREACH(subdir ${SUB_DIRS})
            target_include_directories(${Component} PRIVATE Private/${subdir})
        ENDFOREACH()
        
        target_link_libraries(${Component} PUBLIC SIunits) 
        target_link_libraries(${Component} PUBLIC Topics) 

        set_target_properties (${Component} PROPERTIES FOLDER Components)
    endif()
endfunction(business_logic)

# Test Target: add_catch_test
function(black_box_test Component)
    if( NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Test)
        message(FATAL_ERROR "${Component} test target failed because no Test folder")
    endif()
    message(${Component}Test)
    file(GLOB test_source CONFIGURE_DEPENDS Test/*.h
                                            Test/*.cpp)
    add_catch_test(${Component}Test ${Component} Components ${test_source})

    # Set the working directory for Visual Studio
    set_property(TARGET ${Component}Test PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:${Component}Test>)
endfunction(black_box_test)

# LCA Target: Link to business logic and fabric. Set EXPORT macro. VS folder. Link container to target
function(lca_target Component)
    if( NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/LCAMessaging)
            message(FATAL_ERROR " ${Component} LCA target failed because no LCAMessaging folder")
    endif()

    file(GLOB lca_sources CONFIGURE_DEPENDS LCAMessaging/*.h
                                            LCAMessaging/*.cpp)

    add_library (${ContainerName}_${Component}LCA SHARED ${lca_sources}) 
    
    target_link_libraries(${ContainerName}_${Component}LCA PUBLIC ${Component})
    target_link_libraries(${ContainerName}_${Component}LCA PUBLIC ${ContainerName}_Fabric)

    target_link_libraries (${ContainerName}_${Component}LCA PRIVATE ${ContainerName}_Container) # For LCA Container Context Instance
    target_link_libraries (${ContainerName}_${Component}LCA PRIVATE ${ContainerName}_Logging) # For LCA Logging Context Instance
    
    # LCA requires components define EXPORT (I think?)
    target_compile_definitions(${ContainerName}_${Component}LCA PRIVATE EXPORT) 
    # Container needs to link to every component. See comment on add_topic re fabric linkage for alternative.
	target_link_libraries(${ContainerName} PUBLIC ${ContainerName}_${Component}LCA) 

    set_target_properties (${ContainerName}_${Component}LCA PROPERTIES FOLDER Components)
endfunction(lca_target)

function(lca_target_minimum_links Component)
    if( NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/LCAMessaging)
            message(FATAL_ERROR " ${Component} LCA target failed because no LCAMessaging folder")
    endif()

    file(GLOB lca_sources CONFIGURE_DEPENDS LCAMessaging/*.h
                                            LCAMessaging/*.cpp)

    add_library (${ContainerName}_${Component}LCA SHARED ${lca_sources}) 
    
    target_link_libraries(${ContainerName}_${Component}LCA PUBLIC ${Component})
    target_link_libraries(${ContainerName}_${Component}LCA PUBLIC ${ContainerName}_Fabric ${ContainerName}_Logging)

    target_include_directories(${ContainerName}_${Component}LCA PRIVATE ${LCA_DIR}/ContainerFramework)

    # LCA requires components define EXPORT (I think?)
    target_compile_definitions(${ContainerName}_${Component}LCA PRIVATE EXPORT) 

    set_target_properties (${ContainerName}_${Component}LCA PROPERTIES FOLDER Components)
endfunction(lca_target_minimum_links)


# Add unit test, link to component to test, link to catch lib, register test using add_test and set label, add to list of tests.
# Param 1: The name of the test.
# Param 2: The Component that is being unit tested. This should be a library that can be linked to.
# Param 3: The label CTest will use to group this test.
# Param 4 & above: Source files to be included in the test executable
function(add_catch_test TestName Component Label)
	add_executable (${TestName} ${ARGN})

	target_link_libraries (${TestName} PRIVATE Catch2)        # link to the testing library
	target_link_libraries (${TestName} PRIVATE ${Component})  # link to the business logic to be tested
    target_compile_definitions(${TestName} PRIVATE CATCH_CONFIG_CONSOLE_WIDTH=500) # To stop long scenario names breaking vscode Test Explorer
    
    # Add test to CTest. Define the command used to run the test (catch flags)
    # Catch2 flag info: https://github.com/catchorg/Catch2/blob/master/docs/command-line.md
    # TODO: Could do coverage in here!
    add_test(NAME ${TestName} 
             COMMAND ${TestName} --reporter junit 
                                 --name ${Label}
                                 --filenames-as-tags 
                                 --success 
                                 --out ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/results/${TestName}_results.xml
                                 WORKING_DIRECTORY $<TARGET_FILE_DIR:${TestName}>)
    
    # Add CTest label. Tests with the same label are grouped together. 
    set_tests_properties (${TestName} PROPERTIES LABELS ${Label}) 
    
endfunction (add_catch_test)

#This macro collects subdirectories one level beneath the current directory (curdir)
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()