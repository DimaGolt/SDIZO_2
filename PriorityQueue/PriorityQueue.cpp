#include "PriorityQueue.h"
#include <fstream>

PriorityQueue::PriorityQueue() {
    headerPtr = nullptr;
    size = 0;
}

PriorityQueue::~PriorityQueue() {
    if (headerPtr != nullptr) {
        delete[] headerPtr;
    }
}

void PriorityQueue::push(QueueElement *element) {
    auto **newHeaderPtr = new QueueElement *[size + 1];
    newHeaderPtr[size] = element;

    for (int i = 0; i < size; i++) {
        newHeaderPtr[i] = headerPtr[i];
    }

    delete[] headerPtr;
    headerPtr = newHeaderPtr;
    size++;
    correctQueue();
}

bool PriorityQueue::contains(int index) {
    for (int i = 0; i < size; i++) {
        if (headerPtr[i]->index == index) {
            return true;
        }
    }

    return false;
}

bool PriorityQueue::isEmpty() {
    if (size == 0)
        return true;

    return false;
}

void PriorityQueue::changeKey(int index, int key) {
    for (int i = 0; i < size; i++) {
        if (headerPtr[i]->index == index) {
            headerPtr[i]->key = key;
        }
    }
}

QueueElement *PriorityQueue::pop() {

    if (isEmpty()) {
        return nullptr;
    }

    QueueElement *elementToReturn = headerPtr[0];

    if (size == 1) {
        size--;
        delete[] headerPtr;
        headerPtr = nullptr;

        return elementToReturn;
    }

    auto **newHeaderPtr = new QueueElement *[size - 1];

    for (int i = 0; i < size - 1; i++) {
        newHeaderPtr[i] = headerPtr[i + 1];
    }

    delete[] headerPtr;
    headerPtr = newHeaderPtr;
    size--;

    correctQueue();

    return elementToReturn;
}

void PriorityQueue::correctQueue() {
    int startIndex = (size / 2) - 1;

    for (int i = startIndex; i >= 0; i--)
        heapify(i);
}

void PriorityQueue::heapify(int i) {
    int smallest{i}, left{2 * i + 1}, right{2 * 1 + 2};

    if (headerPtr[left] != nullptr) {
        if (left < size)
            if (headerPtr[left]->key < headerPtr[smallest]->key)
                smallest = left;
    }

    if (headerPtr[right] != nullptr) {
        if (right < size)
            if (headerPtr[right]->key < headerPtr[smallest]->key)
                smallest = right;
    }

    if (smallest != i) {
        std::swap(headerPtr[i], headerPtr[smallest]);

        heapify(smallest);
    }
}
