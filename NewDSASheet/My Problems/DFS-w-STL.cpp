
#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;

void dfs(int adjMatrix[MAX_SIZE][MAX_SIZE], int visited[MAX_SIZE], int n, int start) {
    std::cout << start << " ";
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (adjMatrix[start][i] && !visited[i]) {
            dfs(adjMatrix, visited, n, i);
        }
    }
}

int main() {
    std::ifstream inputFile("DFS.txt");
    if (!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    int n;
    inputFile >> n;

    int adjMatrix[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inputFile >> adjMatrix[i][j];
        }
    }

    inputFile.close();

    int visited[MAX_SIZE] = {0};
    int startNode;
    std::cout << "Enter the starting node: ";
    std::cin >> startNode;

    std::cout << "DFS traversal: ";
    dfs(adjMatrix, visited, n, startNode);
    std::cout << std::endl;

    return 0;
}