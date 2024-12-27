#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    // BFS traversal
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // DFS traversal
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(start);

        cout << "DFS Traversal: ";

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                visited[node] = true;
                cout << node << " ";

                // Push all unvisited neighbors to the stack
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Create a graph
    Graph g(5); // Graph with 5 vertices

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    // Perform BFS and DFS
    g.BFS(0); // Start BFS from vertex 0
    g.DFS(0); // Start DFS from vertex 0

    return 0;
}
