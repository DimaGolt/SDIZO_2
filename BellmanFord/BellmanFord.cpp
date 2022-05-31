#include <limits>
#include <iostream>
#include "BellmanFord.h"

BellmanFord::BellmanFord(const NeighborhoodList &list) : vertexNumber(list.vertexNumber), edgeNumber(list.edgeNumber),
                                                         edges(list.edges) {
    distance = new int[vertexNumber];
    previous = new int[vertexNumber];
}

BellmanFord::BellmanFord(IncidenceMatrix matrix) : vertexNumber(matrix.vertexNumber), edgeNumber(matrix.edgeNumber) {
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

BellmanFord::~BellmanFord() {}

int BellmanFord::findShortestPath(int from, int to) {

    for (int i = 0; i < vertexNumber; i++) {
        distance[i] = std::numeric_limits<int>::max() - 1;
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

    for (int i = 0; i < vertexNumber; i++) {
        std::cout << "Shortest distance is " << distance[i] << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < vertexNumber; i++) {
        std::cout << "Previous is " << previous[i] << std::endl;
    }

    return 0;
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