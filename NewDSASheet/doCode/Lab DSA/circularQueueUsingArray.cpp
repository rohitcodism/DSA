// implementation of circular queue using array

#include <iostream>
using namespace std;


class CircularQueue
{
private:
    int *arr;
    int capacity;
    int size;
    int front;
    int rear;
public:
    CircularQueue(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
        this->front = 0;
        this->rear = -1;
        // Initialize array with zeros
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!!!" << endl;
            return;
        }
        cout << "Queue : ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue Overflow!!!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!!!" << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }
};


// menu driven program to test circular queue
int main()
{
    int capacity;
    cout << "Enter the capacity of the circular queue : ";
    cin >> capacity;

    CircularQueue cq(capacity);

    int choice, data;
    while (1)
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to enqueue : ";
            cin >> data;
            cq.enqueue(data);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}