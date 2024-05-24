# Removing call to external script until we have common CMake scripts hooked into this repo
	#add_catch_test (SleeperTest Sleeper Helper Test/SleeperTest)
    add_executable (SleeperTest SleeperTest.cpp)

    target_link_libraries (SleeperTest PRIVATE Catch2)        # link to the testing library
    target_link_libraries (SleeperTest PRIVATE Sleeper)  # link to the business logic to be tested
    target_compile_definitions(SleeperTest PRIVATE CATCH_CONFIG_CONSOLE_WIDTH=500) # To stop long scenario names breaking vscode Test Explorer

    # Add test to CTest. Define the command used to run the test (catch flags)
    # Catch2 flag info: https://github.com/catchorg/Catch2/blob/master/docs/command-line.md
    # TODO: Could do coverage in here!
    add_test(NAME SleeperTest
             COMMAND SleeperTest --reporter junit
                                 --name Helper
                                 --filenames-as-tags
                                 --success
                                 --out ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/SleeperTest_results.xml
                                 WORKING_DIRECTORY $<TARGET_FILE_DIR:SleeperTest>)

    # Add CTest label. Tests with the same label are grouped together.
    set_tests_properties (SleeperTest PROPERTIES LABELS Helper)
# end add_catch_test

if(NOT TARGET Concurrent::Queue)
# Fallback to the old Concurrent Queue library
# Temporary fix that can be removed once we have unified all the concurrent queues in this repo
    target_link_libraries(SleeperTest PRIVATE ConcurrentQueue)
else()
    target_link_libraries(SleeperTest PRIVATE Concurrent::Queue)
endif()