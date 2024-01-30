#include <iostream>
using namespace std;

struct cQueue
{
    int front;
    int rear;
    int size;
    int *Q;
};

bool isFull(cQueue *q)
{
    return q->front == (q->rear + 1) % q->size;
}

bool isEmpty(cQueue *q)
{
    return q->front == q->rear;
}

void display(cQueue *q) {
    if (isEmpty(q)) {
        cout << "Cannot display empty queue!!!" << endl;
        return;
    }
    cout << "The queue is : ";
    int i = q->front + 1;
    do {
        cout << q->Q[i] << " ";
        i = (i + 1) % q->size;
    } while (i != (q->rear + 1) % q->size);
    cout << endl;
}

void enQueue(cQueue *q, int key)
{
    if (isFull(q))
    {
        cout << "Cannot perform enqueue as your queue is full!!!" << endl;
        return;
    }

    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = key;

    display(q);
}

int deQueue(cQueue *q)
{
    if (isEmpty(q))
    {
        cout << "Cannot perform dequeue as your queue is empty!!!" << endl;
    }

    q->front = (q->front + 1) % q->size;
    int x = q->Q[q->front];

    display(q);
    return x;
}

int main()
{
    cQueue q;
    q.front = q.rear = 0; // Initial front and rear are set to 0

    int choice, key;
    cout << "Enter size of queue: ";
    cin >> q.size;
    q.Q = new int[q.size]; // Dynamically allocating memory
    cout << "Your queue is created successfully!!!" << endl;

    do
    {
        cout << "----Circular Queue----" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1:
                cout << "Enter the element you want to enqueue: ";
                cin >> key;
                enQueue(&q, key);
                break;
            case 2:
                deQueue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 0:
                cout << "Thank you for using our program!!!" << endl;
                break;
            default:
                cout << "Invalid choice!!!" << endl;
                break;
        }
    } while (choice);

    delete[] q.Q; // Freeing dynamically allocated memory
    return 0;
}