#!/bin/bash
cmake -B build/
cmake --build  build/
cmake --install build/
./install/bin/main_program
./install/bin/main_test
./install/bin/main_program
