cmake_minimum_required(VERSION 3.0)

project(CppChallenge)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

FILE(GLOB HEADERS include/*.h)
FILE(GLOB SRC src/*.cpp)

add_executable(CppChallenge main.cpp ${HEADERS} ${SRC})