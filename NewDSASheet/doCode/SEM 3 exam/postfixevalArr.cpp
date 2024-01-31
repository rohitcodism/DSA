// // implementation of postfix evaluation through stack using Array

// #include <iostream>
// #include <string>
// using namespace std;

// class Stack
// {
// private:
//     int size;
//     int top;
//     int *arr;
// public:
//     Stack(int size)
//     {
//         this->size = size;
//         top = -1;
//         arr = new int[size];
//     }
//     ~Stack()
//     {
//         delete [] arr;
//     }
//     void push(int x);
//     int pop();
//     int peek(int index);
//     int isEmpty();
//     int isFull();
//     int stackTop();
// };

// int Stack:: isFull()
// {
//     if(top == size-1)
//         return 1;
//     return 0;
// }

// int Stack:: isEmpty()
// {
//     if(top == -1)
//         return 1;
//     return 0;
// }

// void Stack::push(int x)
// {
//     if(isFull())
//         cout << "Stack Overflow" << endl;
//     else
//     {
//         top++;
//         arr[top] = x;
//     }
// }

// int Stack::pop()
// {
//     int x = -1;
//     if(isEmpty())
//         cout << "Stack Underflow" << endl;
//     else
//     {
//         x = arr[top];
//         top--;
//     }
//     return x;
// }

// int Stack::peek(int index)
// {
//     int x = -1;
//     if(top-index+1 < 0)
//         cout << "Invalid Index" << endl;
//     else
//         x = arr[top-index+1];
//     return x;
// }

// int Stack::stackTop()
// {
//     if(isEmpty())
//         return -1;
//     return arr[top];
// }

// int isOperand(char x)
// {
//     if(x == '+' || x == '-' || x == '*' || x == '/')
//         return 0;
//     else
//         return 1;
// }

// int operation(int x, int y, char op)
// {
//     if(op == '+')
//         return x+y;
//     else if(op == '-')
//         return x-y;
//     else if(op == '*')
//         return x*y;
//     else if(op == '/')
//         return x/y;
//     else
//         return 0;
// }

// int postfixEval(string postfix)
// {
//     Stack stk(postfix.length());
//     int x1, x2, r;
//     for(int i=0; postfix[i]!='\0'; i++)
//     {
//         if(isOperand(postfix[i]))
//             stk.push(postfix[i]-'0');
//         else
//         {
//             x2 = stk.pop();
//             x1 = stk.pop();
//             r = operation(x1, x2, postfix[i]);
//             stk.push(r);
//         }
//     }
//     return stk.pop();
// }

// // menu driven program
// int main()
// {
//     string postfix;
//     cout << "Enter the postfix expression: ";
//     cin >> postfix;
//     cout << "Result: " << postfixEval(postfix) << endl;
//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    int capacity;
    int size;
    int top;
    int *arr;

public:
    Stack(int capacity)
    {
        this->top = -1;
        this->size = 0;
        this->capacity = capacity;
        this->arr = new int[this->capacity];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    void Display()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!!!" << endl;
            return;
        }

        cout << "Stack is : " << endl;
        for (int i = 0; i < this->size - 1; i++)
        {
            cout << this->arr[i] << endl;
        }
    }

    void Push(int val)
    {
        if (isFull())
        {
            cout << "Stack Overflow!!!" << endl;
            return;
        }

        this->arr[++top] = val;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!!!" << endl;
            return -1;
        }

        int x = this->arr[top--];
        return x;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!!!" << endl;
            return -1;
        }

        return this->arr[top];
    }
};

bool isAlNum(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return false;
    }
    return true;
}

int operation(int op1, int op2, char opr)
{

    switch (opr)
    {
    case '+':
        return op1 + op2;
        break;
    case '-':
        return op1 - op2;
        break;
    case '*':
        return op1 * op2;
        break;
    case '/':
        return op1 / op2;
        break;
    default:
        return 0;
        break;
    }
}
string postfixEval(string exp)
{
    Stack stk(exp.length());
    int x1, x2, r;
    for (int i = 0; i < exp.length(); i++)
    {
        if (isAlNum(exp[i]))
        {
            stk.Push(exp[i] - '0');
        }
        else
        {
            x1 = stk.pop();
            x2 = stk.pop();
            r = operation(x1, x2, exp[i]);
            stk.Push(r);
        }
    }
    return to_string(stk.pop());
}

int main()
{
        string postfix;
        cout << "Enter the postfix expression: ";
        cin >> postfix;
        cout << "Result: " << postfixEval(postfix) << endl;
        return 0;
}