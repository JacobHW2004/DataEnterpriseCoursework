
project(NSITests)

file(GLOB nsi_test_src CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_catch_test(${PROJECT_NAME} NSIunits DataUnits "${nsi_test_src}")
