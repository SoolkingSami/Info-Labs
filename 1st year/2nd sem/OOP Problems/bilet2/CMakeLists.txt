cmake_minimum_required(VERSION 3.22)
project(bilet2)

set(CMAKE_CXX_STANDARD 17)

add_executable(bilet2 main.cpp Stack.h StackLinkedList.cpp StackLinkedList.h Queue.h)
