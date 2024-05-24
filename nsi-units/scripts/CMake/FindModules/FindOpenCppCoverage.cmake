FIND_PROGRAM(OPEN_CPP_COV_EXECUTABLE
              NAMES opencppcoverage
              DOC "Code coverage tool"
              )

if(OPEN_CPP_COV_EXECUTABLE)
  set(OPEN_CPP_COV_FOUND TRUE)
  message(STATUS "Found OpenCppCoverage.exe: ${OPEN_CPP_COV_EXECUTABLE}")
else()
  set(OPEN_CPP_COV_FOUND FALSE)
  message(STATUS "Could not find OpenCppCoverage.exe")
endif()

