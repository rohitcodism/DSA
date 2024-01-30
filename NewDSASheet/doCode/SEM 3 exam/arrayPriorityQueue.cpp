// implementation of priority queue using array

#include <iostream>
using namespace std;


class PriorityQueue
{
private:
    int *arr;
    int size;
    int capacity;
public:
    PriorityQueue(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
    }

    bool isEmpty()
    {
        return this->size == 0;
    }

    bool isFull()
    {
        return this->size == this->capacity;
    }

    void Display()
    {
        if (isEmpty())
        {
            cout << "Cannot display an empty Linked list" << endl;
            return;
        }
        cout<<"Queue is: ";
        for (int i = 0; i < this->size; i++)
        {
            cout << this->arr[i] << "  ";
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
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        int i = this->size - 1;
        while (i >= 0 && this->arr[i] > val)
        {
            this->arr[i + 1] = this->arr[i];
            i--;
        }
        this->arr[i + 1] = val;
        this->size++;
    }

    /**
     * The deQueue function removes the node at the front of the queue.
     *
     * @return The function does not have a return type.
     */
    void deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = 0; i < this->size - 1; i++)
        {
            this->arr[i] = this->arr[i + 1];
        }
        this->size--;
    }

    /**
     * The peek function returns the value of the node at the front of the queue.
     *
     * @return The function returns the value of the node at the front of the queue.
     */
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return this->arr[0];
    }
};

int main(){
    int choice, val, capacity, size;

    cout << "Enter the capacity of the queue: ";
    cin >> capacity;
    cout<<endl;

    PriorityQueue q(capacity);
    
    do
    {
        cout << "Enter your choice: " << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice is: ";
        cout<<"Your choice is: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to be enqueued: ";
            cin >> val;
            q.enQueue(val);
            cout << endl;
            break;
        case 2:
            q.deQueue();
            cout << endl;
            break;
        case 3:
            cout << "The value at the front of the queue is: " << q.peek() << endl;
            cout << endl;
            break;
        case 4:
            q.Display();
            cout << endl;
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