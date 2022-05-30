cmake_minimum_required(VERSION 2.8)

project(CppChallenge)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

FILE(GLOB HEADERS include/*.h)
FILE(GLOB SRC src/*.cpp)

add_executable(CppChallenge main.cpp ${HEADERS} ${SRC})

# Add Unit Test
option(unittest "Compile with Unit Test Available." ON)
if (unittest)
    include(ExternalProject)
    # Download and install GoogleTest
    ExternalProject_Add(
        gtest
        URL https://github.com/google/googletest/archive/master.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        CMAKE_ARGS -DCMAKE_CXX_FLAGS=-Wno-effc++
        # Disable install step
        INSTALL_COMMAND ""
    )
    # Get GTest source and binary directories from CMake project
    ExternalProject_Get_Property(gtest source_dir binary_dir)
    # Create a libgtest target to be used as a dependency by test programs
    add_library(libgtest IMPORTED STATIC GLOBAL)
    add_dependencies(libgtest gtest)
    # Set libgtest and libgmock properties
    if (EXISTS "${binary_dir}/googlemock/gtest/libgtest.a")
        set_target_properties(libgtest PROPERTIES
            "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
            "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
        )
        # Create a libgmock target to be used as a dependency by test programs
        add_library(libgmock IMPORTED STATIC GLOBAL)
        add_dependencies(libgmock gtest)
        # Set libgmock properties
        set_target_properties(libgmock PROPERTIES
            "IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
            "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
        )
    else()
        set_target_properties(libgtest PROPERTIES
            "IMPORTED_LOCATION" "${binary_dir}/lib/libgtest.a"
            "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
        )
        # Create a libgmock target to be used as a dependency by test programs
        add_library(libgmock IMPORTED STATIC GLOBAL)
        add_dependencies(libgmock gtest)
        # Set libgmock properties
        set_target_properties(libgmock PROPERTIES
            "IMPORTED_LOCATION" "${binary_dir}/lib/libgmock.a"
            "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
        )
    endif()

    include_directories(SYSTEM "${source_dir}/googletest/include"
                        "${source_dir}/googlemock/include")

    # Test
    # Includes
    include_directories("${PROJECT_SOURCE_DIR}/src"
                        "${PROJECT_SOURCE_DIR}/test"
                        )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -pedantic -std=c++11 -pg")
    add_executable(TestCppChallenge
                   # Test's Main Code
                   ${PROJECT_SOURCE_DIR}/test/main_test.cpp

                   # Test's Codes
                   ${PROJECT_SOURCE_DIR}/test/dataentrytest.cpp
                   ${PROJECT_SOURCE_DIR}/test/datareadertest.cpp
                   ${PROJECT_SOURCE_DIR}/test/dataprocessortest.cpp
                   ${PROJECT_SOURCE_DIR}/test/datawritertest.cpp
                   ${PROJECT_SOURCE_DIR}/test/nameprocessortest.cpp

                   ###
                   )
    target_link_libraries(TestCppChallenge ${STL_LIBS} ${SRC} libgtest)
endif()

