//
// Created by Home on 02-Jun-22.
//

#ifndef SDIZO_2_GRAPHREADER_H
#define SDIZO_2_GRAPHREADER_H


#include "../Graph/Graph.h"
#include <fstream>

class GraphReader {
public:
    static Graph *loadFromFile(std::string fileName);
};


#endif //SDIZO_2_GRAPHREADER_H
