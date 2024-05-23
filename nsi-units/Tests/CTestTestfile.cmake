# CMake generated Testfile for 
# Source directory: D:/commandchecker/commandchecker/nsi-units/Tests
# Build directory: D:/commandchecker/commandchecker/build/nsi-units/Tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(NSITests "D:/commandchecker/commandchecker/build/bin/Debug/NSITests.exe" "--reporter" "junit" "--name" "DataUnits" "--filenames-as-tags" "--success" "--out" "D:/commandchecker/commandchecker/build/bin/results/NSITests_results.xml")
  set_tests_properties(NSITests PROPERTIES  LABELS "DataUnits" WORKING_DIRECTORY "D:/commandchecker/commandchecker/build/bin/Debug" _BACKTRACE_TRIPLES "D:/commandchecker/commandchecker/si-units/scripts/CMake/CustomTargets.cmake;149;add_test;D:/commandchecker/commandchecker/nsi-units/Tests/CMakeLists.txt;6;add_catch_test;D:/commandchecker/commandchecker/nsi-units/Tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(NSITests "D:/commandchecker/commandchecker/build/bin/Release/NSITests.exe" "--reporter" "junit" "--name" "DataUnits" "--filenames-as-tags" "--success" "--out" "D:/commandchecker/commandchecker/build/bin/results/NSITests_results.xml")
  set_tests_properties(NSITests PROPERTIES  LABELS "DataUnits" WORKING_DIRECTORY "D:/commandchecker/commandchecker/build/bin/Release" _BACKTRACE_TRIPLES "D:/commandchecker/commandchecker/si-units/scripts/CMake/CustomTargets.cmake;149;add_test;D:/commandchecker/commandchecker/nsi-units/Tests/CMakeLists.txt;6;add_catch_test;D:/commandchecker/commandchecker/nsi-units/Tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(NSITests "D:/commandchecker/commandchecker/build/bin/MinSizeRel/NSITests.exe" "--reporter" "junit" "--name" "DataUnits" "--filenames-as-tags" "--success" "--out" "D:/commandchecker/commandchecker/build/bin/results/NSITests_results.xml")
  set_tests_properties(NSITests PROPERTIES  LABELS "DataUnits" WORKING_DIRECTORY "D:/commandchecker/commandchecker/build/bin/MinSizeRel" _BACKTRACE_TRIPLES "D:/commandchecker/commandchecker/si-units/scripts/CMake/CustomTargets.cmake;149;add_test;D:/commandchecker/commandchecker/nsi-units/Tests/CMakeLists.txt;6;add_catch_test;D:/commandchecker/commandchecker/nsi-units/Tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(NSITests "D:/commandchecker/commandchecker/build/bin/RelWithDebInfo/NSITests.exe" "--reporter" "junit" "--name" "DataUnits" "--filenames-as-tags" "--success" "--out" "D:/commandchecker/commandchecker/build/bin/results/NSITests_results.xml")
  set_tests_properties(NSITests PROPERTIES  LABELS "DataUnits" WORKING_DIRECTORY "D:/commandchecker/commandchecker/build/bin/RelWithDebInfo" _BACKTRACE_TRIPLES "D:/commandchecker/commandchecker/si-units/scripts/CMake/CustomTargets.cmake;149;add_test;D:/commandchecker/commandchecker/nsi-units/Tests/CMakeLists.txt;6;add_catch_test;D:/commandchecker/commandchecker/nsi-units/Tests/CMakeLists.txt;0;")
else()
  add_test(NSITests NOT_AVAILABLE)
endif()
