add_executable(college_data_lib_test "")

target_sources(college_data_lib_test
    PRIVATE
    college_data_lib_test.cpp
    data_storage_test.cpp
)

target_link_libraries(college_data_lib_test
    PRIVATE
    gtest_main
    gmock_main
    college_data_lib
)

add_test(
    NAME college_data_lib_test
    COMMAND $<TARGET_FILE:college_data_lib_test>
)

target_compile_definitions(college_data_lib_test PUBLIC TEST_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data/")