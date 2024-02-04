// implementation of Binary Search Tree

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void Display(Node *root){
    if(root == nullptr){
        return;
    }
    cout << root->data << " ";
    Display(root->left);
    Display(root->right);
}

Node *insertBST(Node *root, int val){
    if(root == nullptr){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insertBST(root->left, val);
    }
    else{
        root->right = insertBST(root->right, val);
    }
    return root;
}

void inorder(Node *root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root){
    if(root == nullptr){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(root == nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node *searchBST(Node *root, int key){
    if(root == nullptr){
        return nullptr;
    }
    if(root->data == key){
        return root;
    }
    if(key < root->data){
        return searchBST(root->left, key);
    }
    return searchBST(root->right, key);
}

Node *inorderSucc(Node *root){
    Node *curr = root;
    while(curr && curr->left != nullptr){
        curr = curr->left;
    }
    return curr;
}

Node *deleteBST(Node *root, int key){
    if(key < root->data){
        root->left = deleteBST(root->left, key);
    }
    else if(key > root->data){
        root->right = deleteBST(root->right, key);
    }
    else{
        if(root->left == nullptr){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == nullptr){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

int main(){
    Node *root = nullptr;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    // Display(root);
    // inorder(root);
    // cout << endl;
    // preorder(root);
    // cout << endl;
    // postorder(root);
    // cout << endl;
    // if(searchBST(root, 4) == nullptr){
    //     cout << "Key doesn't exist" << endl;
    // }
    // else{
    //     cout << "Key exists" << endl;
    // }
    deleteBST(root, 3);
    inorder(root);
    cout << endl;
    return 0;
}