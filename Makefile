make: 
	./scripts/run.sh

clear:
	rm -r ./build/

tests:
	./scripts/test.sh

clear_tests:
	rm -r ./test/build/