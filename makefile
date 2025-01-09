all: build install run  clean 
cc=g++
program_name=main
source_files=main.cpp
build:
	mkdir  build 2>> /dev/null ||true 
	cd build && $(cc)  -S ../$(source_files)
	$(cc) build/*.s -o $(program_name)
install:
	mkdir install 
	mv  $(program_name) install/
run:
	@./install/$(program_name)

test:
	g++ -o test_program  myvectorTest.cpp -l gtest -l gtest_main  && ./test_program

clean:
	rm -rf build
.PHONY: build install