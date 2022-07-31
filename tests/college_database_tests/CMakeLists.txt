FILE(GLOB SRC_FILES ../../src/*.cpp)
FILE(GLOB INC_FILES ../../include/*.h)
add_executable(CollegeDatabaseTests college_database_tests.cpp ${SRC_FILES} ${INC_FILES})
target_link_libraries(CollegeDatabaseTests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} -lpthread)
add_custom_command(
        TARGET CollegeDatabaseTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/tests/college_database_tests/*.csv
                ${CMAKE_CURRENT_BINARY_DIR}/)