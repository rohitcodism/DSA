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
        return x;
    }
}

int main()
{

    struct Queue q1;

    cout << "Enter the size of the queue: ";
    cin >> q1.size;
    cout << endl;

    q1.Q = new int[q1.size]; // TODO: To create a dynamic array we need to create it like this
    q1.front = q1.rear = -1;

    enQueue(&q1,5);
    enQueue(&q1,4);
    enQueue(&q1,3);
    enQueue(&q1,2);
    enQueue(&q1,1);
    enQueue(&q1,0);

    deQueue(&q1);
    deQueue(&q1);
    deQueue(&q1);
    deQueue(&q1);
    deQueue(&q1);
    deQueue(&q1);

    return 0;
}