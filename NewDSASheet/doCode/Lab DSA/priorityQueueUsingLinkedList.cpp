// implementation of priority queue using linked list

#include <iostream>
using namespace std;

// node
struct Node
{
    int data;
    int priority;
    Node *next;
    Node(int d, int p)
    {
        data = d;
        priority = p;
        next = nullptr;
    }
};

// class to represent a priority queue using a linked list
class PriorityQueue
{
private:
    Node *front;
    Node *rear;
public:
    PriorityQueue()
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
            cout << "Priority Queue is empty!!!" << endl;
            return;
        }
        cout << "Priority Queue : ";
        Node *current = front;
        while (current != nullptr)
        {
            cout << current->data << "(" << current->priority << ") ";
            current = current->next;
        }
        cout << endl;
    }

    void enQueue(int x, int p)
    {
        Node *newNode = new Node(x, p);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            if (p > front->priority)
            {
                newNode->next = front;
                front = newNode;
            }
            else if (p < rear->priority)
            {
                rear->next = newNode;
                rear = newNode;
            }
            else
            {
                Node *current = front;
                while (current->next != nullptr && current->next->priority >= p)
                {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }

    void deQueue()
    {
        if (isEmpty())
        {
            cout << "Priority Queue is empty!!!" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
    }
};


// menu driven program
int main()
{
    PriorityQueue pq;
    int choice, x, p;
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
            cout << "Enter the element to be enqueued : ";
            cin >> x;
            cout << "Enter the priority of the element : ";
            cin >> p;
            pq.enQueue(x, p);
            break;
        case 2:
            pq.deQueue();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice!!!" << endl;
        }
    }
    return 0;
}