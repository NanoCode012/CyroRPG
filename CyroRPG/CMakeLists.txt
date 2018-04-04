cmake_minimum_required(VERSION 3.0)
project("CyroRPG")

set(Misc_DIR Miscellaneous)
include_directories(${Misc_DIR})

set(HEADER Characters.h InTown.h ${Misc_DIR}/Misc.h OutTown.h Skills.h Monsters.h ${Misc_DIR}/Random.h Items.h ${Misc_DIR}/DataController.h Home.h)
set(SOURCEFILE Characters.cpp InTown.cpp ${Misc_DIR}/Misc.cpp OutTown.cpp Skills.cpp Monsters.cpp ${Misc_DIR}/Random.cpp Items.cpp ${Misc_DIR}/DataController.cpp Home.cpp)
set(SOURCE main.cpp ${HEADER} ${SOURCEFILE})

set (CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} ${SOURCE})