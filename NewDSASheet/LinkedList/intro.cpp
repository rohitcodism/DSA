#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
}*first;

void Create(int a[], int n){
    int i;
    Node *t, *last;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last=first;

    for(i = 1;i<n;i++){
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(Node *p){
    if(p != NULL){
        cout<<p->data<<" ";
        display(p->next);
    }
}

void Count(Node *p){
    int count;
    while(p->next != NULL){
        count++;
    }
    cout<<"The number of nodes in the linked list is : "<<count<<endl;
}


int main(){
    int A[5] = {1,2,3,4,5};
    Create(A, 5);
    display(first);
    Count(first);
    return 0;
}