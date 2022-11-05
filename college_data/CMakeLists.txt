# Create library
file(GLOB college_data_SRC
    src/*.cpp
    src/*.c
)

file(GLOB college_data_HDR 
    src/*.hpp
    src/*.h
)

add_library(college_data_lib STATIC
    ${college_data_SRC}
    ${college_data_HDR}
)

# Add project subdirectories

# Link libraries

# System libraries

# Include directories path to the library
target_include_directories(college_data_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Define library version
target_compile_definitions(college_data_lib PUBLIC COLLEGE_DATA_LIB_VERSION=0)

# Google Test
if (ENABLE_UNIT_TESTS)
    add_subdirectory(tests)
endif()
