#ifndef SDIZO_2_PRIM_H
#define SDIZO_2_PRIM_H


#include "../Array/Array.h"
#include "../PriorityQueue/PriorityQueue.h"
#include "../Edge/Edge.h"
#include "../NeighborhoodList/NeighborhoodList.h"
#include "../IncidenceMatrix/IncidenceMatrix.h"
#include "../Graph/Graph.h"

class Prim {

public:
    Prim(const NeighborhoodList &list);

    Prim(const IncidenceMatrix &matrix);

    Graph *findMinimumSpanningTree();

    ~Prim();

private:
    Edge **edges;
    int vertexNumber;
    int edgeNumber;
    int *key;
    int *previous;
    Array **neighbors;
    PriorityQueue queue;

    int extractMin();

    int weight(int vertex1, int vertex2) const;
};


#endif //SDIZO_2_PRIM_H
