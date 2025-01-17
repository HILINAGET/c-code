# c-code

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent a graph
struct Edge {
    int src, dest, weight;
};

// A class to represent a connected, undirected graph
class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adjMatrix; // Adjacency matrix

    Graph(int V);
    void addEdge(int u, int v, int w);
    void primMST();
};

// Constructor
Graph::Graph(int V) {
    this->V = V;
    adjMatrix.resize(V, vector<int>(V, INT_MAX));
}

// Function to add an edge to the graph
void Graph::addEdge(int u, int v, int w) {
    adjMatrix[u][v] = w;
    adjMatrix[v][u] = w; // Since the graph is undirected
}

// Function to find the vertex with the minimum key value
int minKey(const vector<int>& key, const vector<bool>& mstSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < key.size(); v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to construct and print the MST using Prim's algorithm
void Graph::primMST() {
    vector<int> parent(V); // Array to store constructed MST
    vector<int> key(V, INT_MAX); // Key values to pick minimum weight edge
    vector<bool> mstSet(V, false); // To represent the vertices included in MST

    key[0] = 0; // Start from the first vertex
    parent[0] = -1; // First node is always the root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // Pick the minimum key vertex

        mstSet[u] = true; // Add it to the MST

        for (int v = 0; v < V; v++) {
            // Update key only if adjacently and not in mstSet
            if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
        }
    }

    // Print the constructed MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << adjMatrix[i][parent[i]] << " \n";
    }
}

int main() {
    // Create a graph given in the above example
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.primMST();

    return 0;
}
