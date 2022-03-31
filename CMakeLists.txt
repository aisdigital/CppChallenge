cmake_minimum_required(VERSION 3.10)

project(CppChallenge)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)
include_directories(input)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/googletest)
