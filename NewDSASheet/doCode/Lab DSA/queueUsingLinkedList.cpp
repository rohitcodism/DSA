// implementation of queue using linked list


#include <iostream>
using namespace std;

// node
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

// class to represent a queue using a linked list
class Queue
{
private:
    Node *front;
    Node *rear;
public:
    Queue()
    {
        front = rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!!!" << endl;
            return;
        }
        cout << "Queue : ";
        Node *current = front;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void enQueue(int x)
    {
        Node *newNode = new Node(x);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        display();
    }

    int deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!!!" << endl;
            return -1;
        }
        Node *temp = front;
        front = front->next;
        int x = temp->data;
        delete temp;
        display();
        return x;
    }
};

//menu
int main()
{
    Queue q;
    int choice, x;
    do{
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to be enqueued : ";
            cin >> x;
            q.enQueue(x);
            break;
        case 2:
            q.deQueue();
            break;
        case 3:
            q.display();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice!!!" << endl;
        }
    }while(choice != 0);
    return 0;
}