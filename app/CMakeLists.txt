FILE(GLOB HEADERS ../include/*.h)
FILE(GLOB SRC ../src/*.cpp)
add_executable(CppChallenge main.cpp ${HEADERS} ${SRC})

target_link_libraries(CppChallenge PRIVATE college_data_lib)

if (ENABLE_UNIT_TESTS)
    add_subdirectory(tests)
endif()