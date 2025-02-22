 #include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void addEdge(unordered_map<int, vector<int>>& graph, int u, int v) {
    graph[u].push_back(v); // Add v to u's list
    graph[v].push_back(u); // Add u to v's list (for undirected graph)
}


void printGraph(const unordered_map<int, vector<int>>& graph) {
    for (const auto& vertex : graph) {
        cout << vertex.first << " -> ";
        for (int neighbor : vertex.second) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    unordered_map<int, vector<int>> graph; // Graph representation using adjacency list

  
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);


    printGraph(graph);

    return 0;
}
