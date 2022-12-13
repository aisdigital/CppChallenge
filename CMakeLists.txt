cmake_minimum_required(VERSION 3.14)

project(CppChallenge)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest-main)
include_directories(googletest-main/include)
include_directories(include)

FILE(GLOB HEADERS include/*.h)
FILE(GLOB SRC src/*.cpp)

add_executable(CppChallenge main.cpp 
generalStructs.h 
readExcel.h
readExcel.cpp
SATImport.h 
SATImport.cpp 
ui.h
ui.cpp
)

target_link_libraries(CppChallenge PRIVATE gtest)
