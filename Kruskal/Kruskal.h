#ifndef SDIZO_2_KRUSKAL_H
#define SDIZO_2_KRUSKAL_H


#include "../NeighborhoodList/NeighborhoodList.h"
#include "../IncidenceMatrix/IncidenceMatrix.h"
#include "../Array/Array.h"

class Kruskal {
public:
    Kruskal(const NeighborhoodList &list);

    Kruskal(const IncidenceMatrix &matrix);

    ~Kruskal();

    int findMinimumSpanningTree();

private:
    Edge **edges;
    int vertexNumber;
    int edgeNumber;
    int setsNumber;
    Array **sets;

    int findSet(int vertex);

    void makeSet(int vertex);

    void Union(int vertex1, int vertex2);

    void sortEdges(int l, int p);
};


#endif //SDIZO_2_KRUSKAL_H
