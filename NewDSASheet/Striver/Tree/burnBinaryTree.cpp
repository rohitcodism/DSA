#include<Tree.h>
#include<bits/stdc++.h>
using namespace std;


unordered_map<treeNode*, treeNode*> parentFinder (treeNode* root){
    queue<treeNode*>Q;

    unordered_map<treeNode*, treeNode*>msp;

    Q.push(root);

    while(!Q.empty()){
        treeNode* node = Q.front();
        Q.pop();

        if(node->left){
            Q.push(node->left);
            msp[node->left] = node;
        }
        if(node->right){
            Q.push(node->right);
            msp[node->right] = node;
        }
    }
    return msp;
}


int BurnTime(treeNode* bNode, treeNode* root){
    queue<treeNode*>Q;

    unordered_map<treeNode*, treeNode*>msp = parentFinder(root);

    map<treeNode*, bool>visited;

    int burnTime = 0;

    Q.push(bNode);

    while(!Q.empty()){

        int size = Q.size();

        for(int i = 0;i<size;i++){
            treeNode* node = Q.front();

            Q.pop();

            if(msp.find(msp[node]) != msp.end() && !visited[msp[node]]){
                Q.push(msp[node]);
                visited[msp[node]] = true;
            }
            if(node->left && !visited[node->left]){
                Q.push(node->left);
                visited[node->left] = true;
            }
            if(node->right && !visited[node->right]){
                Q.push(node->right);
                visited[node->right] = true;
            }
        }
        burnTime++;
    }
    return burnTime;
}