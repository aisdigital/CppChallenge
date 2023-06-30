load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "cpp-challenge-lib",
    srcs = ["application.cpp",
            "csv_parser.cpp",
            "level_results.cpp"],
    hdrs = ["application.hpp",
            "csv_parser.hpp",
            "level_results.hpp"],
    visibility = ["//tests:__pkg__"],
)

cc_binary(
    name = "cpp-challenge",
    srcs = ["main.cpp"],
    deps = [
        ":cpp-challenge-lib",
    ],
)