FILE(GLOB HEADERS ../include/*.h)
FILE(GLOB SRC ../src/*.cpp)
add_executable(CppChallenge main.cpp ${HEADERS} ${SRC})

if (ENABLE_UNIT_TESTS)
    add_subdirectory(tests)
endif()