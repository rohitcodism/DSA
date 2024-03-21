#include<bits/stdc++.h>
#include<Tree.h>
using namespace std;


treeNode* childrenSum(treeNode* root){

    if(!root) return;

    if(root->left && root->right && root->left->data + root->right->data < root->data){
        root->left->data = root->right->data = root->data;
    }

    treeNode* leftChild = childrenSum(root->left);
    
    treeNode* rightChild = childrenSum(root->right);

    if(leftChild && rightChild)
        root->data = leftChild->data + rightChild->data;
    
    return root;


}