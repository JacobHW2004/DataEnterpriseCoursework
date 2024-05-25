if (TARGET CmakeScripts)
    message("CmakeScripts already exists")
else()
    list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/FindModules)
	
    #Dont add external scripts for opencppcoverage etc for Linux/VxWorks
    if(WIN32)
        include(ExternalTools.cmake)
        add_docs()
        add_diagram()
        run_opencppcoverage()
    endif()

    include(CustomTargets.cmake)
    include(MiscFunctions.cmake)

    add_custom_target(CmakeScripts)
endif()

