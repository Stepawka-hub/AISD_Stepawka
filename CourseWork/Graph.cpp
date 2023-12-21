#include "Graph.h"
#include "MySet.h"
#include <queue>
#include <fstream>
#include <sstream>
#include <string>

Graph::Graph(int v, const std::string& filename) {
    this->v = v;
    vertices = new char[v];
    weight = new int* [v];
    for (int i = 0; i < v; i++)
        weight[i] = new int[v];

    std::ifstream file(filename);
    if (!file)
        std::cout << "\x1B[91mФайл не найден!";

    // Считываем строку с рёбрами
    std::string line;
    std::getline(file, line);
    std::istringstream streamline(line);
    std::string vertex;

    int i = 0;
    while (streamline >> vertex && i < v)
        vertices[i++] = vertex[0];

    int index = 0;
    while (std::getline(file, line) && index < v) {
        std::istringstream matrixStream(line);
        int value;

        for (int j = 0; j < v; j++) {
            matrixStream >> value;
            weight[index][j] = value;
        }

        index++;
    }

    file.close();

}

int** Graph::getweight() {
    int** tempweight = new int* [v];

    for (int i = 0; i < v; ++i) {
        tempweight[i] = new int[v];

        for (int j = 0; j < v; ++j)
            tempweight[i][j] = weight[i][j];
    }

    return tempweight;
}

char* Graph::getvertices() {
    char* tempvertices = new char [v];

    for (int i = 0; i < v; ++i)
        tempvertices[i] = vertices[i];

    return tempvertices;
}

int Graph::getV() {
    return this->v;
}

void Graph::DFS() {
    bool* visited = new bool[v]; // Массив посещений

    for (int i = 0; i < v; ++i)
        visited[i] = false;

    for (int i = 0; i < v; ++i) {
        if (!visited[i])
            DFSUtil(i, visited);
    }

    delete[] visited;
}

void Graph::DFSUtil(int v, bool visited[]) {
    visited[v] = true;
    std::cout << vertices[v] << " ";

    for (int i = 0; i < v; ++i) {
        if (weight[v][i] > 0 && !visited[i]) // Если вершина i не посещена и имеется ребро от текущей вершины v до вершины i
            DFSUtil(i, visited);
    }
}

void Graph::BFS() {
    int start = 0;
    bool* visited = new bool[v]; // Массив для отслеживания посещенных вершин
    for (int i = 0; i < v; ++i)
        visited[i] = false;

    std::queue<int> queue;
    queue.push(start); // Помещаем начальную вершину в очередь...
    visited[start] = true; // и помечаем её как посещенную

    while (!queue.empty()) {
        int top = queue.front(); // Извлекаем текущую вершину из очереди
        queue.pop();
        std::cout << vertices[top] << " ";

        // Добавляем в очередь соседние вершины, если они не были посещены
        for (int i = 0; i < v; ++i) {
            if (weight[top][i] && !visited[i]) {
                queue.push(i);
                visited[i] = true;
            }
        }
    }

    delete[] visited;
}

void Graph::sortEdge(Edge * Array, int N) {
    int i, j;
    Edge tempArr;
    for (i = 1; i < N; i++) {
        tempArr = Array[i];
        j = i - 1;

        while (j >= 0 && (Array[j].weight > tempArr.weight)) {
            Array[j + 1] = Array[j];
            j = j - 1;
        }
        Array[j + 1] = tempArr;
    }
}

void Graph::Kruskal() {
    Edge* result = new Edge[v - 1]; // Максимальное количество рёбер в остовном дереве

    // Отсортированный массив рёбер
    Edge* edges = new Edge[v * (v - 1) / 2]; // Максимальное количество ребер

    // Заполнение массива рёбер из матрицы смежности
    int k = 0;
    for (int i = 0; i < v; i++) {
        for (int j = i + 1; j < v; j++) {
            if (weight[i][j] > 0) {
                edges[k].source = i;
                edges[k].dest = j;
                edges[k].weight = weight[i][j];
                k++;
            }
        }
    }

    // Сортировка рёбер по весу
    sortEdge(edges, k);

    for (int i = 0; i < v; i++)
        MakeSet(i);

    // Добавление рёбер в остовное дерево
    int j = 0;
    for (int i = 0; i < k && j < v - 1; i++) {
        int x = Find(edges[i].source);
        int y = Find(edges[i].dest);
        if (x != y) {
            result[j++] = edges[i];
            Union(x, y);
        }
    }

    // Вывод минимального остовное дерево
    int path = 0;
    for (int i = 0; i < v - 1; i++) {
        std::cout << "\x1B[96m[" << vertices[result[i].source] << " - " << vertices[result[i].dest] << "]: "
            << "\x1B[93m" << result[i].weight << std::endl;
        path += result[i].weight;
    }
    std::cout << "\n\x1B[96mВес: \x1B[93m" << path;

    delete[] result;
    delete[] edges;
}

std::ostream& operator<<(std::ostream& os, Graph& graph) {
    int** tempweight = graph.getweight();
    char* tempvertices = graph.getvertices();

    std::cout << "\x1B[91m";
    for (int i = 0; i < graph.getV(); ++i)
        os << std::setw(4) << tempvertices[i] << " ";

    os << "\x1B[96m\n";
    for (int i = 0; i < graph.getV(); ++i) {
        for (int j = 0; j < graph.getV(); ++j) {
            os << std::setw(4) << tempweight[i][j] << " ";
        }
        os << "\n";
    }

    return os;
}
