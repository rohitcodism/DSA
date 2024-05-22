#include <bits/stdc++.h>
using namespace std;

vector<int> DFS(int node, vector<int> adj[], int V, int visited[], vector<int>& dfs)
{

    visited[node] = 1;

    dfs.push_back(node);

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            DFS(it, adj, V, visited, dfs);
        }
    }

    return dfs;
}

vector<int> Solve(int S, vector<int> adj[], int V)
{
    int visited[V] = {0};

    vector<int> dfs;

    DFS(S, adj, V, visited, dfs);

    return dfs;
}

int main() {
    int V, E;

    ifstream infile("BFS.txt");

    infile >> V >> E;

    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        infile >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Adjacency List:" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    int S;
    infile >> S;

    infile.close();

    vector<int> result = Solve(S, adj, V);

    cout << "DFS traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}