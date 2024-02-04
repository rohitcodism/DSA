// implementation of parenthesis matching in C++ using stack using linked list


#include <iostream>
using namespace std;


struct Node
{
    char data;
    Node *next;
    Node(char data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack
{
private:
    Node *top;
public:
    Stack()
    {
        this->top = nullptr;
    }

    bool underflow()
    {
        return this->top == nullptr;
    }

    void display()
    {
        if (underflow())
        {
            cout << "Cannot display an empty Linked list" << endl;
            return;
        }
        Node *temp = this->top;
        cout << "Stack is: " << endl;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    void push(char val)
    {
        Node *temp = new Node(val);

        if (!temp)
        {
            cout << "Heap Overflow" << endl;
            return;
        }

        temp->next = this->top;
        this->top = temp;
    }

    char pop()
    {
        if (underflow())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        Node *temp = this->top;
        this->top = this->top->next;
        char popped = temp->data;
        delete temp;
        return popped;
    }

    char peek()
    {
        if (underflow())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return this->top->data;
    }

    bool parenthesisMatching(string exp)
    {
        for (int i = 0; i < exp.length(); i++)
        {
            if (exp[i] == '(')
            {
                push(exp[i]);
            }
            else if (exp[i] == ')')
            {
                if (underflow())
                {
                    return false;
                }
                pop();
            }
        }
        return underflow();
    }
};

int main(){
    Stack s;
    string exp;
    cout << "Enter an expression: ";
    cin >> exp;
    if (s.parenthesisMatching(exp))
    {
        cout << "Parenthesis are balanced" << endl;
    }
    else
    {
        cout << "Parenthesis are not balanced" << endl;
    }
}