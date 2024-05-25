#include <iostream>
#include <fstream>
#include <climits> // For INT_MAX

using namespace std;

const int MAX_VERTICES = 100; // Define a maximum number of vertices

// Structure to represent an edge
struct Edge
{
    int src;
    int dest;
    int weight;
};

// Function to find the parent of a node in the Disjoint-Set Union (DSU)
int find(int parent[], int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent, parent[x]); // Path compression
    }
    return parent[x];
}

// Function to perform union of two sets in the DSU
void unionSets(int parent[], int rank[], int x, int y)
{
    int rootX = find(parent, x);
    int rootY = find(parent, y);

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

// Function to swap two edges
void swapEdges(Edge *a, Edge *b)
{
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

// Function to implement selection sort for edges based on weight
void modifiedBubbleSort(Edge edges[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                swapEdges(&edges[j], &edges[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped in the inner loop, then the array is already sorted
        if (!swapped)
        {
            break;
        }
    }
}

// Function to implement Kruskal's MST algorithm
int KruskalMST(int V, Edge edges[], int E)
{
    int result = 0; // Initialize MST weight sum

    // Allocate memory for parent and rank arrays
    int *parent = new int[V];
    int *rank = new int[V];

    // Initialize all parent pointers to point to themselves (single vertex sets)
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sort edges by weight in non-decreasing order using selection sort
    modifiedBubbleSort(edges, E);

    // Include edges in MST one by one
    for (int i = 0; i < E; i++)
    {
        int src = edges[i].src, dest = edges[i].dest;

        // Check if including this edge creates a cycle (ensures MST)
        if (find(parent, src) != find(parent, dest))
        {
            result += edges[i].weight;
            unionSets(parent, rank, src, dest);
        }
    }

    // Deallocate memory for parent and rank arrays
    delete[] parent;
    delete[] rank;

    return result;
}

int main()
{
    int V, E; // Number of vertices and edges

    ifstream infile("kuruskal.txt");

    if (!infile.is_open())
    {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    infile >> V;
    if (V <= 0)
    {
        cerr << "Invalid input! Please enter a positive integer for the number of vertices." << endl;
        return 1;
    }

    infile >> E;
    if (E <= 0)
    {
        cerr << "Invalid input! Please enter a positive integer for the number of edges." << endl;
        return 1;
    }

    // Allocate memory for edges array
    Edge *edges = new Edge[E];

    for (int i = 0; i < E; i++)
    {
        infile >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    infile.close();

    int mstWeight = KruskalMST(V, edges, E);

    cout << "Weight of the Minimum Spanning Tree (MST): " << mstWeight << endl;

    // Deallocate memory for edges array
    delete[] edges;

    return 0;
}
