#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

const long long INF = LLONG_MAX;

void initializeDist(long long dist[], int n, long long value) {
    for (int i = 0; i < n; ++i) {
        dist[i] = value;
    }
}

void BellmanFord(int** graph, int n, int e, int source, long long dist[]) {
    initializeDist(dist, n, INF);
    dist[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < e; i++) {
        int u = graph[i][0];
        int v = graph[i][1];
        int weight = graph[i][2];

        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            // Negative cycle detected
            dist[0] = -1;
            return;
        }
    }
}

int main() {
    ifstream infile("BFWSTL.txt");
    if (!infile.is_open()) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    int n, e;
    infile >> n >> e;
    infile.ignore(); // Ignore newline character
    cout << "Number of vertices: " << n << endl;
    cout << "Number of edges: " << e << endl;

    int** graph = new int*[e];
    for (int i = 0; i < e; i++) {
        graph[i] = new int[3];
        int source, sink, weight;
        infile >> source >> sink >> weight;
        cout << "Edge " << i + 1 << ": Source=" << source << ", Sink=" << sink << ", Weight=" << weight << endl;

        graph[i][0] = source;
        graph[i][1] = sink;
        graph[i][2] = weight;
    }

    int sourceVertex;
    infile >> sourceVertex;
    cout << "Source vertex: " << sourceVertex << endl;

    infile.close();

    long long* dist = new long long[n];
    BellmanFord(graph, n, e, sourceVertex, dist);

    if (dist[0] == -1) {
        cout << "Error: Source vertex is invalid or negative cycle detected." << endl;
    } else {
        cout << "Shortest distances from source vertex:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i << ": ";
            if (dist[i] == INF) {
                cout << "INF" << endl;
            } else {
                cout << dist[i] << endl;
            }
        }
    }

    // Free memory
    for (int i = 0; i < e; i++) {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] dist;

    return 0;
}
