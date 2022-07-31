add_executable(CollegeDatabaseTests college_database_tests.cpp ${SRC} ${INC})
target_link_libraries(CollegeDatabaseTests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} -lpthread)