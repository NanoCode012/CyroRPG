cmake_minimum_required(VERSION 3.0)
project("CyroRPG")

set (CMAKE_CXX_STANDARD 11)

set (HEADER_FILE)
set (INC_DIR ${PROJECT_SOURCE_DIR}/inc)
add_subdirectory(${INC_DIR})

set (SOURCE_FILE)
set (SRC_DIR ${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${SRC_DIR})

set (SOURCE main.cpp ${SOURCE_FILE} ${HEADER_FILE})

add_executable(${PROJECT_NAME} ${SOURCE})
target_include_directories(${PROJECT_NAME} PRIVATE INC_DIR PRIVATE SRC_DIR)