#include <iostream>
#include <fstream>
#include "Array.h"

using namespace std;

Array::Array() {

    Array::headerPtr = nullptr;
    Array::size = 0;
}

Array::~Array() {

    if (headerPtr != nullptr) {
        delete[] headerPtr;
    }
}

void Array::addFront(int var) {

    int *newHeaderPtr = new int[size + 1];
    newHeaderPtr[0] = var;

    //Copy data
    for (int i = 0; i < size; i++) {
        newHeaderPtr[i + 1] = headerPtr[i];
    }

    //Delete old header
    delete headerPtr;
    headerPtr = newHeaderPtr;

    size++;
}

void Array::addEnd(int var) {

    int *newHeaderPtr = new int[size + 1];
    newHeaderPtr[size] = var;

    for (int i = 0; i < size; i++) {
        newHeaderPtr[i] = headerPtr[i];
    }

    delete headerPtr;
    headerPtr = newHeaderPtr;

    size++;
}

void Array::addAt(int var, int index) {

    //Check if index is correct
    if (index < 0 || index > size) {
        cout << "Can't add element at index " << index << ", out of bounds" << endl;
    } else {

        int *newHeaderPtr = new int[size + 1];
        //Add variable at index
        newHeaderPtr[index] = var;

        //Copy data before index
        for (int i = 0; i < index; i++) {
            newHeaderPtr[i] = headerPtr[i];
        }

        //Copy data after index
        for (int i = index; i < size; i++) {
            newHeaderPtr[i + 1] = headerPtr[i];
        }

        delete headerPtr;
        headerPtr = newHeaderPtr;

        size++;
    }
}


void Array::removeLast() {

    if (size > 0) {
        int *newHeaderPtr = new int[size - 1];

        for (int i = 0; i < size - 1; i++) {
            newHeaderPtr[i] = headerPtr[i];
        }

        delete[] headerPtr;
        headerPtr = newHeaderPtr;

        size--;
    } else {
        cout << "Array is empty" << endl;
    }
}

void Array::removeFirst() {

    if (size > 0) {
        int *newHeaderPtr = new int[size - 1];

        for (int i = 0; i < size - 1; i++) {
            newHeaderPtr[i] = headerPtr[i + 1];
        }

        delete[] headerPtr;
        headerPtr = newHeaderPtr;

        size--;
    } else {
        cout << "Array is empty" << endl;
    }
}

void Array::removeAt(int index) {

    if(size - 1 == 0){
        delete[] headerPtr;
        headerPtr = nullptr;
        size--;
    }else if (index > size || index < 0) {
        cout << "Index out of bounds" << endl;
    } else if (size > 0 || index > 0 || index < size) {
        int *newHeaderPtr = new int[size - 1];

        for (int i = 0; i < index; i++) {
            newHeaderPtr[i] = headerPtr[i];
        }

        for (int i = index; i < size - 1; i++) {
            newHeaderPtr[i] = headerPtr[i + 1];
        }

        delete[] headerPtr;
        headerPtr = newHeaderPtr;

        size--;
    } else {
        cout << "Array is empty" << endl;
    }
}

bool Array::contains(int var) {

    //Iterate until end
    for (int i = 0; i < size; i++) {
        if (headerPtr[i] == var) {
            return true;
        }
    }
    return false;
}

void Array::print() {
    if (headerPtr != nullptr) {
        cout << "Array contains: " << endl;
        for (int i = 0; i < size; i++) {
            cout << " [" << i << "] " << headerPtr[i] << endl;
        }
    } else {
        cout << "Array is empty" << endl;
    }
}

int Array::getSize() {
    return size;
}

int Array::getAt(int index) {
    return headerPtr[index];
}

void Array::fromFile(string fileName) {
    ifstream file(fileName); //otwieramy plik ze ??cie??ki podanej przez usera
    int elementsCount;
    string buff = "";
    getline(file, buff);
    elementsCount = stoi(buff); //pierwsza linia pliku zawiera ilo???? element??w w pliku

    int *newTable = new int[elementsCount]; //tworzymy pomocnicz?? dynamiczn?? tablic??

    for (int i = 0; i < elementsCount; i++) {     // uzupe??niamy pomocnicz?? tablic?? warto??ciami z pliku
        getline(file, buff);
        newTable[i] =
                std::stoi(buff);
    }

    for (int i = 0; i < elementsCount; ++i) {
        addEnd(newTable[i]);
    }
}