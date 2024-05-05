#include<bits/stdc++.h>
#include "Tree.h"
using namespace std;

treeNode* Flatten(treeNode* root){
    stack<treeNode*> Nodes;

    Nodes.push(root);

    while(!Nodes.empty()){
        treeNode* curr = Nodes.top();

        Nodes.pop();

        if(curr->right){
            Nodes.push(curr->right);
        }
        if(curr->left){
            Nodes.push(curr->left);
        }

        if(!Nodes.empty()){
            curr->right = Nodes.top();
            curr->left = nullptr;
        }
    }

    return root;
}

int main(){
    Tree tree;

    tree.insert(tree.getRoot(), 7);
    tree.insert(tree.getRoot(), 3);
    tree.insert(tree.getRoot(), 1);
    tree.insert(tree.getRoot(), 2);
    tree.insert(tree.getRoot(), 9);
    tree.insert(tree.getRoot(), 8);
    tree.insert(tree.getRoot(), 10);
    tree.insert(tree.getRoot(), 11);

    cout<<"Before Flattening : "<<endl;

    tree.display(tree.getRoot());

    cout<<endl;

    treeNode* newRoot = Flatten(tree.getRoot());

    cout<<"After flattening : "<<endl;

    tree.display(newRoot);
}