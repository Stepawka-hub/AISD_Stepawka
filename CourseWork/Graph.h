#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <iomanip>
#include <string>

// Ребро графа
struct Edge {
    int source, dest, weight;
};

class Graph {
private:
    int v;
    char* vertices;
    int** weight; // 0 - отсутствует ребро; > 0 - вес между вершинами
    void DFSUtil(int , bool []);
    void sortEdge(Edge*, int); // Сортировка вставками

public:
    Graph(int, const std::string&);
    int** getweight(); // данные о графе
    char * getvertices(); // получить вершины
    int getV(); // количество вершин графа
    void DFS(); // Обход в глубину
    void BFS(); // Обход в ширину
    void Kruskal(); // Алгоритм Краскала
};

std::ostream& operator<<(std::ostream&, Graph&);

#endif