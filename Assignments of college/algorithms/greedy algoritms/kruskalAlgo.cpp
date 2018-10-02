#include <bits/stdc++.h>
using namespace std;


class Edge{
public:
  int src;
  int dest;
  int weight;

};
class Graph{
public:
  int V,E;
  //list of edges for the graph
  vector <Edge> edges;

  Graph(int V,int E){
    this->V=V;
    this->E=E;

  }

  void addEdge(int s,int d,int w){
    Edge e1;
    e1.src=s;
    e1.dest=d;
    e1.weight=w;

    edges.push_back(e1);
  }

};
struct node{
  struct node *parent;
  int data;
  int rank;
};

struct node *makeSet(int x){
  struct node*root=(struct node *)malloc(sizeof(struct node));
  root->parent=root;
  root->data=x;
  root->rank=0;
  return root;
}
struct node *findSet(struct node* node1){

  if(node1 != (node1->parent)){
    node1->parent=findSet(node1->parent);
  }
  return node1->parent;
}

void link(struct node* set1,struct node *set2){
  if(set1->rank > set2->rank){
    set2->parent=set1;
  }else {
    set1->parent=set2;
  }
   if(set1->rank==set2->rank){
     set2->rank++;
   }

}
void Union(struct node* a,struct node *b){
  link(findSet(a),findSet(b));
}
bool myComp(Edge a, Edge b)
{
    return a.weight < b.weight;
}

void kruskal(Graph g){
  vector <Edge> mst;
struct node *array[g.V];
  for(int i=0;i<g.V;i++){
    array[i]=makeSet(i);
  }
  sort(g.edges.begin(),g.edges.end(), myComp);

  for(int i=0;i<g.E;i++){
    struct node*x,*y;
    if(findSet(array[g.edges[i].src])!=findSet(array[g.edges[i].dest])){
      mst.push_back(g.edges[i]);
      Union(array[g.edges[i].src],array[g.edges[i].dest]);
    }
  }

cout<<"minium spanning tree will contain  "<<endl;
  for(int i=0;i<mst.size();i++){
  
  cout<<"edge "<<mst[i].src<<" to "<<mst[i].dest<<"of weight  "<<mst[i].weight<<endl;
}


}
int main(){

    Graph g1(5,7);
    g1.addEdge(0,1,5);
    g1.addEdge(0,2,1);
    g1.addEdge(1,2,2);
    g1.addEdge(3,1,3);
    g1.addEdge(3,4,6);
    g1.addEdge(3,2,7);
    g1.addEdge(2,4,4);

    kruskal(g1);



  return 0;
}
