cmake_minimum_required(VERSION 3.16.3)
project(1sem_C_Cpp)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

add_library(equa STATIC src/equation.c)
target_include_directories(equa PUBLIC include/)
add_executable(main.out main.c)
target_link_libraries(main.out equa)

enable_testing()

# Find libraries for test
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

#include_directories(${GTEST_INCLUDE_DIRS})
add_executable(test.out gtest.cpp)
target_link_libraries(test.out equa ${GTEST_LIBRARIES} Threads::Threads)
