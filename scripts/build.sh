#!/bin/bash

if [ $# -lt 1 ]; then
    echo "Please, run # build.sh <TARGET>"
    echo "    TARGET - Target of build e.g.: CppChallenge, CSVFileTests, etc"
    echo "Example: build.sh CppChallenge"
    exit 1
fi

echo "Building $1..."

BUILD_DIR="build"

cmake -B ${BUILD_DIR}
cmake --build ${BUILD_DIR} --target $1