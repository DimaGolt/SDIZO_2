cmake_minimum_required(VERSION 3.22)
project(SDIZO_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(SDIZO_2 main.cpp NeighborhoodList/NeighborhoodList.cpp NeighborhoodList/NeighborhoodList.h Edge/Edge.cpp Edge/Edge.h Dijkstra/Dijkstra.cpp Dijkstra/Dijkstra.h Array/Array.cpp Array/Array.h IncidenceMatrix/IncidenceMatrix.cpp IncidenceMatrix/IncidenceMatrix.h BellmanFord/BellmanFord.cpp BellmanFord/BellmanFord.h PriorityQueue/PriorityQueue.cpp PriorityQueue/PriorityQueue.h PriorityQueue/QueueElement.h Prim/Prim.cpp Prim/Prim.h PriorityQueue/QueueElement.cpp)
