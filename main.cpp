#include <iostream>
#include "Dijkstra/Dijkstra.h"
#include "BellmanFord/BellmanFord.h"
#include "Prim/Prim.h"
#include "Kruskal/Kruskal.h"
#include "GraphReader/GraphReader.h"

int main() {
    auto graph = GraphReader::loadFromFile("C:\\Users\\Home\\CLionProjects\\SDIZO_2\\graph-3.txt");

    std::cout << "Dijkstra: " << std::endl;
    auto dijkstra1 = new Dijkstra(graph->list);
    auto dijkstra2 = new Dijkstra(graph->matrix);
    auto path1 = dijkstra1->findShortestPath(0, 5);
    path1.print();
    std::cout << std::endl;
    auto path2 = dijkstra2->findShortestPath(0, 5);
    path2.print();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Bellman-ford: " << std::endl;
    auto bellman1 = new BellmanFord(graph->list);
    auto bellman2 = new BellmanFord(graph->matrix);
    auto path3 = bellman1->findShortestPath(0, 5);
    path3.print();
    std::cout << std::endl;
    auto path4 = bellman2->findShortestPath(0, 5);
    path4.print();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Kruskal: " << std::endl;
    auto kruskal1 = new Kruskal(graph->list);
    auto kruskal2 = new Kruskal(graph->matrix);
    auto tree1 = kruskal1->findMinimumSpanningTree();
    tree1->list.print();
    tree1->matrix.print();
    std::cout<<std::endl;
    kruskal2->findMinimumSpanningTree();
//    auto tree2 = kruskal2->findMinimumSpanningTree();
//    tree2->list.print();
//    tree2->matrix.print();
    std::cout<<std::endl;

    std::cout << "Prim: " << std::endl;
    auto prim1 = new Prim(graph->list);
    auto prim2 = new Prim(graph->matrix);
    prim1->findMinimumSpanningTree();
    std::cout << std::endl;
    prim2->findMinimumSpanningTree();
}
