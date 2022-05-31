#ifndef SDIZO_2_BELLMANFORD_H
#define SDIZO_2_BELLMANFORD_H


#include "../NeighborhoodList/NeighborhoodList.h"
#include "../IncidenceMatrix/IncidenceMatrix.h"

class BellmanFord {

public:
    BellmanFord(const NeighborhoodList &list);

    BellmanFord(IncidenceMatrix matrix);

    ~BellmanFord();

    int findShortestPath(int from, int to);

private:
    int vertexNumber;
    int edgeNumber;
    Edge **edges;
    int *distance;
    int *previous;

    int weight(int source, int destination) const;
};


#endif //SDIZO_2_BELLMANFORD_H
