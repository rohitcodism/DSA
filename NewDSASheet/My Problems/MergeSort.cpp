#include <iostream>
#include <vector>
using namespace std;

// Function to print the current state of the array
void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// Function to merge two halves into a sorted array
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of the left half
    int n2 = right - mid;     // Size of the right half

    // Temporary arrays to hold the left and right halves
    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Initial indexes of the left and right halves
    int i = 0, j = 0;

    // Initial index of the merged subarray
    int k = left;

    // Merge the temporary arrays back into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        cout << "Before sorting: ";
        printArray(arr);

        int mid = left + (right - left) / 2;  // Find the middle point

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);

        cout << "After sorting from " << left << " to " << right << ": ";
        printArray(arr);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Initial array: ";
    printArray(arr);

    // Call the mergeSort function
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
