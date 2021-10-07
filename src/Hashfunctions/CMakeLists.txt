cmake_minimum_required (VERSION 3.1)

project (Hashfunction)

set (Hash_SOURCE
	hashfunction.cpp
)

set (Hash_HEADER
	hashfunction.h
 )

#Include Dependencies
include_directories(
	${PROJECT_SOURCE_DIR}
)

add_library(${PROJECT_NAME}
	hashfunction.cpp
	hashfunction.h
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    DEBUG_POSTFIX "d"
    RELEASE_POSTFIX ""
	RELWITHDEBINFO_POSTFIX ""
	FOLDER "${FOLDER_NAME}"
)

target_include_directories(${PROJECT_NAME} PUBLIC
)