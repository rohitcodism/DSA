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
    if(p)
        return Count(p->next)+1;
    return 0;
}

int SumOfElements(Node *p){
    if(p)
        return SumOfElements(p->next)+p->data;
    return 0;
}

int Max(Node *p){
    int m = -32768;
    if(!p)
        return m;
    else{
        int x = Max(p->next);
        return x>p->data ? x : p->data;
    }
}

Node* search(Node *p, int key){
    if(p == NULL)
        return NULL;
    else{
        if(key == p->data)
            return (p);
        search(p->next, key); 
    }
}

Node* MTH(Node* p, int key){
    Node *q = NULL;
    while(p){
        if(key == p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void insertFirst(int key){
    Node *t;
    t->data = key;
    t->next = first;
    first = t;
}

int main(){
    int A[] = {1,2,3,4,5,6,7};
    Create(A, 7);
    // display(first);
    // cout<<"The number of nodes in the linked list is : "<<Count(first)<<endl;
    // cout<<"The sum of elements in the linked list is : "<<SumOfElements(first)<<endl;
    // cout<<"The Maximum element in the linked list is : "<<Max(first)<<endl;
    // cout<<search(first, 3)<<endl;
    Node *src = MTH(first, 3);
    if(src)
        cout<<"Key was found : "<<src->data<<endl;
    else
        cout<<"Key wasn't found."<<endl;

    int k;
    cout<<"Enter a key to insert : "<<endl;
    cin>>k;
    insertFirst(k);
    display(first);
    return 0;
}