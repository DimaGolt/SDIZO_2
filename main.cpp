#include <iostream>
#include "Dijkstra/Dijkstra.h"
#include "IncidenceMatrix/IncidenceMatrix.h"
#include "BellmanFord/BellmanFord.h"
#include "Prim/Prim.h"
#include "Kruskal/Kruskal.h"

int main() {
    Edge **edges = new Edge *[9];
    edges[0] = new Edge(0, 1, 3);
    edges[1] = new Edge(0, 4, 3);
    edges[2] = new Edge(1, 2, 1);
    edges[3] = new Edge(2, 3, 3);
    edges[4] = new Edge(2, 5, 1);
    edges[5] = new Edge(3, 1, 3);
    edges[6] = new Edge(4, 5, 2);
    edges[7] = new Edge(5, 0, 6);
    edges[8] = new Edge(5, 3, 1);

    NeighborhoodList list = NeighborhoodList(9, 6, edges);
    IncidenceMatrix matrix = IncidenceMatrix(9, 6, edges);
    auto dijkstra1 = new Dijkstra(list);
    auto dijkstra2 = new Dijkstra(matrix);
    auto *bellman1 = new BellmanFord(list);
    auto *bellman2 = new BellmanFord(matrix);
    dijkstra1->findShortestPath(0, 3);
    std::cout << std::endl;
    dijkstra2->findShortestPath(0, 3);
    bellman1->findShortestPath(0, 3);
    std::cout << std::endl;
    bellman2->findShortestPath(0, 3);

    Edge **edges2 = new Edge *[7];
    edges2[0] = new Edge(0, 1, 3);
    edges2[1] = new Edge(0, 2, 1);
    edges2[2] = new Edge(1, 2, 3);
    edges2[3] = new Edge(1, 3, 4);
    edges2[4] = new Edge(1, 4, 2);
    edges2[5] = new Edge(2, 3, 6);
    edges2[6] = new Edge(4, 3, 5);
    NeighborhoodList list2 = NeighborhoodList(7, 5, edges2);
    IncidenceMatrix matrix2 = IncidenceMatrix(7, 5, edges2);
    Prim *prim1 = new Prim(list2);
    Prim *prim2 = new Prim(matrix2);
    prim1->findMinimumSpanningTree();
    std::cout << std::endl;
    prim2->findMinimumSpanningTree();
    return 0;

//    Edge **edges = new Edge *[7];
//    edges[0] = new Edge(0, 1, 3);
//    edges[1] = new Edge(0, 2, 1);
//    edges[2] = new Edge(1, 2, 3);
//    edges[3] = new Edge(1, 3, 4);
//    edges[4] = new Edge(1, 4, 2);
//    edges[5] = new Edge(2, 3, 6);
//    edges[6] = new Edge(4, 3, 5);
//    NeighborhoodList list = NeighborhoodList(7, 5, edges);
//    IncidenceMatrix matrix = IncidenceMatrix(7, 5, edges);
//    Kruskal kruskal1 = Kruskal(list);
//    Kruskal kruskal2 = Kruskal(matrix);
//    kruskal1.findMinimumSpanningTree();
//    std::cout<<std::endl;
//    kruskal2.findMinimumSpanningTree();

}
