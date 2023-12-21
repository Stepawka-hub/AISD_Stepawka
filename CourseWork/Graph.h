#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <iomanip>
#include <string>

// ����� �����
struct Edge {
    int source, dest, weight;
};

class Graph {
private:
    int v;
    char* vertices;
    int** weight; // 0 - ����������� �����; > 0 - ��� ����� ���������
    void DFSUtil(int , bool []);
    void sortEdge(Edge*, int); // ���������� ���������

public:
    Graph(int, const std::string&);
    int** getweight(); // ������ � �����
    char * getvertices(); // �������� �������
    int getV(); // ���������� ������ �����
    void DFS(); // ����� � �������
    void BFS(); // ����� � ������
    void Kruskal(); // �������� ��������
};

std::ostream& operator<<(std::ostream&, Graph&);

#endif