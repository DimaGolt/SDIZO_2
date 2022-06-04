#include <iostream>
#include "Kruskal.h"

Kruskal::Kruskal(const NeighborhoodList &list) : vertexNumber(list.vertexNumber), edgeNumber(list.edgeNumber),
                                                 edges(list.edges) {
    sets = new Array *[vertexNumber];
    setsNumber = vertexNumber;
}

Kruskal::Kruskal(const IncidenceMatrix &matrix) : vertexNumber(matrix.vertexNumber), edgeNumber(matrix.edgeNumber) {
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
    sets = new Array *[vertexNumber];
    setsNumber = vertexNumber;
}

Kruskal::~Kruskal() {
    if (edges != nullptr) {
        for (int i = 0; i < edgeNumber; i++) {
            delete edges[i];
        }
        delete[] edges;
    }
    delete[] sets;
}

Graph *Kruskal::findMinimumSpanningTree() {
    Edge **resultEdges = new Edge *[vertexNumber - 1];
    int resultIter = 0;

    for (int i = 0; i < vertexNumber; i++) {
        makeSet(i);
    }

    sortEdges(0, edgeNumber - 1);

    for (int i = 0; i < edgeNumber; i++) {
        Edge *currentEdge = edges[i];
        if (findSet(currentEdge->source) != findSet(currentEdge->destination)) {
            resultEdges[resultIter] = currentEdge;
            resultIter++;
            Union(currentEdge->source, currentEdge->destination);
        }
    }

    auto list = new NeighborhoodList(vertexNumber -1, vertexNumber, resultEdges);
    auto matrix = new IncidenceMatrix(vertexNumber -1, vertexNumber, resultEdges);

    auto *graph = new Graph(*list, *matrix);

    return graph;
}

int Kruskal::findSet(int vertex) {
    for (int i = 0; i < setsNumber; ++i) {
        if (sets[i]->contains(vertex))
            return i;
    }
    return -1;
}

void Kruskal::makeSet(int vertex) {
    sets[vertex] = new Array();
    sets[vertex]->addEnd(vertex);
}

void Kruskal::Union(int vertex1, int vertex2) {
    auto **newSets = new Array *[setsNumber - 1];

    for (int i = 0; i < setsNumber - 1; i++) {
        newSets[i] = new Array();
    }

    int set1 = findSet(vertex1);
    int set2 = findSet(vertex2);
    int smallerIndex = set1 > set2 ? set2 : set1;
    int biggestIndex = set1 < set2 ? set2 : set1;

    for (int i = 0; i < sets[biggestIndex]->size; i++) {
        sets[smallerIndex]->addEnd(sets[biggestIndex]->getAt(i));
    }

    for (int i = 0; i < biggestIndex; i++) {
        newSets[i] = sets[i];
    }

    for (int i = biggestIndex; i < setsNumber - 1; i++) {
        newSets[i] = sets[i + 1];
    }

    delete[] sets;
    sets = newSets;

    setsNumber--;
}

void Kruskal::sortEdges(int l, int p) {
    if (l >= p)
        return;
    auto partition = [&](int lewy, int prawy) {
        int pivo = edges[lewy]->wage;
        int l = lewy;
        int r = prawy;
        while (true) {
            while (edges[l]->wage < pivo) ++l;
            while (edges[r]->wage > pivo) --r;
            if (l < r) {
                std::swap(edges[l], edges[r]);
                ++l;
                --r;
            } else {
                if (r == prawy) r--;
                return r;
            }
        }
    };
    int m = partition(l, p);
    sortEdges(l, m);
    sortEdges(m + 1, p);
}