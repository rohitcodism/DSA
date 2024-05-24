#include <iostream>
#include <limits.h>

using namespace std;

// Function to perform matrix chain multiplication using recursion
int matrixChainOrder(int p[], int i, int j, int m[][100], int s[][100]) {
    if (i == j) {
        return 0;
    }

    if (m[i][j] != -1) {
        return m[i][j];
    }

    m[i][j] = INT_MAX;

    for (int k = i; k < j; k++) {
        int q = matrixChainOrder(p, i, k, m, s) + matrixChainOrder(p, k + 1, j, m, s) + p[i - 1] * p[k] * p[j];
        if (q < m[i][j]) {
            m[i][j] = q;
            s[i][j] = k;
        }
    }

    return m[i][j];
}

// Function to print the optimal parenthesis placement
void printOptimalParenthesis(int s[][100], int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        cout << ")";
    }
}

// Function to print the m and s tables
void printTables(int m[][100], int s[][100], int n) {
    cout << "m table:" << endl;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j >= i) {
                cout << m[i][j] << "\t";
            } else {
                cout << "-\t";
            }
        }
        cout << endl;
    }
    cout << "s table:" << endl;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j > i) {
                cout << s[i][j] << "\t";
            } else {
                cout << "-\t";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int p[n + 1];
    cout << "Enter the dimensions: ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    int m[100][100];
    int s[100][100];

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            m[i][j] = -1;
        }
    }

    matrixChainOrder(p, 1, n, m, s);

    cout << "Minimum number of multiplications is: " << m[1][n] << endl;

    printTables(m, s, n + 1);

    cout << "Optimal Parenthesis Placement: ";
    printOptimalParenthesis(s, 1, n);
    cout << endl;

    return 0;
}
