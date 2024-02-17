#include <iostream>

// Node class to represent each element in the queue
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Queue class to manage the linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to enqueue an element
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        std::cout << value << " enqueued to the queue." << std::endl;
    }

    // Function to dequeue an element
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return -1;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        std::cout << temp->data << " dequeued from the queue." << std::endl;
        int x = temp->data;
        delete temp;
        return x;
    }

    // Function to get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }

        return front->data;
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        Node* temp = front;
        std::cout << "Elements in the queue: ";

        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }

        std::cout << std::endl;
    }
};
