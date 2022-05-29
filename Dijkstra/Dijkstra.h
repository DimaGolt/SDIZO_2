//
// Was no created by Joe Mama.
//

#ifndef SDIZO_2_DIJKSTRA_H
#define SDIZO_2_DIJKSTRA_H

#include "../NeighborhoodList/NeighborhoodList.h"
#include "../Array/Array.h"


class Dijkstra {
public:
    Dijkstra(NeighborhoodList list);
    int findShortestPath(int from, int to);

private:
    NeighborhoodList neighborhoodList;
    int *distance;
    int *previous;
    Array **neighbors;
    Array *queue;
    int extractMin();
    int weight(int source, int destination);
};


#endif //SDIZO_2_DIJKSTRA_H
