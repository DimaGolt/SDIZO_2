//
// Created by Home on 02-Jun-22.
//

#ifndef SDIZO_2_GRAPH_H
#define SDIZO_2_GRAPH_H


#include "../IncidenceMatrix/IncidenceMatrix.h"
#include "../NeighborhoodList/NeighborhoodList.h"

class Graph {
public:
    Graph(NeighborhoodList &list, IncidenceMatrix &matrix);
    NeighborhoodList list;
    IncidenceMatrix matrix;
};


#endif //SDIZO_2_GRAPH_H
