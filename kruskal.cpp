#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to compare two edges based on their weights
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Find function with path compression
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Union function by rank
void unionByRank(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to implement Kruskal's algorithm
void kruskalMST(vector<Edge>& edges, int V) {
    vector<Edge> result; // To store the resultant MST
    int e = 0; // Initial count of edges in MST
    int i = 0; // Initial index of sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Create V subsets with single elements
    Subset *subsets = new Subset[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1) {
        // Step 2: Pick the smallest edge and increment the index
        Edge next_edge = edges[i++];

        // Find the subsets of the vertices of the picked edge
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause a cycle
        if (x != y) {
            result.push_back(next_edge);
            unionByRank(subsets, x, y);
            e++;
        }
    }

    // Print the resulting MST
    cout << "Edge \tWeight\n";
    for (const auto& edge : result) {
        cout << edge.src << " - " << edge.dest << "\t" << edge.weight << endl;
    }

    delete[] subsets; // Free allocated memory
}

int main() {
    // Number of vertices in the graph
    int V = 4;

    // Create a vector of edges
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // Function call to construct MST using Kruskal's algorithm
    kruskalMST(edges, V);

    return 0;
}
