#!/bin/bash

cmake . -B ./build
make -C ./build/ CppChallenge
./build/CppChallenge
