//
// Created by Dima on 30.05.2022.
//

#include <iostream>
#include "IncidenceMatrix.h"

IncidenceMatrix::IncidenceMatrix(int edgeNumber, int vertexNumber, Edge **edges) : edgeNumber(edgeNumber),
                                                                                   vertexNumber(vertexNumber) {
    matrix = new int *[vertexNumber];

    for (int i = 0; i < vertexNumber; i++) {
        matrix[i] = new int[edgeNumber];
        for (int j = 0; j < edgeNumber; j++) {
            matrix[i][j] = insertWage(i, edges[j]);
        }
    }

    for (int i = 0; i < vertexNumber; i++) {
        for (int j = 0; j < edgeNumber; j++) {
            std::cout << " " << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

IncidenceMatrix::~IncidenceMatrix() {

}

int IncidenceMatrix::insertWage(int vertexIndex, Edge *edge) {
    if (vertexIndex == edge->source)
        return edge->wage;
    if (vertexIndex == edge->destination)
        return -edge->wage;
    else return 0;
}
