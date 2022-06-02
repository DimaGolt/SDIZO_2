#include <limits>
#include <iostream>
#include "Dijkstra.h"

Dijkstra::Dijkstra(const NeighborhoodList &list) : vertexNumber(list.vertexNumber), edgeNumber(list.edgeNumber),
                                                   edges(list.edges) {
    distance = new int[vertexNumber];
    previous = new int[vertexNumber];
    neighbors = new Array *[vertexNumber];
    queue = new Array();

    for (int i = 0; i < vertexNumber; i++) {
        neighbors[i] = new Array();
        for (int j = 0; j < edgeNumber; j++) {
            if (edges[j]->source == i)
                neighbors[i]->addEnd(edges[j]->destination);
        }
    }
}

Dijkstra::Dijkstra(const IncidenceMatrix &matrix) : vertexNumber(matrix.vertexNumber), edgeNumber(matrix.edgeNumber) {
    Edge **futureEdges = new Edge *[edgeNumber];

    for (int i = 0; i < edgeNumber; i++) {
        int start = -1, end = -1, wage = -1;
        for (int j = 0; j < vertexNumber; j++) {
            int possibleEdge = matrix.matrix[j][i];
            if (possibleEdge != 0) {
                if (possibleEdge < 0)
                    end = j;
                if (possibleEdge > 0) {
                    start = j;
                    wage = possibleEdge;
                }
            }
        }
        if (start != -1 && end != -1 && wage != -1) {
            futureEdges[i] = new Edge(start, end, wage);
        }
    }
    if (futureEdges[edgeNumber - 1] == nullptr)
        throw "No";

    edges = futureEdges;
    distance = new int[vertexNumber];
    previous = new int[vertexNumber];
    neighbors = new Array *[vertexNumber];
    queue = new Array();

    for (int i = 0; i < vertexNumber; i++) {
        neighbors[i] = new Array();
        for (int j = 0; j < edgeNumber; j++) {
            if (edges[j]->source == i)
                neighbors[i]->addEnd(edges[j]->destination);
        }
    }
}

Dijkstra::~Dijkstra() {
    if (edges != nullptr) {
        for (int i = 0; i < edgeNumber; i++) {
            delete edges[i];
        }
        delete[] edges;
    }
    delete[] distance;
    delete[] previous;
    delete[] neighbors;
    delete queue;
}

int Dijkstra::findShortestPath(int from, int to) {

    for (int i = 0; i < vertexNumber; i++) {
        distance[i] = std::numeric_limits<int>::max() - 1;
        queue->addEnd(i);
        previous[i] = -1;
    }

    distance[from] = 0;

    int currentVertex;

    while (queue->getSize() != 0) {
        currentVertex = extractMin();
        for (int i = 0; i < neighbors[currentVertex]->getSize(); i++) {
            int neighbor = neighbors[currentVertex]->getAt(i);
            if (distance[neighbor] > (distance[currentVertex] + weight(currentVertex, neighbor))) {
                distance[neighbor] = distance[currentVertex] + weight(currentVertex, neighbor);
                previous[neighbor] = currentVertex;
            }
        }
    }

    for (int i = 0; i < vertexNumber; i++) {
        std::cout << "Shortest distance is " << distance[i] << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < vertexNumber; i++) {
        std::cout << "Previous is " << previous[i] << std::endl;
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
    for (int i = 0; i < edgeNumber; i++) {
        if (edges[i]->source == source) {
            if (edges[i]->destination == destination)
                return edges[i]->wage;
        }
    }

    return std::numeric_limits<int>::max();
}