#include <iostream>
#include "NeighborhoodList.h"

NeighborhoodList::NeighborhoodList(int edgeNumber, int vertexNumber, Edge **edges)
        : edgeNumber(edgeNumber), vertexNumber(vertexNumber), edges(edges) {}

NeighborhoodList::~NeighborhoodList() {
    if (edges != nullptr) {
        for (int i = 0; i < edgeNumber; i++) {
            delete[] edges[i];
        }
        delete[] edges;
    }
}

void NeighborhoodList::print() {
    for (int i = 0; i < edgeNumber; i++) {
        std::cout << edges[i]->source << "-" << edges[i]->destination << " | "<< edges[i]->wage<< std::endl;
    }
}
