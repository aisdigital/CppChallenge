# Bazel configurations
workspace(name = "CppChallenge")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Add dependencies
http_archive(
    name = "rules_cc",
    urls = ["https://github.com/bazelbuild/rules_cc/releases/download/0.0.6/rules_cc-0.0.6.tar.gz"],
    sha256 = "3d9e271e2876ba42e114c9b9bc51454e379cbf0ec9ef9d40e2ae4cec61a31b40",
    strip_prefix = "rules_cc-0.0.6",
)

http_archive(
    name = "gtest",
    url = "https://github.com/google/googletest/archive/v1.13.0.zip",
    sha256 = "ffa17fbc5953900994e2deec164bb8949879ea09b411e07f215bfbb1f87f4632",
    strip_prefix = "googletest-1.13.0",
)

