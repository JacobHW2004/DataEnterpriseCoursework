function(add_diagram)
if(TARGET Diagram)
    message("Scripts - Diagram already exists in this project")
else()
    find_package(Dot)
    option(DIAGRAM "Generate dependency diagram" ${DOT_FOUND})

    if(DIAGRAM)
        file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Diagram)

        add_custom_target(Diagram
            COMMAND cmake --graphviz=dependency.dot ..
            COMMAND ${DOT_EXECUTABLE} dependency.dot -T png -o Diagram/dependency.png
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating dependency diagram"
            VERBATIM)

        set_target_properties (Diagram PROPERTIES FOLDER ExtTools)
    endif(DIAGRAM)
endif()
endfunction(add_diagram)


function(add_docs)
if(TARGET Documentation)
    message("Scripts - Documentation already exists in this project")
else()
    find_package(Doxygen)
    option(BUILD_DOCUMENTATION "Build the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})

    if(BUILD_DOCUMENTATION)
        if(NOT DOXYGEN_FOUND)
            message(FATAL_ERROR "Doxygen is needed to build the documentation.")
        endif()

        add_custom_target(Documentation
            COMMAND ${DOXYGEN_EXECUTABLE}  ${DOCUMENTATION_PATH}/Doxyfile.dox
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)

        set_target_properties (Documentation PROPERTIES FOLDER ExtTools)
    endif()
endif()
endfunction(add_docs)

#run OpenCppCoverage
#will only work if you have built the unit test exes first (and have OpenCppCoverage installed)
function(run_opencppcoverage)
if(TARGET Coverage)
    message("Scripts - Coverage already exists in this project")
else()
    find_package(OpenCppCoverage)

    if(${OPEN_CPP_COV_FOUND})
        message(STATUS "OpenCppCoverage found")
    endif()

    if(${OPEN_CPP_COV_FOUND})

        add_custom_target(Coverage
            COMMAND  ${PROJECT_SOURCE_DIR}/System/Common/Scripts/RunOpenCppCoverage.cmd
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
            COMMENT "Running test coverage with OpenCppCoverage"
            VERBATIM)
        
        set_target_properties (Coverage PROPERTIES FOLDER ExtTools)
        
    endif()
endif()
endfunction(run_opencppcoverage)