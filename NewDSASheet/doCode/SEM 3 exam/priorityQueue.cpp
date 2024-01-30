// implementation of priority queue using linked list

#include <iostream>
using namespace std;


struct Node
{
    int data;
    int priority;
    Node *next;
    Node(int data, int priority)
    {
        this->data = data;
        this->priority = priority;
        this->next = nullptr;
    }
};

class PriorityQueue
{
private:
    Node *front;
    Node *rear;
public:
    PriorityQueue()
    {
        this->front = nullptr;
        this->rear = nullptr;
    }

    bool isEmpty()
    {
        return this->front == nullptr;
    }

    void Display()
    {
        if (isEmpty())
        {
            cout << "Cannot display an empty Linked list" << endl;
            return;
        }
        Node *temp = this->front;
        cout<<"Queue is: ";
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }

    /**
     * The enQueue function adds a new node with a given value to the rear of the queue.
     *
     * @param val The value to be enqueued into the queue.
     *
     * @return The function does not have a return type.
     */
    void enQueue(int val, int priority){
        Node *temp = new Node(val, priority);

        if (!temp)
        {
            cout << "Heap Overflow" << endl;
            return;
        }
        if(isEmpty()){
            this->front = temp;
            this->rear = temp;
            return;
        }
        if(priority < this->front->priority){
            temp->next = this->front;
            this->front = temp;
            return;
        }
        if(priority > this->rear->priority){
            this->rear->next = temp;
            this->rear = temp;
            return;
        }
        Node *curr = this->front;
        while(curr->next != nullptr && curr->next->priority < priority){
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }

    /**
     * The deQueue function removes the node at the front of the queue.
     *
     * @param None
     *
     * @return The function returns the value of the node that was removed.
     */
    int deQueue(){
        if(isEmpty()){
            cout << "Queue Underflow" << endl;
            return -1;
        }
        Node *temp = this->front;
        int val = temp->data;
        this->front = this->front->next;
        delete temp;
        return val;
    }
};

int main(){
    int choice, element, priority;

    PriorityQueue q;

    do
    {
        cout << "Enter your choice: " << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element to be enqueued: ";
            cin >> element;
            cout << "Enter the priority of the element: ";
            cin >> priority;
            q.enQueue(element, priority);
            break;
        case 2:
            cout << "The dequeued element is: " << q.deQueue() << endl;
            break;
        case 3:
            q.Display();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice);
}