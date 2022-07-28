#!/bin/bash

echo "Building CppChallenge..."

BUILD_DIR="build"

cmake -B ${BUILD_DIR}
cmake --build ${BUILD_DIR}
