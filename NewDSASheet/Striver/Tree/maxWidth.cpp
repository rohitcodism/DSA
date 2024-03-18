#include<bits/stdc++.h>
#include<Tree.h>
using namespace std;


int maxWidth(treeNode* root){

    queue<pair<treeNode*, int>>Q;
    Q.push({root, 0});
    int ans = 0;

    while(!Q.empty()){
        int minIndex = Q.front().second;
        int size = Q.size();
        int first, last;

        for(int i = 0;i<size;i++){
            int curr_Id = Q.front().second - minIndex;

            treeNode* node = Q.front().first;
            Q.pop();

            if(i == 0) first = curr_Id;

            if(i == size-1 ) last = curr_Id;

            if(node->left)
                Q.push({node->left, 2*curr_Id + 1});
            if(node->right)
                Q.push({node->right, 2*curr_Id + 2});
        }

        ans = max(ans, last-first+1);
    }
    return ans;
}