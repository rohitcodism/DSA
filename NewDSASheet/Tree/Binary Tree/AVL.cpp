#include <iostream>
using namespace std;

class Node
{
    public:
    Node *left;
    int data;
    int height;
    Node *right;

    Node(int value){
        this->data = value;
        this->left = this->right = NULL;
        this->height = 1;
    }
} *root = NULL;

int balanceFactor(Node *p){
    int hl,hr;
    hl = p && p->left?p->left->height : 0;
    hr = p && p->right?p->right->height : 0;

    return hl-hr;
}

int nodeHeight(Node *p){
    int hl,hr;
    hl = p && p->left?p->left->height : 0;
    hr = p && p->right?p->right->height : 0;
    return hl>hr?hl+1:hr+1;
}

Node *LLRotation(Node *p){
    Node *pl = p->left;
    Node *plr = p->left->right;

    pl->right = p;
    p->left = plr;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if(root == p)
        root = pl;
    
    return pl;
}

Node *LRRotation(Node *p){
    return p;
}

Node *RRRotation(Node *p){
    return p;
}

Node *RLRotation(Node *p){
    return p;
}

Node *RInsert(Node *p, int value)
{
    Node *t;
    if (p == NULL)
    {
        t = new Node(value);
        cout << "Node Inserted Successfully !!" << endl;
        return t;
    }
    else
    {
        if (value < p->data)
        {
            p->left = RInsert(p->left, value);
        }
        else if (value > p->data)
            p->right = RInsert(p->right, value);
    }

    p->height = nodeHeight(p);

    if(balanceFactor(p) == 2 && balanceFactor(p->left) == 1)
    {
        return LLRotation(p);
    }
    else if(balanceFactor(p) == 2 && balanceFactor(p->left) == -1)
    {
        return LRRotation(p);
    }
    else if(balanceFactor(p) == -2 && balanceFactor(p->right) == -1){
        return RRRotation(p);
    }
    else if(balanceFactor(p) == -2 && balanceFactor(p->right) == 1){
        return RLRotation(p);
    }


    return p;
}

int main()
{
    root = RInsert(root,10);
    RInsert(root, 5);
    RInsert(root,2);
    RInsert(root, 12);
    cout<<root->data<<endl<<root->right->left<<endl;
    return 0;
}