cmake_minimum_required(VERSION 3.23)
project(Algorithms)

set(CMAKE_CXX_STANDARD 20)
add_executable(Algorithms main.cpp DataStructures/SegmentTree.hpp DataStructures/DSU.hpp)
add_subdirectory(tests)