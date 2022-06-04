//
// Created by Dima on 30.05.2022.
//

#ifndef SDIZO_2_INCIDENCEMATRIX_H
#define SDIZO_2_INCIDENCEMATRIX_H


#include "../Edge/Edge.h"

class IncidenceMatrix {
public:
    IncidenceMatrix(int edgeNumber, int vertexNumber, Edge **edges);

    ~IncidenceMatrix();

    int edgeNumber;
    int vertexNumber;
    int **matrix;

    void print();

private:
    int insertWage(int vertexIndex, Edge *edge);

};


#endif //SDIZO_2_INCIDENCEMATRIX_H
