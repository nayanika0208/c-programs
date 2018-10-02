#include<bits/stdc++.h>
using namespace std;
#define NINF INT_MAX

void addEdge(vector<int> adj[],int u,int v ){
  adj[u].push_back(v);
}
int * toplogicalSort(vector<int> adj[], int V){
  int indeg[V];
  for(int i=0;i<V;i++){
    indeg[i]=0;
  }
  //indegree of every vertex is found
  for(int i=0;i<V;i++){
    for(int j=0;j<adj[i].size();j++)
    indeg[adj[i][j]]++;
  }

  queue <int> q;
  for(int i=0;i<V;i++){
    if(indeg[i]==0){
      q.push(i);
    }
  }
  vector <int> order;

  while(!q.empty()){
        int u = q.front();
        q.pop();
        order.push_back(u);


                for(int j=0;j<adj[u].size();j++){
                if ((--indeg[adj[u][j]]) == 0)
                {

                q.push(adj[u][j]);

               }
              }

  }

  for(int i=0;i<order.size();i++){
    cout<<order[i]<<" ";
  }
  cout<<endl;

}
int main(){

  int V = 6;
  vector<int> adj[V];
  addEdge(adj, 1, 0);
  addEdge(adj, 5, 0);
  addEdge(adj, 0, 3);
  addEdge(adj, 0, 4);
  addEdge(adj, 3, 2);
  addEdge(adj, 4, 2);



  toplogicalSort(adj,V);

  return 0;
}
