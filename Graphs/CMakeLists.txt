cmake_minimum_required(VERSION 3.16)
project(Graphs)

set(CMAKE_CXX_STANDARD 20)

add_executable(Graphs main.cpp Graph.cpp Graph.h BinaryHeap.h)