load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary", "cc_test")

# Create a library for main project files
cc_library(
    name = "MainLibrary",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    includes = ["include"],
    copts = ["-std=c++17"],
)

# Create the main executable
cc_binary(
    name = "CppChallenge",
    srcs = ["main.cpp"],
    includes = ["include"],
    deps = [":MainLibrary"],
)

# Create the test executable
cc_test(
    name = "CppChallenge_test",
    srcs = glob(["tests/*.cpp"]),
    includes = ["include"],
    deps = [":MainLibrary", "@gtest//:gtest_main"],
)
