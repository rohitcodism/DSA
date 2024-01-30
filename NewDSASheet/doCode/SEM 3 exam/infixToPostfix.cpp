// implementation of infix to postfix conversion using stack using linked list

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

    int precedence(char ch)
    {
        switch (ch)
        {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
        }
    }

    bool isalnum(char ch)
    {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9');
    }

    string infixToPostfix(string infix)
    {
        string postfix = "";
        for (int i = 0; i < infix.length(); i++)
        {
            if (isalnum(infix[i]))
            {
                postfix += infix[i];
            }
            else if (infix[i] == '(')
            {
                push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (!underflow() && peek() != '(')
                {
                    postfix += pop();
                }
                if (!underflow() && peek() != '(')
                {
                    return "Invalid Expression";
                }
                else
                {
                    pop();
                }
            }
            else
            {
                while (!underflow() && precedence(infix[i]) <= precedence(peek()))
                {
                    postfix += pop();
                }
                push(infix[i]);
            }
        }
        while (!underflow())
        {
            postfix += pop();
        }
        return postfix;
    }
};

int main()
{
    string infix;
    cout << "Enter the infix expression: ";
    cin >> infix;
    Stack s1;
    cout << "The postfix expression is: " << s1.infixToPostfix(infix) << endl;
    return 0;
}