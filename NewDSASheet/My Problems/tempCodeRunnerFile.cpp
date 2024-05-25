#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX; // Represent infinity

vector<long long> BellmanFord(vector<vector<int>> &graph, int n, int source) {
    vector<long long> dist(n, INF);

    dist[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto edge : graph) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative cycles
    for (auto edge : graph) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            // Negative cycle detected
            return { -1 };
        }
    }

    return dist;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << endl;

    vector<vector<int>> graph;

    for (int i = 0; i < n; i++) {
        int source, sink, weight;
        cout << "Enter the source for edge " << i + 1 << ": ";
        cin >> source;
        cout << "Enter the sink for edge " << i + 1 << ": ";
        cin >> sink;
        cout << "Enter the weight for edge " << i + 1 << ": ";
        cin >> weight;
        cout << endl;

        graph.push_back({ source, sink, weight });
    }

    int sourceVertex;
    cout << "Enter the source vertex: ";
    cin >> sourceVertex;
    cout << endl;

    vector<long long> dist = BellmanFord(graph, n, sourceVertex);

    if (dist[0] == -1) {
        cout << "Error: Source vertex is invalid." << endl;
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

    return 0;
}
