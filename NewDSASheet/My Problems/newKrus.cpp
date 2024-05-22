#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to compare two edges based on their weights
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Function to find the parent of a vertex
int findParent(int vertex, vector<int>& parent) {
    if (parent[vertex] == -1)
        return vertex;
    return findParent(parent[vertex], parent);
}

// Function to perform Kruskal's algorithm
void kruskalsAlgorithm(vector<Edge>& edges, int numVertices) {
    // Sort the edges in non-decreasing order of their weights
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(numVertices, -1); // Parent array to track disjoint sets
    vector<Edge> mst; // Minimum Spanning Tree

    int numEdges = 0; // Counter to keep track of the number of edges in MST

    for (const auto& edge : edges) {
        int srcParent = findParent(edge.src, parent);
        int destParent = findParent(edge.dest, parent);

        // If including this edge does not form a cycle, add it to the MST
        if (srcParent != destParent) {
            mst.push_back(edge);
            numEdges++;

            // Union the two sets
            parent[srcParent] = destParent;

            // If MST has V-1 edges, where V is the number of vertices, exit the loop
            if (numEdges == numVertices - 1)
                break;
        }
    }

    // Print the Minimum Spanning Tree
    cout << "Minimum Spanning Tree:" << endl;
    for (const auto& edge : mst) {
        cout << edge.src << " -- " << edge.dest << " : " << edge.weight << endl;
    }
}

int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    vector<Edge> edges;
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            int weight;
            cin >> weight;
            if (weight != 0) {
                Edge edge;
                edge.src = i;
                edge.dest = j;
                edge.weight = weight;
                edges.push_back(edge);
            }
        }
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cout << edges[i * numVertices + j].weight << " ";
        }
        cout << endl;
    }

    kruskalsAlgorithm(edges, numVertices);

    return 0;
}