cmake_minimum_required(VERSION 3.16)

project(CppChallenge)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

FILE(GLOB HEADERS include/*.h)
FILE(GLOB SRC src/*.cpp)

add_executable(CppChallenge main.cpp ${HEADERS} ${SRC})

add_subdirectory(googletest) # add googletest subdirectory
include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>
add_executable(tests test/tests.cpp ${HEADERS} ${SRC}) # add this executable
target_link_libraries(tests PRIVATE gtest) # link google test to this executable
