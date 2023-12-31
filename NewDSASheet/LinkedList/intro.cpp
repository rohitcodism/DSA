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
    last->next = first;
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

void insertFirst(int key, int pos){
    if(pos<=Count(first)){
        Node *t;
        Node *p = first;
        if(pos == 0){
            t = new Node;
            t->data = key;
            t->next = first;
            first = t;
        }else{
            for(int i  = 0;i<pos-1;i++){
                p = p->next;
            }
            t = new Node;
            t->data = key;
            t->next = p->next;
            p->next = t;
        }
    }
    display(first);
}

void reDup(Node *p){
    Node *q = first->next;
    while(q != NULL){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else if(p->data == q->data){
            p->next = q->next;
            q->next = NULL;
            delete(q);
            q = p->next;
        }
    }
    display(first);
}

void Reverse1(Node *p){
    int A[4];
    int i;
    Node *q = p;
    for(i = 0;i<4 && q;i++){
        A[i] = q->data;
        q = q->next;
    }
    q = first;
    for(i = i-1;i>=0;i--){
        q->data = A[i];
        q = q->next;
    }
    display(first);
}

// Sliding pointer method Reverse

void Reverse2(Node *p){
    Node *q, *r, *s;
    q = p;
    r = NULL;
    s = NULL;
    while(q){
        s = r;
        r = q;
        q = q->next;
        r->next = s;
    }
    first = r;
    display(first);

}

    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *p, *q, *r;
        p = q = r = head;
        if(head->next != NULL){
            do{
                    q = q->next;
                    p = p->next;
                    if(p)
                        p = p->next;
                    else
                        p = NULL;
            }while(p && q && p!=q);
        }
        if(p == q){
            q = p->next;
            while(p != q){
                r = q;
                q = q->next;
            }
            if(p == r){
                p->next = NULL;
                r->next = NULL;
            }else{
                r->next = NULL;
            }
        }
        cout<<p->next<<endl;
        display(head);
    }

int main(){
    int A[] = {1, 3, 4};
    Create(A, 3);
    //cout<<"Before removing dup : "<<endl;
    //display(first);
    // display(first);
    // cout<<"The number of nodes in the linked list is : "<<Count(first)<<endl;
    // cout<<"The sum of elements in the linked list is : "<<SumOfElements(first)<<endl;
    // cout<<"The Maximum element in the linked list is : "<<Max(first)<<endl;
    // cout<<search(first, 3)<<endl;
    // Node *src = MTH(first, 3);
    // if(src)
    //     cout<<"Key was found : "<<src->data<<endl;
    // else
    //     cout<<"Key wasn't found."<<endl;

    // int k, pos;
    // cout<<"Enter a key to insert : ";
    // cin>>k;
    // cout<<"Enter the position you want to insert : ";
    // cin>>pos;
    // insertFirst(k, pos);

    // cout<<"After removing : "<<endl;
    // reDup(first);

    removeLoop(first);

    return 0;
}