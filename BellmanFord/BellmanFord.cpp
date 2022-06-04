#include <limits>
#include <iostream>
#include "BellmanFord.h"

BellmanFord::BellmanFord(const NeighborhoodList &list) : vertexNumber(list.vertexNumber), edgeNumber(list.edgeNumber),
                                                         edges(list.edges) {
    distance = new int[vertexNumber];
    previous = new int[vertexNumber];
}

BellmanFord::BellmanFord(const IncidenceMatrix &matrix) : vertexNumber(matrix.vertexNumber), edgeNumber(matrix.edgeNumber) {
    Edge **futureEdges = new Edge *[edgeNumber];

    for (int i = 0; i < edgeNumber; i++) {
        int start = -1, end = -1, wage = -1;
        for (int j = 0; j < vertexNumber; j++) {
            int possibleWage = matrix.matrix[j][i];
            if (possibleWage != 0) {
                if (possibleWage < 0)
                    end = j;
                if (possibleWage > 0) {
                    start = j;
                    wage = possibleWage;
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
}

BellmanFord::~BellmanFord() {
    if (edges != nullptr) {
        for (int i = edgeNumber -1; i >= 0; i--) {
            delete edges[i];
        }
        delete[] edges;
    }
    delete[] distance;
    delete[] previous;
}

Path BellmanFord::findShortestPath(int from, int to) {

    for (int i = 0; i < vertexNumber; i++) {
        distance[i] = std::numeric_limits<int>::max() - 2000;
        previous[i] = -1;
    }

    distance[from] = 0;

    for (int i = 0; i < vertexNumber - 1; i++) {
        bool didFix = false;
        for (int j = 0; j < edgeNumber; j++) {
            int source = edges[j]->source;
            int destination = edges[j]->destination;
            if (distance[destination] > (distance[source] + weight(source, destination))) {
                distance[destination] = distance[source] + weight(source, destination);
                previous[destination] = source;
                didFix = true;
            }
        }
        if (!didFix) {
            break;
        }
    }

    Path path(distance[to]);

    int iter = to;
    path.path->addEnd(iter);
    path.pathLength++;
    while(previous[iter] != -1){
        iter = previous[iter];
        path.path->addFront(iter);
        path.pathLength++;
    }

    return path;
}

int BellmanFord::weight(int source, int destination) const {
    for (int i = 0; i < edgeNumber; i++) {
        if (edges[i]->source == source) {
            if (edges[i]->destination == destination)
                return edges[i]->wage;
        }
    }

    return std::numeric_limits<int>::max();
}