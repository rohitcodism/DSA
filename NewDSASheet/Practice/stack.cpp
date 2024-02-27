#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void explainStack() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    printStack(s);
    cout << "Size: " << s.size() << endl;
    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "After pop: " << endl;
    printStack(s);
    cout << "Size: " << s.size() << endl;
    cout << "Top: " << s.top() << endl;
}

int main() {
    explainStack();
    return 0;
}