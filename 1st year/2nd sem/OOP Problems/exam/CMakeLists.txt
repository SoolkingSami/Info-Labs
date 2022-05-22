cmake_minimum_required(VERSION 3.22)
project(exam)

set(CMAKE_CXX_STANDARD 17)

add_executable(exam main.cpp Vehicle.cpp Vehicle.h Tank.cpp Tank.h Truck.cpp Truck.h)
