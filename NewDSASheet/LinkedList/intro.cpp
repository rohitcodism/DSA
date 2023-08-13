#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        class Node *next;
};

int main(){
    Node *p;
    p = new Node;
    p->data = 10;
    p->next = 0;
    cout<<p->data<<endl;
    cout<<p->next<<endl;
}