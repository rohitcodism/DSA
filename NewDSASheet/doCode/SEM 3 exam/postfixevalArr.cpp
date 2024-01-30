// implementation of postfix evaluation through stack using Array

#include <iostream>
#include <string>
using namespace std;


class Stack
{
private:
    int size;
    int top;
    int *arr;
public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new int[size];
    }
    ~Stack()
    {
        delete [] arr;
    }
    void push(int x);
    int pop();
    int peek(int index);
    int isEmpty();
    int isFull();
    int stackTop();
};

int Stack:: isFull()
{
    if(top == size-1)
        return 1;
    return 0;
}

int Stack:: isEmpty()
{
    if(top == -1)
        return 1;
    return 0;
}

void Stack::push(int x)
{
    if(isFull())
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        arr[top] = x;
    }
}

int Stack::pop()
{
    int x = -1;
    if(isEmpty())
        cout << "Stack Underflow" << endl;
    else
    {
        x = arr[top];
        top--;
    }
    return x;
}

int Stack::peek(int index)
{
    int x = -1;
    if(top-index+1 < 0)
        cout << "Invalid Index" << endl;
    else
        x = arr[top-index+1];
    return x;
}

int Stack::stackTop()
{
    if(isEmpty())
        return -1;
    return arr[top];
}

int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int operation(int x, int y, char op)
{
    if(op == '+')
        return x+y;
    else if(op == '-')
        return x-y;
    else if(op == '*')
        return x*y;
    else if(op == '/')
        return x/y;
    else
        return 0;
}

int postfixEval(string postfix)
{
    Stack stk(postfix.length());
    int x1, x2, r;
    for(int i=0; postfix[i]!='\0'; i++)
    {
        if(isOperand(postfix[i]))
            stk.push(postfix[i]-'0');
        else
        {
            x2 = stk.pop();
            x1 = stk.pop();
            r = operation(x1, x2, postfix[i]);
            stk.push(r);
        }
    }
    return stk.pop();
}

int main()
{
    string postfix = "234*+82/-";
    cout << "Result is " << postfixEval(postfix) << endl;
    return 0;
}