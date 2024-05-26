#include <iostream>
using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, int* wt, int* val, int n) {
    // Create a DP array to store the maximum value for each weight
    int* dp = new int[W+1]();

    // Iterate through all items
    for (int i = 0; i < n; i++) {
        // Traverse the dp array from right to left
        for (int w = W; w >= wt[i]; w--) {
            // Update dp[w] by considering the inclusion of item i
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }

    // The maximum value for weight W is stored in dp[W]
    return dp[W];
}

int main() {
    int n, W;
    
    // Read the number of items and the maximum weight capacity of the knapsack
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;
    
    int* wt = new int[n];
    int* val = new int[n];
    
    // Read the weights and values of the items
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    
    // Call the knapsack function and print the result
    int maxValue = knapsack(W, wt, val, n);
    cout << "The maximum value that can be obtained is: " << maxValue << endl;
    
    return 0;
}
