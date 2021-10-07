# define what to do on different platforms
if(WIN32)
	message("OS: Windows")
    cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
	set(PLATTFORM_INSTALL_DIR "win")
	
elseif(UNIX)
	message("OS:UNIX")
    cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
	set(PLATTFORM_INSTALL_DIR "linux")
endif()

#solution name
project(Hash-Generator)

# set the paths first
include(CMakeListsSettings_$ENV{USERNAME}.txt OPTIONAL RESULT_VARIABLE LOCAL_PATH_SETTING_OK)
if(LOCAL_PATH_SETTING_OK)
    message("using local path settings of user $ENV{USERNAME}")
else(LOCAL_PATH_SETTING_OK)
    message("WARNING: using default path settings. please create your own CMakeListsSettings_USERNAME.txt")
#    include(PathsForCmake.txt)
endif()

#Qt5
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
if(Qt5_FOUND)
 message("-- Found Qt5")
else(Qt5_FOUND)
 message(FATAL_ERROR "-- Not found Qt5")
endif(Qt5_FOUND)

#Qt5Widgets
find_package(Qt5Widgets REQUIRED)
if(Qt5Widgets_FOUND)
 message("-- Found Qt5Widgets")
else(Qt5Widgets_FOUND)
 message(FATAL_ERROR "-- Not found Qt5Widgets")
endif(Qt5Widgets_FOUND)

# used libraries
include_directories(
	${CMAKE_SOURCE_DIR}/src
)

add_subdirectory(src/GUI)
#add_subdirectory(src/Hashfunctions)