load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library (
    name = "lib_cli",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.hpp"]),
    includes = ["include"],
    linkopts = ["-lpthread"],
    visibility = ["//app:__pkg__"]
)

cc_test (
    name = "cpp_challenge_test",
    srcs = glob(["test/*.cpp"]),
    deps = [":lib_cli",
            "@com_google_googletest//:gtest_main",
            "@bazel_tools//tools/cpp/runfiles",],
    data = ["test/testFile.csv"],
    copts = ['-std=c++17']
)

cc_binary(
    name = "cpp_challenge",
    srcs = ["main/main.cpp"],
    deps = [ ":lib_cli" ]
)