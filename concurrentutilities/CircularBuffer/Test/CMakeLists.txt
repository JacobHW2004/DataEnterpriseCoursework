# Removing call to external script until we have common CMake scripts hooked into this repo
add_executable (CircularBufferTest CircularBufferTest.cpp)

target_link_libraries (CircularBufferTest PRIVATE Catch2)        # link to the testing library
target_link_libraries (CircularBufferTest PRIVATE CircularBuffer)  # link to the business logic to be tested
target_compile_definitions(CircularBufferTest PRIVATE CATCH_CONFIG_CONSOLE_WIDTH=500) # To stop long scenario names breaking vscode Test Explorer

# Add test to CTest. Define the command used to run the test (catch flags)
# Catch2 flag info: https://github.com/catchorg/Catch2/blob/master/docs/command-line.md
add_test(NAME CircularBufferTest
		 COMMAND CircularBufferTest --reporter junit
							 --name DataStructures
							 --filenames-as-tags
							 --success
							 --out ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/CircularBufferTest_results.xml
							 WORKING_DIRECTORY $<TARGET_FILE_DIR:CircularBufferTest>)

# Add CTest label. Tests with the same label are grouped together.
set_tests_properties (CircularBufferTest PROPERTIES LABELS DataStructures)