#include <iostream>
#include <fstream>
#include <climits> // For INT_MAX

using namespace std;

int Prims(int V, int** adjMatrix) {
    int* key = new int[V];     // Key values used to pick minimum weight edge in cut
    bool* mstSet = new bool[V]; // To represent set of vertices included in MST
    int* parent = new int[V];  // Array to store constructed MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include first vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int minKey = INT_MAX, u;
        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
        }
    }

    // Calculate the total weight of the MST
    int sum = 0;
    for (int i = 1; i < V; i++) {
        sum += adjMatrix[i][parent[i]];
    }

    // Free dynamically allocated memory
    delete[] key;
    delete[] mstSet;
    delete[] parent;

    return sum;
}

int main() {
    ifstream infile("prims.txt");

    if (!infile.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    int V; // number of vertices
    infile >> V;

    // Dynamically allocate memory for the adjacency matrix
    int** adjMatrix = new int*[V];
    for (int i = 0; i < V; i++) {
        adjMatrix[i] = new int[V]();
    }

    int E; // number of edges
    infile >> E;

    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        infile >> src >> dest >> weight;
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight;
    }

    infile.close();

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    int minimumCost = Prims(V, adjMatrix);
    cout << "Minimum cost of spanning tree: " << minimumCost << endl;

    // Free dynamically allocated memory for the adjacency matrix
    for (int i = 0; i < V; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}
