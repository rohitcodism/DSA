#include <iostream>

using namespace std;

int main() {
    int n, stages;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of stages: ";
    cin >> stages;

    // Create the cost matrix and initialize it with 0
    int** graph = new int*[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input for graph
    cout << "Enter the graph as adjacency matrix (Enter large number for no path):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Arrays for costs and path
    int* cost = new int[n];
    int* d = new int[n];  // Decision array
    int* path = new int[stages];

    // Initialize cost of sink
    cost[n-1] = 0;

    // Dynamic programming to find the shortest path
    for (int i = n - 2; i >= 0; i--) {
        int min = 32767;
        for (int k = i + 1; k < n; k++) {
            if (graph[i][k] && graph[i][k] + cost[k] < min) {
                min = graph[i][k] + cost[k];
                d[i] = k;
            }
        }
        cost[i] = min;
    }

    // Construct the shortest path
    path[0] = 0;  // Starting from the first vertex
    path[stages - 1] = n - 1;  // Ending at the last vertex
    for (int i = 1; i < stages - 1; i++) {
        path[i] = d[path[i - 1]];
    }

    // Output the results
    cout << "Cost of shortest path: " << cost[0] << endl;
    cout << "Path: ";
    for (int i = 0; i < stages; i++) {
        cout << path[i] + 1 << " ";
    }
    cout << endl;

    // Deallocate memory
    for (int i = 0; i < n; i++) {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] cost;
    delete[] d;
    delete[] path;

    return 0;
}
