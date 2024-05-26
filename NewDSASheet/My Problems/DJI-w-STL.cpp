#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

const int MAX_V = 100; // Maximum number of vertices

// Structure to represent an edge
struct Edge {
    int to;
    int weight;
    Edge* next;
};

// Structure to represent a node in the adjacency list
struct Node {
    Edge* head;
};

// Function to add an edge to the adjacency list
void addEdge(Node* adj[], int u, int v, int w) {
    Edge* newEdge = new Edge;
    newEdge->to = v;
    newEdge->weight = w;
    newEdge->next = adj[u]->head;
    adj[u]->head = newEdge;

    newEdge = new Edge;
    newEdge->to = u;
    newEdge->weight = w;
    newEdge->next = adj[v]->head;
    adj[v]->head = newEdge;
}

// Function to extract the minimum distance node from the priority queue
int extractMin(int dist[], bool visited[], int V) {
    int minIndex = -1, minValue = INT_MAX;
    for (int i = 0; i < V; ++i) {
        if (!visited[i] && dist[i] < minValue) {
            minValue = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to perform Dijkstra's algorithm
void Dijkstra(int V, Node* adj[], int source, int dist[]) {
    bool visited[MAX_V] = { false };

    for (int i = 0; i < V; ++i)
        dist[i] = INT_MAX;

    dist[source] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = extractMin(dist, visited, V);
        visited[u] = true;

        for (Edge* edge = adj[u]->head; edge != nullptr; edge = edge->next) {
            int v = edge->to;
            int weight = edge->weight;

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
}

int main() {
    ifstream infile("graph.txt");

    int V, E;
    infile >> V >> E;

    Node* adj[MAX_V];
    for (int i = 0; i < V; ++i) {
        adj[i] = new Node;
        adj[i]->head = nullptr;
    }

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        infile >> u >> v >> w;
        addEdge(adj, u, v, w);
    }

    int source;
    infile >> source;
    infile.close();

    int dist[MAX_V];
    Dijkstra(V, adj, source, dist);

    for (int i = 0; i < V; ++i) {
        cout << "Shortest distance from source to node " << i << ": " << dist[i] << endl;
    }

    cout << "Adjacency List:\n";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": ";
        for (Edge* edge = adj[i]->head; edge != nullptr; edge = edge->next) {
            cout << "(" << edge->to << ", " << edge->weight << ") ";
        }
        cout << endl;
    }

    return 0;
}
