#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
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
    void enQueue(int val)
    {
        Node *temp = new Node(val);

        if (!temp)
        {
            cout << "Cannot enqueue as your queue is full!!!" << endl;
            return;
        }
        else
        {
            if (!front)
                front = rear = temp;
            else
            {
                this->rear->next = temp;
                rear = temp;
            }
        }
        Display();
    }
    int deQueue()
    {
        if (isEmpty())
        {
            cout << "Cannot perform dequeue as your queue is empty" << endl;
            return -1;
        }
        else
        {
            Node *temp = this->front;
            this->front = this->front->next;
            int x = temp->data;
            delete temp;
            Display();
            return x;
        }
    }

    int peek(){
        if(isEmpty()){
            cout<<"Cannot perform peek as it is an empty queue!!!"<<endl;
            return -1;
        }
        return this->front->data;

    }
};

int main() {
    Queue q;

    int choice, element;
    do {
        cout << "\n------ Menu ------" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout<< "4. Peek" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> element;
                q.enQueue(element);
                break;
            case 2:
                cout << "Dequeued value: " << q.deQueue() << endl;
                break;
            case 3:
                q.Display();
                break;
            case 4:
                cout<<"Peek  Element: "<<q.peek()<<endl;
                break;
            case 0:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 0);

    return 0;
}