all: build install run clean 
cc=g++
program_name=main
source_files=src/main.cpp src/myvector.cpp
build:
	cmake -B build/
	cmake --build  build/
install:
	mkdir install 
	mv  $(program_name) install/
run:
	@./instal/$(program_name)

test:
	g++ -o test_program  myvectorTest.cpp -l gtest -l gtest_main  && ./test_program

clean:
	rm -rf build
.PHONY: build install