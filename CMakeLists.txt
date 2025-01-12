set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install)
project(myvector)
add_executable(main_program src/main.cpp src/myvector.cpp)
install(TARGETS main_program )

find_package(GTest REQUIRED)
add_executable(main_test test/myvectorTest.cpp src/myvector.cpp )
target_include_directories(main_test PUBLIC include/)
target_link_libraries(main_test  gtest  gtest_main )
install(TARGETS main_test )  

