#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int Kruskal(int V, vector<pair<int, int>> adj[])
{
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int dest = it.first;
            int wt = it.second;
            if (i < dest)
            { // Prevent duplicating edges in undirected graph
                edges.push_back({wt, {i, dest}});
            }
        }
    }

    sort(edges.begin(), edges.end());

    DSU ds(V);

    int mstSum = 0;

    for (auto it : edges)
    {
        int wt = it.first;
        int src = it.second.first;
        int dest = it.second.second;

        if (ds.find(src) != ds.find(dest))
        {
            mstSum += wt;
            ds.unionSets(src, dest);
        }
    }

    return mstSum;
}

int main()
{
    int V; // number of vertices

    cout << "Enter the number of vertices (positive integer): ";
    if (!(cin >> V) || V <= 0)
    {
        cerr << "Invalid input! Please enter a positive integer." << endl;
        return 1;
    }

    vector<pair<int, int>> adjacency[V]; // adjacency list representation

    int E; // number of edges
    cout << "Enter the number of edges (positive integer): ";
    if (!(cin >> E) || E <= 0)
    {
        cerr << "Invalid input! Please enter a positive integer." << endl;
        return 1;
    }

    cout << "Enter the edges and weights (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++)
    {
        int src, dest, weight;
        cout << "Enter source for edge " << i + 1 << ": ";
        if (!(cin >> src))
        {
            cerr << "Invalid input! Please enter an integer." << endl;
            return 1;
        }
        cout << "Enter destination for edge " << i + 1 << ": ";
        if (!(cin >> dest))
        {
            cerr << "Invalid input! Please enter an integer." << endl;
            return 1;
        }
        cout << "Enter weight for edge " << i + 1 << ": ";
        if (!(cin >> weight))
        {
            cerr << "Invalid input! Please enter an integer." << endl;
            return 1;
        }
        cout << endl;

        adjacency[src].push_back({dest, weight});
        adjacency[dest].push_back({src, weight});
    }

    // Print adjacency list
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << ": ";
        for (auto it : adjacency[i])
        {
            int dest = it.first;
            int wt = it.second;
            cout << "(" << dest << ", " << wt << ") ";
        }
        cout << endl;
    }

    int mstSum = Kruskal(V, adjacency);
    cout << "Minimum Spanning Tree Sum: " << mstSum << endl;

    return 0;
}