#include<bits/stdc++.h>
#include<Tree.h>
using namespace std;

bool getPath(treeNode* root, int target, vector<int> &arr){
    if(root==NULL)
        return false;

    arr.push_back(root->data);

    if(root->data == target){
        return true;
    }

    if(getPath(root->left, target, arr)&& getPath(root->right, target, arr)){
        return true;
    }

    arr.pop_back();
    return false;
}

int main(){
    
}