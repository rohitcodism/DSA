#include<bits/stdc++.h>
#include<Tree.h>
using namespace std;

vector<int>rightView(treeNode* root, int level){

    map<int , int>msp;

    vector<int> res;

    if(!root) return;
    
    if(msp.find(level) == msp.end()){
        msp[level] = root->data;
    }

    rightView(root->right, level+1);
    rightView(root->left, level+1);

    for(auto it : msp){
        res.push_back(it.second);
    }

    return res;
}

vector<int> leftView(treeNode* node, int level){

    map<int, int> msp;

    vector<int> res;

    if(!node) return;

    if(msp.find(level) == msp.end())
        msp[level] = node->data;
    
    leftView(node->left, level+1);
    leftView(node->right, level+1);

    for(auto it : msp){
        res.push_back(it.second);
    }

    return res;
}