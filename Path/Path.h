#ifndef SDIZO_2_PATH_H
#define SDIZO_2_PATH_H


#include "../Array/Array.h"

class Path {
public:
    Path(int wage): path(new Array()), wage(wage) {};
    Array *path;
    int pathLength = 0;
    int wage;
    void print() {
        std::cout << path->getAt(0);
        for (int i = 1; i < pathLength; ++i) {
            std::cout << "->" << path->getAt(i);
        }
        std::cout << " | " << wage;
    };
};


#endif //SDIZO_2_PATH_H
