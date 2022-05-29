//
// Was no created by Joe Mama.
//

#include "NeighborhoodList.h"

NeighborhoodList::NeighborhoodList(int edgeNumber, int vertexNumber, Edge **edges)
        : edgeNumber(edgeNumber), vertexNumber(vertexNumber), edges(edges) {}

NeighborhoodList::~NeighborhoodList() {
    if (edges != nullptr) {
        for (int i = edgeNumber -1; i >= 0; i--) {
            delete edges[i];
        }
        delete[] edges;
    }
}