FIND_PROGRAM(DOT_EXECUTABLE
              NAMES dot
              DOC "Graphviz Dot tool"
              )

if(DOT_EXECUTABLE)
  set(DOT_FOUND TRUE)
  message(STATUS "Found Dot.exe (GraphViz): ${DOT_EXECUTABLE}")
else()
  set(DOT_FOUND FALSE)
  message(STATUS "Could not find Dot.exe (GraphViz)")
endif()