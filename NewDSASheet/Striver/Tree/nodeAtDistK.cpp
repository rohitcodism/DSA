#include <Tree.h>
#include <bits/stdc++.h>
using namespace std;

unordered_map<treeNode *, treeNode *> parentFinder(treeNode *root)
{
    queue<treeNode *> Q;

    unordered_map<treeNode *, treeNode *> msp;

    Q.push(root);

    while (!Q.empty())
    {
        int inserted = 0;
        treeNode *node = Q.front();
        Q.pop();

        if (node->left)
        {
            msp[node->left] = node;
            Q.push(node->left);
        }
        if (node->right)
        {
            msp[node->right] = node;
            Q.push(node->right);
        }
    }

    return msp;
}

vector<int> nodeAtDistanceK(treeNode *target, int k, treeNode *root)
{
    queue<treeNode *> nodeQueue;

    vector<int> res;

    map<treeNode *, bool> visited;

    unordered_map<treeNode *, treeNode *> msp = parentFinder(root);

    int distance = 0;

    nodeQueue.push(target);

    while (!nodeQueue.empty())
    {

        if (distance == k) break;

        int queueSize = nodeQueue.size();

        for (int i = 0; i < queueSize; i++)
        {
            treeNode *node = nodeQueue.front();
            nodeQueue.pop();

            if (msp.find(node) != msp.end() && !visited[node])
            {
                nodeQueue.push(msp[node]);
                visited[msp[node]] = true;
            }
            if (node->left && !visited[node])
            {
                nodeQueue.push(node->left);
                visited[node->left] = true;
            }
            if (node->right && !visited[node])
            {
                nodeQueue.push(node->right);
                visited[node->right] = true;
            }
        }
        distance++;
    }

    while (!nodeQueue.empty())
    {
        res.push_back(nodeQueue.front()->data);

        nodeQueue.pop();
    }

    return res;
}