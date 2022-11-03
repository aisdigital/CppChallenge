.PHONY: build_all run unit_test clean

.DEFAULT_GOAL: build_all

build_all:
	cmake . -B ./build 
	make -C ./build --no-print-directory

run: build_all
	./build/app/CppChallenge

run_unit_test: build_all
	ctest -VV --test-dir ./build -O ./Testing/unit_test.log

clean:
	rm -rf ./build
	rm -rf ./Testing