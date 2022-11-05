FILE(GLOB HEADERS *.h)
FILE(GLOB SRC *.c *.cpp)
add_executable(CppChallenge main.cpp ${HEADERS} ${SRC})

target_link_libraries(CppChallenge PRIVATE college_data_lib)