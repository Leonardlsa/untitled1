cmake_minimum_required(VERSION 3.23)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(untitled1 main.cpp basic_function.h start.h start.cpp basic_function.cpp administrator.cpp administrator.h file_dealer.cpp file_dealer.h basic_struct.h basic_struct.cpp)
