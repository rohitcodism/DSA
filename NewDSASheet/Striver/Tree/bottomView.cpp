#include<bits/stdc++.h>
#include<Tree.h>
using namespace std;

vector<int>bottomView(treeNode* root){

    int vert = 0;

    vector<int>res;

    queue<pair<treeNode*,int>>Q;

    map<int, int> msp;

    Q.push({root, vert});

    while(!Q.empty()){
        auto it = Q.front();
        Q.pop();

        treeNode* node = it.first;

        int line = it.second;

        // if(msp.find(vert) != msp.end()) msp[vert] = node->data;

        msp[line] = node->data;

        if(node->left)
            Q.push({node->left, vert-1});
        if(node->right)
            Q.push({node->right, vert+1});
    }

    for(auto it : msp){
        res.push_back(it.second);
    }

    return res;

}