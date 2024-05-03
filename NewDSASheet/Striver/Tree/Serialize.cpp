#include<bits/stdc++.h>
#include<Tree.h>
using namespace std;

string serialize(treeNode* root){
    if(!root) return "";

    string s = "";

    queue<treeNode*> q;
    q.push(root);

    while(!q.empty()){
        treeNode* newNode = q.front();

        q.pop();

        if(!newNode){
            s.append("#");
        }
        else{
            s.append(to_string(newNode->data)+',');
        }
        if(!(newNode == nullptr)){
            q.push(newNode->left);
            q.push(newNode->right);
        }
    }

    
}

treeNode* deSerialize(string data){

    if(data.length() == 0){
        return NULL;
    }

    stringstream s(data);

    string str;

    getline(s, str, ',');

    treeNode* root = new treeNode(stoi(str));

    queue<treeNode*> q;

    q.push(root);

    while(!q.empty()){
        treeNode* node = q.front();

        q.pop();

        getline(s,str,',');

        if(str == "#"){
            node->left = NULL;
        }

        else{
            treeNode* leftNode = new treeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');

        if(str == "#"){
            node->right = NULL;
        }

        else{
            treeNode* rightNode = new treeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;

}