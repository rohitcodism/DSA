#include <iostream>

using namespace std;

const int INF = 1e9;

void PrintOptimalParens(int i, int j, int** s) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        PrintOptimalParens(i, s[i][j], s);
        PrintOptimalParens(s[i][j] + 1, j, s);
        cout << ")";
    }
}

void PrintTables(int** m, int** s, int n) {
    cout << "Cost Table (m):" << endl;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i <= j) {
                cout << m[i][j] << "\t";
            } else {
                cout << "-\t";
            }
        }
        cout << endl;
    }

    cout << "Split Table (s):" << endl;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i < j) {
                cout << s[i][j] << "\t";
            } else {
                cout << "-\t";
            }
        }
        cout << endl;
    }
}

int MatrixChainOrder(int p[], int n, int** m, int** s) {

    int min,j,q;

    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for(int d = 1; d<n-1;d++){
        for(int i = 1; i<n-d;d++){
            int j = i+d;
            min=32767;
            for(int k = i; k<j-1;k++){
                q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
                if(q<min){
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }

    return m[1][n-1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int p[n + 1];
    cout << "Enter dimensions of matrices (e.g., for matrices 40x20, 20x30, 30x10 enter 40, 20, 30, 10): ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    int** m = new int*[n+1]; 
    int** s = new int*[n+1]; 

    for (int i = 0; i <= n; i++) {
        m[i] = new int[n+1];
        s[i] = new int[n+1];
    }

    int minCost = MatrixChainOrder(p, n + 1, m, s);
    cout << "Minimum number of multiplications is " << minCost << endl;
    
    PrintTables(m, s, n + 1);
    
    cout << "Optimal Parenthesization: ";
    PrintOptimalParens(1, n, s);
    cout << endl;

    for (int i = 0; i <= n; i++) {
        delete[] m[i];
        delete[] s[i];
    }
    delete[] m;
    delete[] s;

    return 0;
}
