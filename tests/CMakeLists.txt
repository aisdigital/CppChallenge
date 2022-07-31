find_package(GTest REQUIRED)

include_directories(../src)
include_directories(../include)

add_subdirectory(csv_file_tests)
add_subdirectory(college_database_tests)