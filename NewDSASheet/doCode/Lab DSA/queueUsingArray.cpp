// implement queue using array

#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int capacity;
    int size;
    int front;
    int rear;
    public:
    Queue(int capacity)
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
        arr[front] = 0;
        front = (front + 1) % capacity;
        size--;
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
};

// menu driven program
int main()
{
    int capacity;
    cout << "Enter the capacity of the queue : ";
    cin >> capacity;
    Queue q(capacity);
    int choice, element;
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
            cout << "Enter the element to enqueue : ";
            cin >> element;
            q.enqueue(element);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice!!!" << endl;
        }
    }
    return 0;
}