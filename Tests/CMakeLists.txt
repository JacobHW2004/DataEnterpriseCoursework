
project(SITests)

file(GLOB si_test_src CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_catch_test(${PROJECT_NAME} SIunits DataUnits ${si_test_src})
