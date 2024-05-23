#include<bits/stdc++.h>
using namespace std;

// Structure to hold the minimum and maximum values
struct MinMax {
    int min;
    int max;
};

// Function to find the minimum and maximum of an array using divide and conquer
MinMax findMinMax(int arr[], int low, int high) {
    MinMax minmax, left, right;
    int mid;

    // If there is only one element
    if (low == high) {
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
    }

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    // If there are more than two elements
    mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    // Compare minimums of two parts
    if (left.min < right.min) {
        minmax.min = left.min;
    } else {
        minmax.min = right.min;
    }

    // Compare maximums of two parts
    if (left.max > right.max) {
        minmax.max = left.max;
    } else {
        minmax.max = right.max;
    }

    return minmax;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    MinMax result = findMinMax(arr, 0, n - 1);

    cout << "Minimum element in the array: " << result.min << endl;
    cout << "Maximum element in the array: " << result.max << endl;

    return 0;
}
