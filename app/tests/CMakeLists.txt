add_executable(app_test "")

target_sources(app_test
    PRIVATE
    main_test.cpp
)

target_link_libraries(app_test
    PRIVATE
    gtest_main
    gmock_main
)

add_test(
    NAME app_test
    COMMAND $<TARGET_FILE:app_test>
)