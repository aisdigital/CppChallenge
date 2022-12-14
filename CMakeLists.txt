cmake_minimum_required(VERSION 2.8)

project(CppChallenge)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

FILE(GLOB HEADERS include/*.h)
FILE(GLOB SRC src/*.cpp)

add_executable(CppChallenge main.cpp ${HEADERS} ${SRC})