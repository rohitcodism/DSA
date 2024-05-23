#include <bits/stdc++.h>

using namespace std;

// A structure to represent a job
struct Job {
    int id;      // Job Id
    int dead;    // Deadline of job
    int profit;  // Profit if job is completed before or on deadline
};

// Comparison function to sort jobs according to their profit in descending order
bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to schedule jobs to maximize profit
void jobScheduling(Job arr[], int n) {
    // Sort all jobs according to decreasing order of profit
    sort(arr, arr + n, cmp);

    // To keep track of free time slots
    vector<int> result(n, -1);  // To store result (sequence of jobs)
    vector<bool> slot(n, false);  // To keep track of free time slots

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (Note that we start from the last possible slot)
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            // Free slot found
            if (slot[j] == false) {
                result[j] = i;  // Add this job to result
                slot[j] = true;  // Make this slot occupied
                break;
            }
        }
    }

    // Print the result
    cout << "Following is the sequence of jobs that maximizes the profit:" << endl;
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << "Job " << arr[result[i]].id << " ";
            totalProfit += arr[result[i]].profit;
        }
    }
    cout << endl;
    cout << "Total Profit: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job arr[n];
    cout << "Enter the job details (id, deadline, profit):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << " ID: ";
        cin >> arr[i].id;
        cout << "Deadline: ";
        cin >> arr[i].dead;
        cout << "Profit: ";
        cin >> arr[i].profit;
    }

    jobScheduling(arr, n);

    return 0;
}
