#include <limits>
#include <iostream>
#include "Prim.h"
#include "../Graph/Graph.h"

Prim::Prim(const NeighborhoodList &list) : vertexNumber(list.vertexNumber), edgeNumber(list.edgeNumber),
                                           edges(list.edges) {
    key = new int[vertexNumber];
    previous = new int[vertexNumber];
    neighbors = new Array *[vertexNumber];
    queue = PriorityQueue();

    for (int i = 0; i < vertexNumber; i++) {
        neighbors[i] = new Array();
    }

    for (int i = 0; i < edgeNumber; i++) {
        neighbors[edges[i]->destination]->addEnd(edges[i]->source);
        neighbors[edges[i]->source]->addEnd(edges[i]->destination);
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
    }

    for (int i = 0; i < edgeNumber; i++) {
        neighbors[edges[i]->destination]->addEnd(edges[i]->source);
        neighbors[edges[i]->source]->addEnd(edges[i]->destination);
    }
}

Prim::~Prim() {
    if (edges != nullptr) {
        for (int i = 0; i < edgeNumber; i++) {
            delete edges[i];
        }
        delete[] edges;
    }
    delete[] key;
    delete[] previous;
    delete[] neighbors;
}

Graph *Prim::findMinimumSpanningTree() {
    for (int i = 0; i < vertexNumber; i++) {
        key[i] = std::numeric_limits<int>::max() - 2000;
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

    auto resultEdges = new Edge *[vertexNumber-1];

    for (int i = 1; i < vertexNumber; i++) {
        resultEdges[i-1] = new Edge(i, previous[i], key[i]);
    }

    auto list = new NeighborhoodList(vertexNumber -1, vertexNumber, resultEdges);
    auto matrix = new IncidenceMatrix(vertexNumber -1, vertexNumber, resultEdges);

    auto *graph = new Graph(*list, *matrix);

    return graph;
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