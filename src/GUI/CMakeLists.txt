cmake_minimum_required (VERSION 3.1)

project(main)

option( MSVC_EXTENDED_ALIGNMENT "Turn on MSVC compiler definition _ENABLE_EXTENDED_ALIGNED_STORAGE " ON  )
if (MSVC_EXTENDED_ALIGNMENT)
    add_definitions(-D_ENABLE_EXTENDED_ALIGNED_STORAGE)
endif()

set(GUILib_SOURCE
	${PROJECT_SOURCE_DIR}/mainwindow.cpp
)

set(GUILib_HEADER
	${PROJECT_SOURCE_DIR}/mainwindow.h
)

set(GUILib_UI
	${PROJECT_SOURCE_DIR}/mainwindow.ui
)

set (GuiBin_SOURCE 
	${PROJECT_SOURCE_DIR}/main.cpp
)

qt5_wrap_cpp(GuiLib_HEADER_MOC ${GUILib_HEADER})
qt5_wrap_ui(GuiLib_UI_MOC ${GUILib_UI})

#Include Dependencies
include_directories(
	${PROJECT_SOURCE_DIR}
	${PROJECT_BINARY_DIR}
	#.../Hashfunctions
)

add_library (GUI 
    ${GUILib_SOURCE}
	${GUILib_HEADER}
    ${GuiLib_HEADER_MOC}
    ${GuiLib_UI_MOC}
)

target_link_libraries (GUI 
	#Hashfunctions
	Qt5::Widgets
)

add_executable(main
	${GuiBin_SOURCE}
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    DEBUG_POSTFIX "d"
    RELEASE_POSTFIX ""
	RELWITHDEBINFO_POSTFIX ""
	FOLDER "${FOLDER_NAME}"
)

target_link_libraries (main GUI)

#install(FILES "${CMAKE_INSTALL_PREFIX}/debug_dlls/Qt5Cored.dll" DESTINATION "${CMAKE_INSTALL_PREFIX}/build/src/GUI/Debug")
#install(FILES "${CMAKE_INSTALL_PREFIX}/debug_dlls/Qt5Guid.dll" DESTINATION "${CMAKE_INSTALL_PREFIX}/build/src/GUI/Debug")
#install(FILES "${CMAKE_INSTALL_PREFIX}/debug_dlls/Qt5Widgetsd.dll" DESTINATION "${CMAKE_INSTALL_PREFIX}/build/src/GUI/Debug")

