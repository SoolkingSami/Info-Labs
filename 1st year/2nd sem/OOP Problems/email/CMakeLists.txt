cmake_minimum_required(VERSION 3.22)
project(email)

set(CMAKE_CXX_STANDARD 17)

add_executable(email main.cpp EmailLetter.cpp EmailLetter.h EmailAddress.cpp EmailAddress.h)
