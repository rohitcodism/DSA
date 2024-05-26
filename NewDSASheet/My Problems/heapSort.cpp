#include <iostream>
using namespace std;

// Function to swap two integers
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to heapify a subtree rooted with node i which is an index in arr[]
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function to do heap sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    cout << "Building the heap:\n";
    for (int i = n / 2 - 1; i >= 0; i--) {
        cout << "Heapifying at index " << i << ":\n";
        heapify(arr, n, i);
        printArray(arr, n);
    }

    // One by one extract an element from heap
    cout << "\nExtracting elements from heap and sorting:\n";
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        cout << "Swapping root with element at index " << i << ":\n";
        swap(arr[0], arr[i]);
        printArray(arr, n);

        // Call max heapify on the reduced heap
        cout << "Heapifying root after swap:\n";
        heapify(arr, i, 0);
        printArray(arr, n);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n]; // Dynamic array

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array is \n";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "\nSorted array is \n";
    printArray(arr, n);

    delete[] arr; // Free the memory allocated for dynamic array

    return 0;
}
