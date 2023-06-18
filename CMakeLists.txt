# Initial CMake configurations
cmake_minimum_required(VERSION 3.14)

project(CppChallenge)
set(TEST_NAME CppChallenge_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_CPPCHECK "cppcheck")

# Add dependencies
include_directories(include)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.13.0
)
FetchContent_MakeAvailable(googletest)

# Create a library for main project files
add_library(MainLibrary STATIC ${HEADERS} ${SRC})

FILE(GLOB HEADERS include/*.h)
FILE(GLOB SRC src/*.cpp)
target_sources(MainLibrary PRIVATE ${HEADERS} ${SRC})

# Create a list of all the test source files
FILE(GLOB TEST_SRC tests/*.cpp)

enable_testing()
add_executable(${TEST_NAME} ${TEST_SRC})

target_link_libraries(${TEST_NAME} PRIVATE gtest_main MainLibrary)

# Create a test executable for each test source file
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})

# Create the main executable
add_executable(${PROJECT_NAME} main.cpp)

# Link the main executable with your library
target_link_libraries(${PROJECT_NAME} PRIVATE MainLibrary)
