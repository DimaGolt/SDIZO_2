cmake_minimum_required(VERSION 3.22)
project(SDIZO_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(SDIZO_2 main.cpp NeighborhoodList/NeighborhoodList.cpp NeighborhoodList/NeighborhoodList.h Edge/Edge.cpp Edge/Edge.h Dijkstra/Dijkstra.cpp Dijkstra/Dijkstra.h Array/Array.cpp Array/Array.h)
