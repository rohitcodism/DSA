// implementation of stack using array

#include <iostream>
using namespace std;


class Stack
{
private:
    int *arr;
    int capacity;
    int size;
public:
    Stack(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
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

    void display(){
        if(isEmpty()){
            cout<<"Stack is empty!!!"<<endl;
            return;
        }
        cout<<"Stack : ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void push(int x)
    {
        if (size < capacity)
        {
            arr[size] = x;
            size++;
        }
        else
        {
            cout << "Stack Overflow!!!" << endl;
        }
    }

    void pop()
    {
        if (size > 0)
        {
            arr[size - 1] = 0;
            size--;
        }
        else
        {
            cout << "Stack Underflow!!!" << endl;
        }
    }

    int peek()
    {
        if (size > 0)
        {
            return arr[size - 1];
        }
        else
        {
            cout << "Stack is empty!!!" << endl;
            return -1;
        }
    }
};

// menu driven program to implement stack using array
int main()
{
    int capacity;
    cout << "Enter the capacity of the stack : ";
    cin >> capacity;

    Stack s(capacity);

    int option, value;

    do
    {
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. peek()" << endl;
        cout << "4. display()" << endl;
        cout << "5. Clear Screen" << endl
        << endl;

        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter an item to push in the stack : ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            cout << "Peek Function Called - The value at the top is : " << s.peek() << endl;
            break;
        case 4:
            s.display();
            break;
        case 5:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}