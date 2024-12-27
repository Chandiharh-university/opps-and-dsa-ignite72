#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to perform Dijkstra's algorithm
void dijkstra(const vector<vector<pair<int, int>>>& graph, int V, int src) {
    // Create a priority queue to store (distance, vertex) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Create a vector to store the shortest distance from the source to each vertex
    vector<int> dist(V, INT_MAX);
    dist[src] = 0; // Distance from source to itself is 0

    // Push the source vertex into the priority queue
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        // Get the vertex with the minimum distance
        int u = pq.top().second;
        pq.pop();

        // Explore all adjacent vertices of the current vertex
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first; // Adjacent vertex
            int weight = neighbor.second; // Weight of the edge

            // If a shorter path to v is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight; // Update the distance
                pq.push(make_pair(dist[v], v)); // Push the updated distance into the priority queue
            }
        }
    }

    // Print the shortest distances from the source
    cout << "Vertex Distance from Source (" << src << "):\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main() {
    // Number of vertices in the graph
    int V = 5;

    // Create a graph using an adjacency list
    vector<vector<pair<int, int>>> graph(V);

    // Add edges (u, v, weight)
    graph[0].push_back(make_pair(1, 10));
    graph[0].push_back(make_pair(2, 3));
    graph[1].push_back(make_pair(2, 1));
    graph[1].push_back(make_pair(3, 2));
    graph[2].push_back(make_pair(1, 4));
    graph[2].push_back(make_pair(3, 8));
    graph[2].push_back(make_pair(4, 2));
    graph[3].push_back(make_pair(4, 7));
    graph[4].push_back(make_pair(3, 9));

    // Call Dijkstra's algorithm from the source vertex 0
    dijkstra(graph, V, 0);

    return 0;
}
