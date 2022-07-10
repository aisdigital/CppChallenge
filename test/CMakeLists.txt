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

add_executable(TestFileUtils TestFileUtils.cpp ../include/FileUtils.hpp)

target_link_libraries( TestFileUtils  gtest_main )

include(GoogleTest)
gtest_discover_tests(TestFileUtils)