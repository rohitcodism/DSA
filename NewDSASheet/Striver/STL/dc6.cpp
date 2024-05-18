#include <bits/stdc++.h>
using namespace std;

long long maximumHappinessSum(vector<int> &happiness, int k)
{
    long long maxHappiness = 0;

    sort(happiness.begin(), happiness.end());

    int i = happiness.size() - 1;

    for (int j = 0; j < k; j++)
    {

        maxHappiness += happiness[i--];
        for (int l = 0; l < happiness.size(); l++)
        {
            if (happiness[l] > 0)
            {
                cout<<"Before decrement: "<<happiness[l]<<endl;
                happiness[l]--;
                cout<<"After decrement: "<<happiness[l]<<endl;
            }
        }
    }
    return maxHappiness;
}

long long maximizeHappinessSum(vector<int>& happiness, int k) {
    int n = happiness.size();
    sort(happiness.begin(), happiness.end(), greater<int>()); // Sort in descending order

    long long maxHappiness = 0;
    priority_queue<int> decrementedValues; // Max heap to store decremented values

    // Calculate the sum of the top k elements and add decremented values to the heap
    for (int i = 0; i < n; i++) {
        if (i < k) {
            maxHappiness += happiness[i];
        } else {
            decrementedValues.push(max(0, happiness[i] - 1));
        }
    }

    // Subtract the sum of top k decremented values from maxHappiness
    for (int i = 0; i < k; i++) {
        maxHappiness -= decrementedValues.top();
        decrementedValues.pop();
    }

    return maxHappiness;
}

int main() {
    int n, k;

    // Input the number of friends (n) and the parameter k
    cout << "Enter the number of friends (n): ";
    cin >> n;

    cout << "Enter the value of k: ";
    cin >> k;

    vector<int> happiness(n);

    // Input the happiness values for each friend
    cout << "Enter the happiness values (space-separated): ";
    for (int i = 0; i < n; i++) {
        cin >> happiness[i];
    }

    // Call the maximumHappinessSum function
    long long maxSum = maximizeHappinessSum(happiness, k);

    // Print the maximum happiness sum
    cout << "The maximum happiness sum is: " << maxSum << endl;

    return 0;
}