cmake_minimum_required(VERSION 3.20)
project(1sem_C_Cpp C)

set(CMAKE_C_STANDARD 99)

add_executable(1sem_C_Cpp main.c include/equation.h src/equation.c)

target_link_libraries(1sem_C_Cpp PRIVATE m)
