//
// Was no created by Joe Mama.
//

#ifndef SDIZO_2_EDGE_H
#define SDIZO_2_EDGE_H


struct Edge {
    int source;
    int destination;
    int wage;

    Edge(int source, int destination, int wage) : source(source), destination(destination), wage(wage) {}
};


#endif //SDIZO_2_EDGE_H
