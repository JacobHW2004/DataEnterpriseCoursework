if(TARGET Catch2)

	message("SIUnits - Catch2 already exists in this project")

else()

	project (Catch2)

	add_library(${PROJECT_NAME} INTERFACE)

	target_include_directories (${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

endif()