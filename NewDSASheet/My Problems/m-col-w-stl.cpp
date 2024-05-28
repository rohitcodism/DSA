#include <iostream>
#include <fstream>

using namespace std;

bool canColor(int** Graph, int node, int* Color, int N, int color) {
    for (int k = 0; k < N; k++) {
        if (k != node && Graph[k][node] == 1 && Color[k] == color) {
            return false;
        }
    }
    return true;
}

bool ColorIt(int node, int** Graph, int M, int N, int* Color) {
    if (node == N) {
        return true;
    }
    for (int i = 0; i < M; i++) {
        if (canColor(Graph, node, Color, N, i)) {
            Color[node] = i;
            if (ColorIt(node + 1, Graph, M, N, Color)) {
                return true;
            }
            Color[node] = 0;
        }
    }
    return false;
}

int main() {
    ifstream inFile("m-col.txt");
    if (!inFile) {
        cerr << "Unable to open file input.txt";
        return 1;
    }

    int M, N;
    inFile >> N >> M;

    int* Colors = new int[N];
    for (int i = 0; i < N; i++) {
        Colors[i] = 0;
    }

    int** Graph = new int*[N];
    for (int i = 0; i < N; i++) {
        Graph[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inFile >> Graph[i][j];
        }
    }

    inFile.close();

    if (ColorIt(0, Graph, M, N, Colors)) {
        cout << "Graph can be colored using " << M << " colors." << endl;
        cout << "Coloring sequence: ";
        for (int i = 0; i < N; i++) {
            cout << Colors[i] << " ";
        }
    } else {
        cout << "Graph cannot be colored using " << M << " colors." << endl;
    }

    for (int i = 0; i < N; i++) {
        delete[] Graph[i];
    }
    delete[] Graph;
    delete[] Colors;

    return 0;
}
