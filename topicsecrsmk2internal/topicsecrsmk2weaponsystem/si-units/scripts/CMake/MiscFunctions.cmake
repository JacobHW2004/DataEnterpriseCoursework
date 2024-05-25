# This function is to be called once near the start of the top level CMake file.
# Does generic setup likely required by many projects
macro(project_setup)

    # Allows use of modern C++ features. This may have to change when the certification/RTOS folks say "I don't trust that"
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Enable the test runner Ctest.
    enable_testing()

    # Enable use of folders for IDEs. 
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Put all binaries in the same folder. MSCV puts binaries in build type folder by default
    if(WIN32 OR UNIX)
        set(OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    else()
        set(OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
    endif()

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

endmacro(project_setup)

# Copy all at the path to the components TARGET_FILE_DIR.
function(copy_test_vectors_to_bin TestComponent VectorsPath)
    # Copy the contents of the specified directory to the target directory and build folder after build has completed
    add_custom_command(TARGET ${TestComponent} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${VectorsPath} $<TARGET_FILE_DIR:${TestComponent}>)
endfunction (copy_test_vectors_to_bin)
