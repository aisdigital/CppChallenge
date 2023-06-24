load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library (
    name = "lib_cli",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.hpp"]),
    includes = ["include"],
    linkopts = ["-lpthread"],
    visibility = ["//app:__pkg__"]
)

cc_binary(
    name = "cpp_challenge",
    srcs = ["main/main.cpp"],
    deps = [ ":lib_cli" ]
)