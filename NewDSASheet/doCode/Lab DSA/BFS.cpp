#include <iostream>
#include <queue>
using namespace std;

class Graph {
    int V;              // Number of vertices
    int** adj;          // Adjacency matrix

public:
    Graph(int V) {
        this->V = V;
        // Allocate memory for adjacency matrix
        adj = new int*[V];
        for (int i = 0; i < V; ++i) {
            adj[i] = new int[V];
            // Initialize all elements to 0 (no edge)
            for (int j = 0; j < V; ++j)
                adj[i][j] = 0;
        }
    }

    void addEdge(int v, int w) {
        // Add edges in both directions (undirected graph)
        adj[v][w] = 1;
        adj[w][v] = 1;
    }

    void printGraph() {
        cout << "Graph Representation (Adjacency Matrix):" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": ";
            for (int j = 0; j < V; ++j) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void BFS(int s) {
        // Mark all the vertices as not visited
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Create a queue for BFS
        queue<int> queue;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push(s);

        cout << "Breadth First Traversal: ";
        while (!queue.empty()) {
            // Dequeue a vertex from queue and print it
            s = queue.front();
            cout << s << " ";
            queue.pop();

            // Get all adjacent vertices of the dequeued vertex s. If an adjacent has not been visited, then mark it visited and enqueue it
            for (int i = 0; i < V; ++i) {
                if (adj[s][i] && !visited[i]) {
                    visited[i] = true;
                    queue.push(i);
                }
            }
        }
        cout << endl;

        delete[] visited;
    }

    // Destructor to deallocate memory
    ~Graph() {
        for (int i = 0; i < V; ++i)
            delete[] adj[i];
        delete[] adj;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.printGraph();

    g.BFS(2);

    return 0;
}
