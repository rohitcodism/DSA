#include<bits/stdc++.h>
using namespace std;

vector<int> Djikstras(int V, vector<vector<int>> adj[], int S){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V, 1e9);

    dist[S] = 0;

    pq.push({0, S});

    while(!pq.empty()){
        int distNode = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]){
            int adjNode = it[0];
            int edgeWeight = it[1];

            if(distNode + edgeWeight < dist[adjNode]){
                dist[adjNode] = distNode + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }

    }

    return dist;
}

int main() {

    ifstream infile("graph.txt");

    int V, E;
    infile >> V >> E;

    vector<vector<int>> adj[V];

    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        infile >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source;
    infile >> source;

    infile.close();

    vector<int> shortestDistances = Djikstras(V, adj, source);

    for (int i = 0; i < V; i++) {
        cout << "Shortest distance from source to node " << i << ": " << shortestDistances[i] << endl;
    }

    cout << "Adjacency List:\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": ";
        for (auto it : adj[i]) {
            cout << "(" << it[0] << ", " << it[1] << ") ";
        }
        cout << endl;
    }

    return 0;
}