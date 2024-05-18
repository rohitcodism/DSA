#include <bits/stdc++.h>
#include "Tree.h"
using namespace std;

treeNode *CeilTree(treeNode *root, int key)
{
    if (!root)
    {
        return nullptr;
    }

    treeNode *ceil = new treeNode(-1);

    if(key == root->data){
        ceil = root;
        return ceil;
    }
    if(key>root->data){
        root = root->right;
    }
    else{
        ceil = root;
        root->left;
    }

    return ceil;
}

int main()
{
    Tree tree;

    tree.insert(tree.getRoot(), 10);
    tree.insert(tree.getRoot(), 5);
    tree.insert(tree.getRoot(), 13);
    tree.insert(tree.getRoot(), 3);
    tree.insert(tree.getRoot(), 6);
    tree.insert(tree.getRoot(), 11);
    tree.insert(tree.getRoot(), 14);
    tree.insert(tree.getRoot(), 2);
    tree.insert(tree.getRoot(), 4);
    tree.insert(tree.getRoot(), 9);

    tree.display(tree.getRoot());

    int ceil = CeilTree(tree.getRoot(), 3)->data;

    cout << "Ceil is : " << ceil << endl;
}