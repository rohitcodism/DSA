#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

// Define a template for the type of data stored in the tree node
struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
    treeNode(int val)
    {
        this->data = val;
        this->left = this->right = nullptr;
    }
    treeNode()
    {
        this->data = 0;
        this->left = this->right = nullptr;
    }

    treeNode(int val, treeNode *lc, treeNode *rc)
    {
        this->data = val;
        this->left = lc;
        this->right = rc;
    }
};

class Tree
{
private:
    treeNode *root;

public:
    Tree()
    {
        this->root = nullptr;
    }
    Tree(int data)
    {
        this->root->data = data;
        this->root->left = root->right = nullptr;
    }

    treeNode *getRoot()
    {
        return root;
    }

    void display(treeNode *root)
    {
        if (root)
        {
            display(root->left);
            cout << root->data << " ";
            display(root->right);
        }
        else
        {
            cout << "NULL: There is no root!!! " << endl;
        }
    }

    void insert(treeNode *root, int data)
    {
        if (root == nullptr)
        {
            root = new treeNode(data);
            display(root);
            return;
        }
        if (root->data > data)
        {
            if (root->left == nullptr)
            {
                root->left = new treeNode(data);
            }
            else
            {
                insert(root->left, data);
            }
        }
        else if (root->data < data)
        {
            if (!root->right)
            {
                root->right = new treeNode(data);
            }
            else
            {
                insert(root->right, data);
            }
        }
        display(root);
    }
};

#endif // TREE_H
