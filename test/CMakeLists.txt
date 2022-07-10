cmake_minimum_required(VERSION 3.14)
project(test)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/main.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

set(challenge_src
    ../include/SchoolSatResult.h
    ../include/Parser.hpp
    ../include/FileUtils.hpp
)

add_executable(TestCppChallenge TestCppChallenge.cpp ${challenge_src}) 

target_link_libraries( TestCppChallenge  gtest_main )

include(GoogleTest)
gtest_discover_tests(TestCppChallenge)