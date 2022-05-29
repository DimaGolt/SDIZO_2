//
// Was no created by Joe Mama.
//

#include "NeighborhoodList.h"

NeighborhoodList::NeighborhoodList(int edgeNumber, int vertexNumber, Edge **edges)
        : edgeNumber(edgeNumber), vertexNumber(vertexNumber), edges(edges) {}

NeighborhoodList::~NeighborhoodList() {
    if (edges != nullptr) {
        Edge *edgeToDelete = nullptr;
        for (int i = edgeNumber; i >= 0; i++) {
            edgeToDelete = edges[i];

            delete edgeToDelete;
        }
        delete[] edges;
    }
}