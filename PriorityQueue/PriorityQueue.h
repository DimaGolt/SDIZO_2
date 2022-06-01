#ifndef SDIZO_2_PRIORITYQUEUE_H
#define SDIZO_2_PRIORITYQUEUE_H

#include "QueueElement.h"

class PriorityQueue {

public:
    PriorityQueue();

    ~PriorityQueue();

    void push(QueueElement *element);

    QueueElement *pop();

    bool contains(int index);

    bool isEmpty();

    void changeKey(int index, int key);

private:
    QueueElement **headerPtr;

    int size;

    void correctQueue();

    void heapify(int i);
};


#endif //SDIZO_2_PRIORITYQUEUE_H
