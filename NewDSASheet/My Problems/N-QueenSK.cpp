#include <iostream>

using namespace std;

void print_board(char **b, int n)
{
    static int sol = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << b[i][j] << "  ";
        }
        cout << endl;
    }
    sol++;
    cout << "NUMBER OF SOLUTION " << sol << endl
        << endl;
}

void solve(int col, char **b, int n, int *lr, int *ud, int *ld)
{
    if (col == n)
    {
        print_board(b, n);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (lr[row] == 0 && ud[(n - 1) + (col - row)] == 0 && ld[(col + row)] == 0)
        {
            b[row][col] = 'Q';
            lr[row] = 1;
            ud[(n - 1) + (col - row)] = 1;
            ld[(col + row)] = 1;

            solve(col + 1, b, n, lr, ud, ld);

            b[row][col] = '.';
            lr[row] = 0;
            ud[(n - 1) + (col - row)] = 0;
            ld[(col + row)] = 0;
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    // Dynamic allocation of arrays
    char **b = new char *[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = new char[n];
    }

    int *lr = new int[n]();
    int *ud = new int[2 * n - 1]();
    int *ld = new int[2 * n - 1]();

    // Initialize the board
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = '.';
        }
    }

    // Solve the N-Queens problem
    solve(0, b, n, lr, ud, ld);

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++)
    {
        delete[] b[i];
    }
    delete[] b;
    delete[] lr;
    delete[] ud;
    delete[] ld;

    return 0;
}
