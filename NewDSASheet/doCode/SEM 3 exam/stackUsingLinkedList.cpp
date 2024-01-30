// implementation of stack using linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node *top;
public:
    Stack() {
        this->top = nullptr;
    }

    bool underflow() {
        return this->top == nullptr;
    }

/**
 * The display function prints the elements of a linked list stack.
 * 
 * @return void, which means it is not returning any value.
 */
    void display(){
        if (underflow()) {
            cout << "Cannot display an empty Linked list" << endl;
            return;
        }
        Node *temp = this->top;
        cout<<"Stack is: "<<endl;
        while (temp != NULL) {
            cout << temp->data <<endl;
            temp = temp->next;
        }
        cout << endl;
    }

    /**
     * The push function adds a new node with a given value to the top of the stack.
     *
     * @param val The value to be pushed into the stack.
     *
     * @return The function does not have a return type.
     */

    void push(int val) {
        Node *temp = new Node(val);

        if (!temp) {
            cout << "Heap Overflow" << endl;
            return;
        }

        temp->next = this->top;
        this->top = temp;
    }

    /**
     * The pop function removes the top node from the stack.
     *
     * @param The function does not have a parameter.
     *
     * @return The function returns the value of the node that was popped.
     */

    int pop() {
        if (underflow()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        Node *temp = this->top;
        this->top = this->top->next;
        int popped = temp->data;
        delete temp;
        return popped;
    }

    /**
     * The peek function returns the value of the node at the top of the stack.
     *
     * @param The function does not have a parameter.
     *
     * @return The function returns the value of the node at the top of the stack.
     */

    int peek() {
        if (underflow()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return this->top->data;
    }
};

int main(){
    int choice,val;

    Stack s1;

    do{

        cout<<"------Menu----"<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;

        switch(choice){
            case 1:
                cout<<"Enter the value to be pushed: ";
                cin>>val;
                s1.push(val);
                s1.display();
                break;
            case 2:
                cout<<"The popped element is: "<<s1.pop()<<endl;
                s1.display();
                break;
            case 3:
                cout<<"The top element is : "<<s1.peek()<<endl;
                s1.display();
                break;
            case 4:
                s1.display();
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }

    }while(choice);
}