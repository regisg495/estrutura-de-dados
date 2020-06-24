cmake_minimum_required(VERSION 3.14)
project(SearchAndSortAlgorithms C)

set(CMAKE_C_STANDARD 99)

add_executable(SearchAndSortAlgorithms main.c sort.c sort.h search.c search.h basiclist.c basiclist.h)