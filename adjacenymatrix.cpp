 #include <iostream>
#include <vector>

using namespace std;
void createAdjacencyMatrix(int vertices, vector<pair<int, int>> &edges, vector<vector<int>> &adjMatrix) {
    adjMatrix.assign(vertices, vector<int>(vertices, 0));
    for (auto edge : edges) {
        int u = edge.first;   
        int v = edge.second;  
        
        adjMatrix[u][v] = 1;  
        adjMatrix[v][u] = 1;    
    }
}
void printAdjacencyMatrix(const vector<vector<int>> &adjMatrix) {
    for (const auto &row : adjMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices = 5;  
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {3, 4}
    }; 
    
    vector<vector<int>> adjMatrix;
    createAdjacencyMatrix(vertices, edges, adjMatrix);
    
    cout << "Adjacency Matrix:" << endl;
    printAdjacencyMatrix(adjMatrix);
    
    return 0;
}
