/*
    Write a program in C or C++ to sort a given array using Merge sort algorithm.
*/

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    // Calculate the sizes of the two sub-arrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays to store the elements of the sub-arrays
    int L[n1], R[n2];

    // Copy the elements from the original array to the temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the two sub-arrays back into the original array in sorted order
    int i = 0, j = 0, k = left;
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

    // Copy the remaining elements of the left sub-array, if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of the right sub-array, if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point to divide the array into two halves
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, size);
    
    return 0;
}