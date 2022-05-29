#ifndef SDIZO_1_ARRAY_H
#define SDIZO_1_ARRAY_H


#include <string>

class Array {

public:
    int *headerPtr;

    int size;

    Array();
    ~Array();
    void addFront(int var);
    void addEnd(int var);
    void addAt(int var, int index);
    void removeLast();
    void removeFirst();
    void removeAt(int index);
    int contains(int var);
    void print();
    void fromFile(std::string fileName);
    int getSize();
};


#endif //SDIZO_1_ARRAY_H
