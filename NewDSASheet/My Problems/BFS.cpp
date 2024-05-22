#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(vector<int> adj[], int S, int V){
    int visited[V] = {0};

    queue<int> Q;

    vector<int> bfs;

    visited[S] = 1;

    Q.push(S);

    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        bfs.push_back(curr);

        for(auto it : adj[curr]){
            if(!visited[it]){
                visited[it] = 1;
                Q.push(it);
            }
        }
    }

    return bfs;

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
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    int startVertex;
    infile >> startVertex;

    vector<int> bfsTraversal = BFS(adj, startVertex, V);

    cout << "BFS Traversal: ";
    for (int i = 0; i < bfsTraversal.size(); i++) {
        cout << bfsTraversal[i] << " ";
    }
    cout << endl;

    return 0;
}