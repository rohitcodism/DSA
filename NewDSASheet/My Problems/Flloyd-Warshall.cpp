#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of vertices in the graph : ";
    cin >> n;
    cout << endl;

    int **graph = new int *[n];

    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 1; i <= n; i++)
    {
        graph[i] = new int[n];
        for (int j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    cout << "All the shortest path : " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }
}