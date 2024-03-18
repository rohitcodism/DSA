#include<Tree.h>
#include<bits/stdc++.h>
using namespace std;

treeNode* LCA(treeNode* root, treeNode* p, treeNode* q){
    if(!root || root == p || root == q)
        return root;

    treeNode* left = LCA(root->left, p, q);
    treeNode* right = LCA(root->right, p, q);

    if(!left)
        return right;
    else if(!right)
        return left;
    else
        return root;
}