//
// Was no created by Joe Mama.
//

#include <limits>
#include <iostream>
#include "Dijkstra.h"

Dijkstra::Dijkstra(const NeighborhoodList& list) : neighborhoodList(list) {
    distance = new int[neighborhoodList.vertexNumber];
    previous = new int[neighborhoodList.vertexNumber];
    neighbors = new Array *[neighborhoodList.vertexNumber];
    queue = new Array();

    for (int i = 0; i < neighborhoodList.vertexNumber; i++) {
        neighbors[i] = new Array();
        for (int j = 0; j < neighborhoodList.edgeNumber; j++) {
            if (neighborhoodList.edges[j]->source == i)
                neighbors[i]->addEnd(neighborhoodList.edges[j]->destination);
        }
    }

    for (int i = 0; i < neighborhoodList.vertexNumber; i++)
        queue->addEnd(i);
}

int Dijkstra::findShortestPath( int from, int to) {

    for (int i = 0; i < neighborhoodList.vertexNumber; i++)
        distance[i] = std::numeric_limits<int>::max() - 1;

    distance[from] = 0;

    int currentVertex;

    while (queue->getSize() != 0) {
        currentVertex = extractMin();
        for (int i = 0; i < neighbors[currentVertex]->getSize(); i++) {
            int neighbor = neighbors[currentVertex]->getAt(i);
            if(distance[neighbor] > (distance[currentVertex] + weight(currentVertex, neighbor))){
                distance[neighbor] = distance[currentVertex] + weight(currentVertex, neighbor);
                previous[neighbor] = currentVertex;
            }
        }
    }

    for (int i = 0; i < neighborhoodList.vertexNumber; i++) {
        std::cout<<"Shortest distance to "<<i<<" is "<<distance[i]<<std::endl;
    }


    return 0;
}

int Dijkstra::extractMin() {
    int min = std::numeric_limits<int>::max();
    int indexMin = -1;
    for (int i = 0; i < queue->getSize(); i++) {
        if (distance[queue->getAt(i)] < min) {
            indexMin = queue->getAt(i);
            queue->removeAt(i);
            return indexMin;
        }
    }
    queue->removeAt(indexMin);
    return indexMin;
}

int Dijkstra::weight(int source, int destination) const {
    for (int i = 0; i < neighborhoodList.edgeNumber; i++) {
        if (neighborhoodList.edges[i]->source == source){
            if (neighborhoodList.edges[i]->destination == destination)
                return neighborhoodList.edges[i]->wage;
        }
    }

    return std::numeric_limits<int>::max();
}