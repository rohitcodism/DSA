#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* heap;
    int capacity;
    int size;

    // Helper function to swap elements at indices i and j
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Helper function to heapify up (used after insertion)
    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Helper function to heapify down (used after deletion)
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heap[leftChild] > heap[largest])
            largest = leftChild;
        if (rightChild < size && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Constructor to create a heap with given capacity
    MaxHeap(int cap) {
        capacity = cap;
        heap = new int[capacity];
        size = 0;
    }

    // Destructor to free dynamically allocated memory
    ~MaxHeap() {
        delete[] heap;
    }

    // Function to insert an element into the heap
    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full. Cannot insert more elements.\n";
            return;
        }
        heap[size++] = value;
        heapifyUp(size - 1);
    }

    // Function to display the elements of the heap
    void display() {
        cout << "Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity = 10;
    MaxHeap heap(capacity);

    cout << "Inserting elements into the heap:" << endl;
    heap.insert(1);
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);
    heap.insert(5);
    heap.display();

    return 0;
}
