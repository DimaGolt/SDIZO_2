//
// Was no created by Joe Mama.
//

#ifndef SDIZO_2_NEIGHBORHOODLIST_H
#define SDIZO_2_NEIGHBORHOODLIST_H
#include "../Edge/Edge.h"


class NeighborhoodList {
public:
    NeighborhoodList(int edgeNumber, int vertexNumber, Edge** edges);
    ~NeighborhoodList();
    int edgeNumber;
    int vertexNumber;
    Edge** edges;
};


#endif //SDIZO_2_NEIGHBORHOODLIST_H
