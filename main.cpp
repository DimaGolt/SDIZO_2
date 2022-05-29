#include "Dijkstra/Dijkstra.h"

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
    Dijkstra* dijkstra = new Dijkstra(list);
    dijkstra->findShortestPath( 0, 3);
    return 0;
}
