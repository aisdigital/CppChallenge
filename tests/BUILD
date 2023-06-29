load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "doctest",
    hdrs = ["doctest.h"],
)

cc_binary(
    name = "cpp-challenge-tests",
    srcs = ["main.cpp"],
    deps = [
        ":doctest",
        "//main:cpp-challenge-lib"
    ],

)