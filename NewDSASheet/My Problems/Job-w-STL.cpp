#include <iostream>

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

// Function to sort jobs array according to decreasing order of profit
void sortJobs(Job* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!cmp(arr[i], arr[j])) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

// Function to schedule jobs to maximize profit
void jobScheduling(Job* arr, int n) {
    // Sort all jobs according to decreasing order of profit
    sortJobs(arr, n);

    // To keep track of free time slots
    int* result = new int[n];  // To store result (sequence of jobs)
    bool* slot = new bool[n]();  // To keep track of free time slots

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (Note that we start from the last possible slot)
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            // Free slot found
            if (!slot[j]) {
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

    // Free dynamically allocated memory
    delete[] result;
    delete[] slot;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    // Allocate memory for jobs array
    Job* arr = new Job[n];

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

    // Free dynamically allocated memory
    delete[] arr;

    return 0;
}
