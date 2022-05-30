//
// Was no created by Joe Mama.
//

#ifndef SDIZO_2_DIJKSTRA_H
#define SDIZO_2_DIJKSTRA_H

#include "../NeighborhoodList/NeighborhoodList.h"
#include "../Array/Array.h"
#include "../IncidenceMatrix/IncidenceMatrix.h"


class Dijkstra {
public:
    Dijkstra(const NeighborhoodList &list);

    Dijkstra(IncidenceMatrix matrix);

    int findShortestPath(int from, int to);

private:
    Edge **edges;
    int vertexNumber;
    int edgeNumber;
    int *distance;
    int *previous;
    Array **neighbors;
    Array *queue;

    int extractMin();

    int weight(int source, int destination) const;
};


#endif //SDIZO_2_DIJKSTRA_H
