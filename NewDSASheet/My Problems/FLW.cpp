#include <iostream>
#include <climits> // For INT_MAX
#include <fstream>
using namespace std;

#define INF 999
#define MAX 100

void initializeGraph(int** graph, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == INF) {
                graph[i][j] = INT_MAX;
            }
        }
    }
}

void floydWarshall(int** graph, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][k] < INT_MAX && graph[k][j] < INT_MAX) { // To avoid overflow
                    if (graph[i][j] > graph[i][k] + graph[k][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }
}

void printGraph(int** graph, int n) {
    cout << "All the shortest paths: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == INT_MAX) {
                cout << "INF  ";
            } else {
                cout << graph[i][j] << "  ";
            }
        }
        cout << endl;
    }
}

int main() {
    ifstream inputFile("FLW.txt");
    if (!inputFile) {
        cout << "Error opening input file." << endl;
        return 1;
    }

    int n, e;
    inputFile >> n >> e;

    int** graph = new int*[n];
    for (int i = 0; i < n; ++i) {
        graph[i] = new int[n];
    }

    // Initialize the graph with infinity
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INT_MAX;
            }
        }
    }

    for (int i = 0; i < e; ++i) {
        int u, v, w;
        inputFile >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // For undirected graphs, mirror the edge
    }

    inputFile.close();

    initializeGraph(graph, n);
    floydWarshall(graph, n);
    printGraph(graph, n);

    // Free dynamically allocated memory
    for (int i = 0; i < n; ++i) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
