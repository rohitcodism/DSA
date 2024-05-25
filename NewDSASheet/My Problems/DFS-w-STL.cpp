#include <iostream>
#include <fstream>

using namespace std;

void dfs(int** adjMatrix, int* visited, int n, int start) {
    cout << start << " ";
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (adjMatrix[start][i] && !visited[i]) {
            dfs(adjMatrix, visited, n, i);
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
    dfs(adjMatrix, visited, n, startNode);
    cout << endl;

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    delete[] visited;

    return 0;
}
