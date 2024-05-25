#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        front = (front + 1) % capacity;
        size--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }

        return arr[front];
    }
};

// Function to perform BFS
void BFS(int node, int** adj, int V, int* visited) {
    Queue q(V);
    q.enqueue(node);
    visited[node] = 1;

    while (!q.isEmpty()) {
        int u = q.getFront();
        q.dequeue();
        cout << u << " ";

        for (int v = 0; v < V; v++) {
            if (adj[u][v] && !visited[v]) {
                q.enqueue(v);
                visited[v] = 1;
            }
        }
    }
}

int main() {
    int V;

    ifstream infile("BFS2.txt");
    if (!infile) {
        cout << "Error: Unable to open input file." << endl;
        return 1;
    }

    infile >> V;

    // Dynamic allocation of adjacency matrix and visited array
    int** adj = new int*[V];
    for (int i = 0; i < V; i++) {
        adj[i] = new int[V];
    }
    int* visited = new int[V]();

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            infile >> adj[i][j];
        }
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    int S;
    infile >> S;

    infile.close();

    cout << "BFS traversal: ";
    BFS(S, adj, V, visited);
    cout << endl;

    // Free dynamically allocated memory
    for (int i = 0; i < V; i++) {
        delete[] adj[i];
    }
    delete[] adj;
    delete[] visited;

    return 0;
}
