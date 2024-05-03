#include <iostream>

using namespace std;

bool isSafe(int row, int col, int* cols, int* diag1, int* diag2, int N) {
    return !cols[col] && !diag1[col + row] && !diag2[col - row + N - 1];
}

void printSolution(int** board, int N) {
    static int count = 1;
    cout << "Solution " << count++ << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueen(int** board, int col, int* cols, int* diag1, int* diag2, int N, int& solutionCount) {
    if (col == N) {
        printSolution(board, N);
        solutionCount++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col, cols, diag1, diag2, N)) {
            board[i][col] = 1;
            cols[col] = 1;
            diag1[col + i] = 1;
            diag2[col - i + N - 1] = 1;

            solveNQueen(board, col + 1, cols, diag1, diag2, N, solutionCount);

            // Backtrack
            board[i][col] = 0;
            cols[col] = 0;
            diag1[col + i] = 0;
            diag2[col - i + N - 1] = 0;
        }
    }
}

int main() {
    int N;
    cout << "Enter the size of the board: ";
    cin >> N;

    int** board = new int*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N]();
    }

    int* cols = new int[N]();
    int* diag1 = new int[2 * N - 1]();
    int* diag2 = new int[2 * N - 1]();

    int solutionCount = 0;

    solveNQueen(board, 0, cols, diag1, diag2, N, solutionCount);

    if (solutionCount == 0) {
        cout << "No solution exists for N = " << N << endl;
    } else {
        cout << "Total solutions found: " << solutionCount << endl;
    }

    // Clean up memory
    for (int i = 0; i < N; i++) {
        delete[] board[i];
    }
    delete[] board;
    delete[] cols;
    delete[] diag1;
    delete[] diag2;

    return 0;
}
