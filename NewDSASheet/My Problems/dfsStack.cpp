#include <iostream>
#include <fstream>

using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

void dfsUsingStack(int** adjMatrix, int* visited, int n, int start) {
    Stack stack(n);
    stack.push(start);

    while (!stack.isEmpty()) {
        int node = stack.pop();

        if (!visited[node]) {
            cout << node << " ";
            visited[node] = 1;

            // Push adjacent vertices in reverse order to visit them in the correct order
            for (int i = n - 1; i >= 0; i--) {
                if (adjMatrix[node][i] && !visited[i]) {
                    stack.push(i);
                }
            }
        }
    }
}

int main() {
    ifstream inputFile("DFS.txt");
    if (!inputFile) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    // Dynamic allocation of adjacency matrix and visited array
    int** adjMatrix = new int*[n];
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = new int[n];
    }
    int* visited = new int[n]();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inputFile >> adjMatrix[i][j];
        }
    }

    int startNode;
    inputFile >> startNode;

    inputFile.close();

    cout << "DFS traversal: ";
    dfsUsingStack(adjMatrix, visited, n, startNode);
    cout << endl;

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    delete[] visited;

    return 0;
}
