//
// Created by Home on 02-Jun-22.
//

#include "GraphReader.h"

Graph* GraphReader::loadFromFile(std::string fileName) {
    std::ifstream file(fileName); //otwieramy plik ze ścieżki podanej przez usera
    if(file.fail()){
        return nullptr;
    }
    int edgeNumber, vertexNumber;

    file >> edgeNumber >> vertexNumber; //pierwsza linia pliku zawiera ilość krawędzi oraz wierzchołków w pliku

    Edge **edges = new Edge *[edgeNumber];; //tworzymy pomocniczą dynamiczną tablicę

    for (int i = 0; i < edgeNumber; i++) {// uzupełniamy pomocniczą tablicę wartościami z pliku
        int source, destination, wage;
        file >> source >> destination >> wage ;
        edges[i] = new Edge(source, destination, wage);
    }
    auto list = new NeighborhoodList(edgeNumber, vertexNumber, edges);
    auto matrix = new IncidenceMatrix(edgeNumber, vertexNumber, edges);
    auto graph = new Graph(*list, *matrix);
    return graph;
}