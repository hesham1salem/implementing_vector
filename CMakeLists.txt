
cmake_minimum_required(VERSION 3.30)
project(myvector)
add_executable(main_program src/main.cpp src/myvector.cpp)
target_include_directories(main_program PUBLIC include/)
install(TARGETS main_program )

include(CTest)
find_package(GTest REQUIRED)
add_executable(main_test test/myvectorTest.cpp src/myvector.cpp )
target_include_directories(main_test PUBLIC include/)
target_link_libraries(main_test  gtest  gtest_main )
add_test(NAME main_testing COMMAND main_test)
