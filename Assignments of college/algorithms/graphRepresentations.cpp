// A simple representation of graph using STL
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v ){
  adj[u].push_back(v);
   adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}

int main()
{
    int V = 8;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 6);
    addEdge(adj, 3, 7);
    addEdge(adj, 4, 7);
    addEdge(adj, 5, 7);
    addEdge(adj, 6, 7);
    printGraph(adj, V);
    return 0;
}
