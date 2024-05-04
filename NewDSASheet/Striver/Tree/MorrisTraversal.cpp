#include <bits/stdc++.h>
#include "Tree.h"
using namespace std;

treeNode* rightMostNode(treeNode* root){
    if(!root)
        return nullptr;

    while(root->right){
        root = root->right;
    }

    return root;
}

vector<vector<int>> MorrisTraversal(treeNode *root)
{
    vector<int> inOrder;

    vector<int> preOrder;

    vector<vector<int>> Traversals;

    treeNode *curr = root;

    while (curr != nullptr)
    {
        if (curr->left != nullptr)
        {
            inOrder.push_back(curr->data);

            preOrder.push_back(curr->data);
            
            curr = curr->right;
        }

        else
        {
            treeNode* predecessor = curr->left;

            while(predecessor->right != nullptr && predecessor->right != curr){
                predecessor = predecessor->right;
            }

            // Connecting the thread
            if(predecessor->right == nullptr){
                predecessor->right = curr;

                // Traveling to left sub-tree
                curr = curr->left;
            }else{
                predecessor->right = nullptr;
                inOrder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    Traversals.push_back(inOrder);

    Traversals.push_back(preOrder);

    return Traversals;
}

int main(){

    Tree tree;

    tree.insert(tree.getRoot(), 10);
    tree.insert(tree.getRoot(), 3);
    tree.insert(tree.getRoot(), 2);
    tree.insert(tree.getRoot(), 4);
    tree.insert(tree.getRoot(), 12);
    tree.insert(tree.getRoot(), 13);
    tree.insert(tree.getRoot(), 11);

    vector<vector<int>> Traversals = MorrisTraversal(tree.getRoot());

    return 0;
}