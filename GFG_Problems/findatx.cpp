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
    last = first;

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

int GetNth(Node *p, int index)
{
    // Code here
    Node *q;
    q = p;

    for (int i = 0; i < index - 1; i++)
    {
        q = q->next;
    }
    cout << q->data << endl;
    q = p;
}

void deleteAlt(Node *head){
    // Code here
    Node *q = head;
    Node *p = NULL;
    int i=1;
    while(q != NULL){
        if(i%2 == 0){
            p->next = q->next;
            q->next = NULL;
            delete (q);
            q = p->next;
            i++;
        }else{
            p = q;
            q = q->next;
            i++;
        }
    }
    q = head;
    while(q){
        cout<<q->data<<endl;
        q = q->next;
    }
}

int main(){
    int A[] = {2,4,6,8};
    Create(A, 4);
    display(first);
    deleteAlt(first);

    return 0;
}