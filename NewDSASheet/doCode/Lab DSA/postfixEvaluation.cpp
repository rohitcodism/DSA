// implementation of postfix evaluation using stack and linked list

#include <iostream>
#include <string>
using namespace std;


// Node to represent a term in the polynomial expression
struct Node
{
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = nullptr;
    }
};

// Class to represent a polynomial expression using a linked list
class Stack
{
private:
    Node *top; // Pointer to the head of the linked list
public:
    Stack(){
        top = nullptr;
    }

    // Function to insert a new term into the polynomial expression
    void push(int d)
    {
        Node *newNode = new Node(d);

        if(!newNode){
            cout<<"Heap Overflow"<<endl;
            return;
        }

        if (top == nullptr)
        {
            newNode->next = top;
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }

    // Function to display the polynomial expression
    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *current = top;
        top = top->next;
        delete current;
    }
    // function to evaluate postfix expression
    string eval(string postfix){
        for(int i = 0; i < postfix.length(); i++){
            if(postfix[i] >= '0' && postfix[i] <= '9'){
                push(postfix[i] - '0');
            }
            else{
                int op1 = top->data;
                pop();
                int op2 = top->data;
                pop();
                switch(postfix[i]){
                    case '+':
                        push(op1 + op2);
                        break;
                    case '-':
                        push(op1 - op2);
                        break;
                    case '*':
                        push(op1 * op2);
                        break;
                    case '/':
                        push(op1 / op2);
                        break;
                }
            }
        }
        return to_string(top->data);
    }
};

int main()
{
    Stack s;
    string postfix = "32*1+";
    cout << s.eval(postfix) << endl;
    return 0;
}