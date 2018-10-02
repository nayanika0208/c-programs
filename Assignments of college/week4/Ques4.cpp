#include<bits/stdc++.h>
using namespace std;
#define NINF INT_MAX

class AdjListNode {
    int v;
    int weight;

public:
    AdjListNode(int v, int weight)
    {
      this->v=v;
      this->weight=weight;
    }
    int getV() { return v; }
    int getWeight() { return weight; }
};

class Graph {
    int V;
    // Pointer to an array containing adjacency lists
    list<AdjListNode>* adj;

public:
    Graph(int V) // Constructor
    {
      this->V = V;
      adj = new list<AdjListNode>[V];
   }

    void addEdge(int u, int v, int weight){
    AdjListNode node(v, weight);
    adj[u].push_back(node); // Add v to u's list
   }
   vector <int> toplogicalSort(list<AdjListNode>* adj,int V);

};

vector <int> toplogicalSort(list<AdjListNode>* adj, int V){
  int indeg[V];
  for(int i=0;i<V;i++){
    indeg[i]=0;
  }

        list<int>::iterator itr;
        for(int i=0;i<V;i++){
        for (itr = adj[i].begin(); itr != adj[i].end(); itr++)
                indeg[(*itr).getV()]++;
              }


          queue <int> q;
          for(int i=0;i<V;i++){
            if(indeg[i]==0){
              q.push(i);
            }
          }

vector<int> order;

  while(!q.empty()){
        int u = q.front();
        q.pop();
        order.push_back(u);


        list<int>::iterator itr2;
        for (itr2 = adj[u].begin(); itr2 != adj[u].end(); itr2++)

            // If in-degree becomes zero, add it to queue
            if (--in_degree[(*itr2).getV()] == 0)
                q.push((*itr2).getV());

               }
              }

  }

  return order;

}

int main(){

  return 0;
}
