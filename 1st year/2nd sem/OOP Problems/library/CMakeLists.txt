cmake_minimum_required(VERSION 3.20)
project(library)

set(CMAKE_CXX_STANDARD 20)

add_executable(library main.cpp entities/Article.cpp entities/Article.h entities/Book.cpp entities/Book.h entities/Magazine.cpp entities/Magazine.h entities/CD_ROM.cpp entities/CD_ROM.h "data access/Library.cpp" "data access/Library.h")
