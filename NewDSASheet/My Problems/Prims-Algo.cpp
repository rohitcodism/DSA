#include<bits/stdc++.h>
using namespace std;

int Prims(int V, vector<vector<int>> adjacency[]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

    int sum = 0;

    vector<int> visited(V, 0);

    pq.push({0, 0});

    while(!pq.empty()){
        auto it = pq.top();

        pq.pop();

        int node = it.second;
        int wt = it.first;

        if(visited[node] == 1) continue;
        visited[node] = 1;
        sum += wt;

        for(auto it : adjacency[node]){
            int adjNode = it[0];

            int edW = it[1];

            if(!visited[adjNode]){
                pq.push({edW, adjNode});
            }
        }

    }

    return sum;
}

int main() {

    ifstream infile("prims.txt");

    int V; // number of vertices
    infile >> V;

    vector<vector<int>> adjacency[V]; // adjacency list representation of graph

    cout << "Enter the number of edges: ";
    int E;
    infile >> E;

    cout << "Enter the edges and weights (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        infile >> src >> dest >> weight;

        adjacency[src].push_back({dest, weight});
        adjacency[dest].push_back({src, weight});
    }

    infile.close();

    cout << "Adjacency List:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": ";
        for (auto it : adjacency[i]) {
            cout << "(" << it[0] << ", " << it[1] << ") ";
        }
        cout << endl;
    }

    int minimumCost = Prims(V, adjacency);
    cout << "Minimum cost of spanning tree: " << minimumCost << endl;

    return 0;
}