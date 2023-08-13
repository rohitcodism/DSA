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

int Count(Node *p){
    if(p == NULL){
        return 0;
    }else{
        return Count(p->next)+1;
    }
}


int main(){
    int A[] = {1,2,3,4,5,6,7};
    Create(A, 7);
    // display(first);
    cout<<"The number of nodes in the linked list is : "<<Count(first)<<endl;
    return 0;
}