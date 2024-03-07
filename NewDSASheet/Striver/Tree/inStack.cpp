#include<bits/stdc++.h>
using namespace std;


struct treeNode{
    int data;
    treeNode* left;
    treeNode* right;
    treeNode(int val){
        this->data = val;
        this->left = this->right = nullptr;
    }
    treeNode(){
        this->data = 0;
        this->left = this->right = nullptr;
    }

    treeNode(int val, treeNode* lc, treeNode* rc){
        this->data = val;
        this->left = lc;
        this->right = rc;
    }
};

class Operations {

    public:
/**
 * The function performs an iterative in-order traversal of a binary tree and returns the elements in
 * in-order sequence.
 * 
 * @param root The `root` parameter in the `inOrder` function is a pointer to the root node of a binary
 * tree. The function performs an in-order traversal of the binary tree starting from the root node and
 * returns a vector of integers representing the nodes visited in in-order sequence.
 */
        vector<int> inOrder(treeNode* root){
            stack<treeNode*>st;
            treeNode* Node = root;
            vector<int> inOrder;
            while(true){
                if(Node){
                    st.push(Node);
                    Node = Node ->left;
                }
                else{
                    if(st.empty()) break;
                    Node = st.top();
                    st.pop();
                    inOrder.push_back(Node->data);
                    Node = Node->right;
                }
            }
        }

/**
 * The function `postOrder` returns a vector of integers representing the post-order traversal of a
 * binary tree.
 * 
 * @param root The `root` parameter in the `postOrder` function represents the root node of a binary
 * tree. The function aims to perform a post-order traversal of the binary tree starting from the given
 * root node.
 * 
 * @return The function `postOrder` returns a vector of integers containing the post-order traversal of
 * a binary tree.
 */
        vector<int> postOrder(treeNode* root){
            vector<int> postOrder;
            stack<treeNode*>st1,st2;
            st1.push(root);

            while(!st1.empty()){
                root = st1.top();
                st1.pop();
                st2.push(root);
                if(root->left)
                    st1.push(root->left);
                if(root->right)
                    st1.push(root->right);
            }
            while(!st2.empty()){
                postOrder.push_back(st2.top()->data);
                st2.pop();
            }
            return postOrder;
        }
};