#include<bits/stdc++.h>
#include<Tree.h>
using namespace std;

vector<int>topView(treeNode* root){

    vector<int> res;

    int vert = 0;

    queue<pair<treeNode*, int>> Q;

    map<int ,int> msp;

    if(!root) return res;

    Q.push({root, vert});

    while(!Q.empty()){
        auto it = Q.front();
        Q.pop();

        treeNode* node = it.first;

        if(msp.find(vert) == msp.end()) msp[vert] = node->data;

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