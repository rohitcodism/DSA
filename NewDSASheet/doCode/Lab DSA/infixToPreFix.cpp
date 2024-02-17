#include <iostream>
#include <string>

using namespace std;

// Simple Stack implementation for characters
class Stack {
private:
    static const int MAX_SIZE = 100;
    char data[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(char ch) {
        if (!isFull()) {
            top++;
            data[top] = ch;
        }
    }

    char pop() {
        char ch = '\0'; // Null character
        if (!isEmpty()) {
            ch = data[top];
            top--;
        }
        return ch;
    }

    char peek() {
        if (!isEmpty()) {
            return data[top];
        }
        return '\0'; // Null character
    }
};

// Function to check if the character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to get the precedence of an operator
int precedence(char op) {
    if(op == '+' || op == '-')
        return 1;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '^')
        return 3;
    return 0;
}

// Function to reverse a string
string reverseString(string str) {
    string reversed;
    for(int i = str.length() - 1; i >= 0; --i) {
        reversed += str[i];
    }
    return reversed;
}

// Function to convert infix to prefix
string infixToPrefix(string infix) {
    string prefix;
    Stack operators;

    // Step 1: Reverse the infix expression
    infix = reverseString(infix);

    // Step 2: Swap opening and closing parentheses and change operator direction
    for(char* ptr = &infix[0]; *ptr != '\0'; ptr++) {
        char& ch = *ptr;
        if(ch == '(')
            ch = ')';
        else if(ch == ')')
            ch = '(';
    }

    // Step 3: Apply infix to postfix conversion using a stack
    for(char* ptr = &infix[0]; *ptr != '\0'; ptr++) {
        char ch = *ptr;
        if(isalnum(ch)) {
            prefix += ch; // Operand, add it to the prefix expression
        }
        else if(ch == '(') {
            // Push opening parenthesis onto the stack
            operators.push(ch);
        }
        else if(ch == ')') {
            // Pop operators from the stack and add them to the prefix expression
            while(!operators.isEmpty() && operators.peek() != '(') {
                prefix += operators.pop();
            }
            // Pop the opening parenthesis from the stack
            operators.pop();
        }
        else if(isOperator(ch)) {
            // Pop operators with higher or equal precedence and add them to the prefix expression
            while(!operators.isEmpty() && precedence(ch) <= precedence(operators.peek())) {
                prefix += operators.pop();
            }
            // Push the current operator onto the stack
            operators.push(ch);
        }
    }

    // Step 4: Pop remaining operators from the stack and add them to the prefix expression
    while(!operators.isEmpty()) {
        prefix += operators.pop();
    }

    // Step 5: Reverse the prefix expression to get the final result
    prefix = reverseString(prefix);

    return prefix;
}

int main() {
    string infix = "(A+B)*C-D/E";

    cout << "Infix expression: " << infix << endl;

    string prefix = infixToPrefix(infix);

    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
