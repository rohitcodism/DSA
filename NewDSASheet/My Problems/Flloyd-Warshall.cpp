#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define INF 999;

int main()
{
    int n;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;
    cout << endl;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] == 999)
            {
                graph[i][j] = 1e9;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    cout << "All the shortest paths: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1e9)
            {
                graph[i][j] = INF;
            }
            cout << graph[i][j] << "  ";
        }
        cout << endl;
    }
}