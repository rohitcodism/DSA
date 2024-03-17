#include<bits/stdc++.h>
#include<Tree.h>
using namespace std;

bool checkSymmetric(treeNode* left, treeNode* right){
    
    if(!left || !right)
        return left == right;
    
    if(left->data != right->data) return false;

    return checkSymmetric(left->left , right->right) && (left->right, right->left);
    
}

bool isSymmetric(treeNode* root){
    return root == NULL || checkSymmetric(root->left, root->right);
}