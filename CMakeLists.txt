cmake_minimum_required(VERSION 2.8...3.22)

project(CppChallenge)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(challenge_src
    include/SchoolSatResult.h
    include/Parser.hpp
    include/FileUtils.hpp
    include/Database.hpp
    include/CLI.hpp
)

add_executable(CppChallenge src/main.cpp ${challenge_src})

add_subdirectory(test)
