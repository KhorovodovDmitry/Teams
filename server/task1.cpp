#include "task1.h"


// Функция для проверки, является ли путь циклом
bool graf(const vector<vector<int>>& graph, const vector<int>& path) {
    if (path.empty() || path.front() != path.back()) return false;

    unordered_set<int> visited;

    for (size_t i = 0; i < path.size() - 1; ++i) {
        int node = path[i];

        // Проверяем, был ли узел уже посещён
        if (visited.count(node) > 0) {
            return false; // Узел посещался дважды, путь не является циклом
        }
        visited.insert(node);

        // Проверка, что текущее ребро существует в графе
        if (find(graph[node - 1].begin(), graph[node - 1].end(), path[i + 1]) == graph[node - 1].end()) {
            return false; // Ребро не существует, путь не является циклом
        }
    }

    return true; // Путь является циклом
}

// Функция для построения графа из строки
vector<vector<int>> buildGraph(const string& input, const int& n) {
    vector<vector<int>> graph(n); // Граф на 7 вершин (0-6)

    stringstream ss(input);
    string edge;

    while (getline(ss, edge, ';')) {
        int u, v;
        char delimiter;
        stringstream edgeStream(edge);
        edgeStream >> u >> delimiter >> v;
        graph[u - 1].push_back(v);
    }

    return graph;
}
vector<int> parsePath(const string& pathInput) {
    vector<int> path;
    stringstream ss(pathInput);
    string node;

    while (getline(ss, node, ':')) {
        path.push_back(stoi(node));
    }

    return path;
}
bool gg(QString var, QString answer, int n){
    std::cout << var.toStdString() << std::endl;
    vector<vector<int>> graph = buildGraph(var.toStdString(), n);
    vector<int> path = parsePath(answer.toStdString());
    return graf(graph, path);
}
