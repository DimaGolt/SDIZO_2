//
// Was no created by Joe Mama.
//

#include <limits>
#include <iostream>
#include "Dijkstra.h"

int Dijkstra::findShortestPath(NeighborhoodList list, int from, int to) {
    neighborhoodList = list;
    distance = new int[neighborhoodList.vertexNumber];
    previous = new int[neighborhoodList.vertexNumber];
    neighbors = new Array *[neighborhoodList.vertexNumber];
    queue = new Array();

    for (int i = 0; i < neighborhoodList.vertexNumber; i++) {
        neighbors[i] = new Array();
        for (int j = 0; j < neighborhoodList.edgeNumber; ++j) {
            if (neighborhoodList.edges[j]->source == i)
                neighbors[i]->addEnd(neighborhoodList.edges[j]->destination);
        }
    }

    for (int i = 0; i < neighborhoodList.vertexNumber; i++)
        queue->addEnd(i);

    for (int i = 0; i < neighborhoodList.vertexNumber; i++)
        distance[i] = std::numeric_limits<int>::max();

    distance[from] = 0;

    int currentVetrex;

    while (queue->getSize() != 0) {
        currentVetrex = extractMin();
        for (int i = 0; i < neighbors[currentVetrex]->getSize(); ++i) {
            if(distance[i] > (distance[currentVetrex]+ weight(currentVetrex, i))){
                distance[i] = distance[currentVetrex]+ weight(currentVetrex, i);
                previous[i] = currentVetrex;
            }
        }
    }

    std::cout<<"Shortest distance is "<<distance[to]<<std::endl;

    return 0;
}

int Dijkstra::extractMin() {
    int min = std::numeric_limits<int>::max();
    int indexMin = -1;
    for (int i = 0; i < queue->getSize(); i++) {
        if (distance[i] < min) {
            min = distance[i];
            indexMin = i;
        }
    }
    queue->removeAt(indexMin);
    return indexMin;
}

int Dijkstra::weight(int source, int destination) {
    for (int i = 0; i < neighborhoodList.edgeNumber; i++) {
        if (neighborhoodList.edges[i]->source == source){
            if (neighborhoodList.edges[i]->destination == destination)
                return i;
        }
    }

    return -1;
}