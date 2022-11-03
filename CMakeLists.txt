cmake_minimum_required(VERSION 3.16 FATAL_ERROR) # Changed from 2.8 to 3.16, added fatal error for previous versions

project(CppChallenge)

set(CMAKE_CXX_STANDARD 11) # Kept in C++11
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

# Included CMake FetchContent module
include(FetchContent)

# Added Google Test from Github
set(ENABLE_UNIT_TESTS TRUE)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")
if (ENABLE_UNIT_TESTS) # If this was a submodule or something similar we could want to disable the unit tests
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    FetchContent_MakeAvailable(googletest)
    enable_testing()
    include(CTest)
    # We could also add some basic code coverage with lcov or other report tool
endif()

include_directories(include)
add_subdirectory(src)
add_subdirectory(app)