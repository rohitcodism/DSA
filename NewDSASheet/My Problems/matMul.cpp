#include<bits/stdc++.h>

using namespace std;

// Function to perform matrix chain multiplication
int matrixChainOrder(vector<int> &p, int n) {
    // dp[i][j] represents the minimum number of multiplications needed
    // to compute the matrix chain from i to j
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // cost is zero when multiplying one matrix
    for (int length = 2; length < n; length++) {
        for (int i = 1; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                // q = cost/scalar multiplications
                int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);
    cout << "Enter the dimensions: ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    cout << "Minimum number of multiplications is: " << matrixChainOrder(p, n + 1) << endl;

    return 0;
}
