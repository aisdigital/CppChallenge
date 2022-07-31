set(SRC_FILES ../../src/csv_file.cpp)
set(INC_FILES ../../include/csv_file.h)
add_executable(CSVFileTests csv_file_tests.cpp ${SRC_FILES} ${INC_FILES})
target_link_libraries(CSVFileTests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} -lpthread)