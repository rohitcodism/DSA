#include <iostream>
#include <fstream>

using namespace std;

int* DFS(int node, int** adj, int V, int visited[], int dfs[], int& index)
{
    visited[node] = 1;
    dfs[index++] = node;

    for (int i = 0; i < V; i++)
    {
        if (adj[node][i] == 1 && !visited[i])
        {
            DFS(i, adj, V, visited, dfs, index);
        }
    }

    return dfs;
}

int* Solve(int S, int** adj, int V)
{
    int* visited = new int[V];
    for (int i = 0; i < V; ++i)
    {
        visited[i] = 0;
    }

    int* dfs = new int[V];
    int index = 0;

    DFS(S, adj, V, visited, dfs, index);

    delete[] visited;
    return dfs;
}

int main()
{
    int V, E;

    ifstream infile("BFS.txt");

    if (!infile)
    {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    infile >> V >> E;

    int** adj = new int*[V];
    for (int i = 0; i < V; i++)
    {
        adj[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u, v;
        infile >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // Assuming undirected graph
    }

    cout << "Adjacency List:" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }

    int S;
    infile >> S;

    infile.close();

    int* result = Solve(S, adj, V);

    cout << "DFS traversal: ";
    for (int i = 0; i < V; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < V; i++)
    {
        delete[] adj[i];
    }
    delete[] adj;
    delete[] result;

    return 0;
}
