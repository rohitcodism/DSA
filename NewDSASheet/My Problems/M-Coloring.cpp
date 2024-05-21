#include<bits/stdc++.h>
using namespace std;

bool canColor(vector<vector<int>>& Graph, int node, vector<int>& Color, int N, int color){

    for(int k = 0;k<N;k++){
        if(k != node && Graph[k][node] == 1 && Color[k] == color){
            return false;
        }
    }
    
    return true;
}

bool ColorIt(int node, vector<vector<int>>& Graph, int M, int N, vector<int>& Color){
    if(node == N){
        return true;
    }

    for(int i = 0; i<M;i++){
        if(canColor(Graph, node, Color, N, i)){
            Color[node] = i;
            
            if(ColorIt(node+1,Graph,M,N,Color)){
                return true;
            }
            Color[node] = 0;
        }
    }
    return false;
}

int main() {
    int M, N;
    cout << "Enter the number of nodes: ";
    cin >> N;
    cout << endl;

    cout << "Enter the number of colors: ";
    cin >> M;
    cout << endl;

    vector<int> Colors(N, 0);

    vector<vector<int>> Graph(N, vector<int>(N, 0));

    cout << "Enter the adjacency matrix (0 or 1) for the graph:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin>>Graph[i][j];
        }
    }

    if (ColorIt(0, Graph, M, N, Colors)) {
        cout << "Graph can be colored using " << M << " colors." << endl;
        cout << "Coloring sequence: ";
        for (int i = 0; i < N; i++) {
            cout << Colors[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Graph cannot be colored using " << M << " colors." << endl;
    }

    return 0;
}