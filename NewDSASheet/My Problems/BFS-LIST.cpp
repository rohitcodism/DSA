#include <iostream>
#include <fstream>

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

// Function to perform BFS traversal
void BFS(int start, int** adjList, int* adjListSize, int V, int* visited) {
    Queue q(V);
    q.enqueue(start);
    visited[start] = 1;

    while (!q.isEmpty()) {
        int u = q.getFront();
        q.dequeue();
        cout << u << " ";

        for (int i = 0; i < adjListSize[u]; ++i) {
            int v = adjList[u][i];
            if (!visited[v]) {
                q.enqueue(v);
                visited[v] = 1;
            }
        }
    }
}

int main() {
    int V, E, isDirected;

    ifstream infile("bfsList.txt");
    if (!infile) {
        cout << "Error: Unable to open input file." << endl;
        return 1;
    }

    infile >> V >> E;
    infile >> isDirected;

    // Dynamic allocation of adjacency list and visited array
    int** adjList = new int*[V];
    int* adjListSize = new int[V]();
    int* visited = new int[V]();

    for (int i = 0; i < V; ++i) {
        adjList[i] = new int[V]; // Max V edges per vertex
        for (int j = 0; j < V; ++j) {
            adjList[i][j] = 0;
        }
    }

    int u, v;
    for (int i = 0; i < E; ++i) {
        infile >> u >> v;
        adjList[u][adjListSize[u]++] = v;
        if (!isDirected) {
            adjList[v][adjListSize[v]++] = u;
        }
    }

    infile.close();

    int S;
    cout << "Enter the starting vertex: ";
    cin >> S;

    cout << "BFS traversal starting from vertex " << S << ": ";
    BFS(S, adjList, adjListSize, V, visited);
    cout << endl;

    // Free dynamically allocated memory
    for (int i = 0; i < V; ++i) {
        delete[] adjList[i];
    }
    delete[] adjList;
    delete[] adjListSize;
    delete[] visited;

    return 0;
}
