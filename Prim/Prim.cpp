#include <limits>
#include <iostream>
#include "Prim.h"

Prim::Prim(const NeighborhoodList &list) : vertexNumber(list.vertexNumber), edgeNumber(list.edgeNumber),
                                           edges(list.edges) {
    key = new int[vertexNumber];
    previous = new int[vertexNumber];
    neighbors = new Array *[vertexNumber];
    queue = PriorityQueue();

    for (int i = 0; i < vertexNumber; i++) {
        neighbors[i] = new Array();
        for (int j = 0; j < edgeNumber; j++) {
            if (edges[j]->source == i)
                if (!neighbors[i]->contains(edges[j]->destination))
                    neighbors[i]->addEnd(edges[j]->destination);
            if (edges[j]->destination == i)
                if (!neighbors[i]->contains(edges[j]->source))
                    neighbors[i]->addEnd(edges[j]->source);
        }
    }
}

Prim::Prim(const IncidenceMatrix &matrix) : vertexNumber(matrix.vertexNumber), edgeNumber(matrix.edgeNumber) {
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

    key = new int[vertexNumber];
    previous = new int[vertexNumber];
    neighbors = new Array *[vertexNumber];
    queue = PriorityQueue();

    for (int i = 0; i < vertexNumber; i++) {
        neighbors[i] = new Array();
        for (int j = 0; j < edgeNumber; j++) {
            if (edges[j]->source == i)
                if (!neighbors[i]->contains(edges[j]->destination))
                    neighbors[i]->addEnd(edges[j]->destination);
            if (edges[j]->destination == i)
                if (!neighbors[i]->contains(edges[j]->source))
                    neighbors[i]->addEnd(edges[j]->source);
        }
    }
}

Prim::~Prim() {}

int Prim::findMinimumSpanningTree() {
    for (int i = 0; i < vertexNumber; i++) {
        key[i] = std::numeric_limits<int>::max() - 1;
    }
    key[0] = 0;
    previous[0] = -1;

    for (int i = 0; i < vertexNumber; i++) {
        queue.push(new QueueElement(i, key[i]));
    }

    while (!queue.isEmpty()) {
        int currentVertex = extractMin();

        for (int i = 0; i < neighbors[currentVertex]->size; i++) {
            int vertex = neighbors[currentVertex]->getAt(i);
            if (queue.contains(vertex) && weight(currentVertex, vertex) < key[vertex]) {
                key[vertex] = weight(currentVertex, vertex);
                previous[vertex] = currentVertex;
                queue.changeKey(vertex, key[vertex]);
            }
        }
    }

    for (int i = 0; i < vertexNumber; i++) {
        std::cout << "1: " << key[i] << "/" << previous[i] << std::endl;
    }

    return 0;
}

int Prim::extractMin() {
    QueueElement *element = queue.pop();
    return element->index;
}

int Prim::weight(int vertex1, int vertex2) const {
    for (int i = 0; i < edgeNumber; i++) {
        if (edges[i]->source == vertex1) {
            if (edges[i]->destination == vertex2)
                return edges[i]->wage;
        }
        if (edges[i]->source == vertex2) {
            if (edges[i]->destination == vertex1)
                return edges[i]->wage;
        }
    }

    return std::numeric_limits<int>::max();
}