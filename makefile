INPUT_DATA_REL_PATH := ./input/SAT__College_Board__2010_School_Level_Results.csv
INPUT_DATA_FULLPATH := $(shell realpath $(INPUT_DATA_REL_PATH))

.PHONY: build_all run unit_test clean
.DEFAULT_GOAL: build_all

build_all:
	cmake . -B ./build 
	make -C ./build --no-print-directory

run: build_all
	./build/app/CppChallenge ${INPUT_DATA_FULLPATH}

run_unit_test: build_all
	GTEST_COLOR=1 ctest -VV --test-dir ./build -O ./Testing/unit_test.log

clean:
	rm -rf ./build
	rm -rf ./Testing