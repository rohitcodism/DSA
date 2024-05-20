#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> board, int n)
{
    int dupRow = row;
    int dupCol = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col])
        {
            return false;
        }
        row--;
        col--;
    }

    col = dupCol;
    row = dupRow;

    while (col >= 0)
    {
        if (board[row][col])
        {
            return false;
        }
        col--;
    }

    col = dupCol;
    row = dupRow;

    while (row < n && col >= 0)
    {
        if (board[row][col])
        {
            return false;
        }
        col--;
        row++;
    }

    return true;
}

void solve(int col, vector<string> board, vector<vector<string>> ans, int n)
{
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int i = 0;i<n;i++){
        if(isSafe(i, col, board, n)){
            board[i][col] = 'Q';
            solve(col,board,ans,n);
            board[i][col] = '.';
        }
    }
}

vector<vector<string>> solveQueen(int n){
    vector<vector<string>> ans;
    vector<string> board(n);

    string s(n, '.');

    for(int i = 0;i<n;i++){
        board[i] = s;
    }

    solve(0, board, ans, n);
}

int main() {
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;

    vector<vector<string>> solutions = solveQueen(n);

    if (solutions.empty()) {
        cout << "No solution exists for N = " << n << endl;
    } else {
        cout << "Total solutions found: " << solutions.size() << endl;
        for (const auto& solution : solutions) {
            for (const auto& row : solution) {
                cout << row << endl;
            }
            cout << endl;
        }
    }

    return 0;
}