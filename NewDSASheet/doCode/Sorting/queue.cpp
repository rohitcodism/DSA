#include <iostream>
using namespace std;

/**
 * The above code defines a struct called Queue that represents a queue data structure.
 * @property {int} size - The size of the queue, which represents the maximum number of elements that
 * the queue can hold.
 * @property {int} front - The front variable is used to keep track of the index of the front element
 * in the queue. It represents the position of the first element in the queue.
 * @property {int} rear - The rear property represents the index of the last element in the queue. It
 * is used to keep track of where the next element will be inserted in the queue.
 * @property {int} Q - The variable "Q" is a pointer to an integer. It is used to dynamically allocate
 * memory for the queue array.
 */

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q; // TODO: To create a dynamic array we need to create it like this
};

bool isFull(Queue *q)
{
    return q->rear == q->size - 1;
}

bool isEmpty(Queue *q)
{
    return q->front == q->rear == -1;
}

void display(Queue *q)
{
    if(isEmpty(q)){
        cout<<"Cannot display empty queue!!!"<<endl;
        return;
    }
    cout<<"The queue is : ";
    for (int i = q->front; i <= q->rear; i++)
    {
        cout << q->Q[i] << " ";
    }
    cout << endl;
}

void enQueue(Queue *q, int key)
{
    if(!isFull(q)){
        q->front = 0;
        q->rear++;

        q->Q[q->rear] = key;
        display(q);
    }
    else{
        cout<<"Your queue is full!!!"<<endl;
    }
}

int deQueue(Queue *q){
    if(isEmpty(q)){
        cout<<"Your queue is empty!!!"<<endl;
    }
    else{
        int x = q->Q[q->front++];
        display(q);

        //** if the queue is empty after dequeueing the element then reset the front and rear
        if(q->front == q->rear){
            q->front = q->rear = -1;
        }
        return x;
    }
}

int main() {
    Queue q1;
    q1.front = q1.rear = -1;

    int choice, element;
    cout << "Enter the size of the queue: ";
    cin >> q1.size;
    q1.Q = new int[q1.size];

    do {
        cout << "\n------ Menu ------" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> element;
                enQueue(&q1, element);
                break;
            case 2:
                deQueue(&q1);
                break;
            case 3:
                display(&q1);
                break;
            case 0:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice);

    delete[] q1.Q; // Freeing dynamically allocated memory
    return 0;
}