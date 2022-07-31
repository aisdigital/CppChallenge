FILE(GLOB SRC_FILES ../../src/csv_file.cpp)
FILE(GLOB INC_FILES ../../include/csv_file.h)
add_executable(CSVFileTests csv_file_tests.cpp ${SRC_FILES} ${INC_FILES})
target_link_libraries(CSVFileTests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} -lpthread)
add_custom_command(
        TARGET CSVFileTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/tests/csv_file_tests/data.csv
                ${CMAKE_CURRENT_BINARY_DIR}/)