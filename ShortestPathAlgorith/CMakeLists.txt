cmake_minimum_required(VERSION 3.16)
project(ShortestPathAlgorith)

set(CMAKE_CXX_STANDARD 20)

add_executable(ShortestPathAlgorith main.cpp ShortestPath.cpp ShortestPath.h Graph.cpp Graph.h PriorityQueue.cpp PriorityQueue.h)