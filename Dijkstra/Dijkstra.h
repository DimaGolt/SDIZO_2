//
// Was no created by Joe Mama.
//

#ifndef SDIZO_2_DIJKSTRA_H
#define SDIZO_2_DIJKSTRA_H

#include "../NeighborhoodList/NeighborhoodList.h"
#include "../Array/Array.h"


class Dijkstra {
public:
    static int findShortestPath(NeighborhoodList list, int from, int to);

private:
    static NeighborhoodList neighborhoodList;
    static int *distance;
    static int *previous;
    static Array **neighbors;
    static Array *queue;
    static int extractMin();
    static int weight(int source, int destination);
};


#endif //SDIZO_2_DIJKSTRA_H
