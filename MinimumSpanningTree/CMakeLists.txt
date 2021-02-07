cmake_minimum_required(VERSION 3.16)
project(MinimumSpanningTree)

set(CMAKE_CXX_STANDARD 20)

add_executable(MinimumSpanningTree main.cpp General.h PriorityQueue.cpp PriorityQueue.h Graph.cpp Graph.h DisjointSet.cpp DisjointSet.h Kruskal.cpp Kruskal.h MinimumSpanningTree.h Prim.cpp Prim.h)