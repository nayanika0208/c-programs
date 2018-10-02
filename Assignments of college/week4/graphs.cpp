#include <bits/stdc++.h>
using namespace std;


void BFS(int rootVertex,int graph[5][5],int visited[5]){
  int u,j;
  queue <int> que;
  for(int i=0;i<5;i++){
    visited[i]=0;
  }
  u=rootVertex;
  visited[u]=1;
  while(1){
    for(j=0;j<5;j++){
      if(graph[u][j]==1){
        if(visited[j]==0){
          que.push(j);
          visited[j]=1;
        }
      }

    }
    cout<<" "<<u<<"then"<<endl;
    if(que.empty()){
      return;
      }
    u=que.front();
    que.pop();
  }


}

void DFS(int v,int graph[5][5],int visited[5]){
  visited[v]=1;
  cout<<" "<<v<<"then"<<endl;
  for(int j=0;j<5;j++){
    if(graph[v][j]==1){
      if(visited[j]==0){
        DFS(j,graph,visited);

      }
    }

  }

}




int main(){
  int graph[5][5]={{0,1,0,0,1},
                    {1,0,1,0,0},
                    {0,1,0,1,1},
                   {0,0,1,0,1},
                 {1,0,1,1,0}};
  int visited[5];
  // BFS(1,graph,visited);
  for(int i=0;i<5;i++){
    visited[i]=0;
  }
  DFS(0,graph,visited);
  return 0;

}
