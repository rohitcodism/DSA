#include <bits/stdc++.h>
#include <Tree.h>
using namespace std;

vector<vector<int>> verticalTrav(treeNode *root)
{
    int vertical = 0;
    int level = 0;

    queue<pair<treeNode *, pair<int, int>>> Q;

    map<int, map<int, multiset<int>>> msp;

    Q.push({root, {vertical, level}});

    while (!Q.empty())
    {
        auto p = Q.front();

        Q.pop();

        treeNode *node = p.first;

        int vert = p.second.first;
        int lev = p.second.second;

        msp[vert][lev].insert(node->data);
        if (node->left)
        {
            Q.push({node->left, {vertical--, level++}});
        }
        if (node->right)
        {
            Q.push({node->right, {vertical++, level--}});
        }
    }

    vector<vector<int>> res;

    for (auto p : msp)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        res.push_back(col);
    }
    return res;
}