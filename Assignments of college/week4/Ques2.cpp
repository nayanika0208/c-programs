#include<bits/stdc++.h>
using namespace std;
#define V 5

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

void findCycle(int graph[][V],int v){
  struct node *array[v];
  for(int i=0;i<v;i++){
      array[i]=makeSet(i);
  }
  for(int i=0;i<v;i++){
    for(int j=i;j<v;j++){
      if(graph[i][j]==1){
        if((findSet(array[i])->parent)==(findSet(array[j]->parent))){
          cout<<"the array Contains cycle"<<endl;
        }
        else{
          Union(array[i],array[j]);
        }
      }
    }

}
  struct node *array2[v];
  for(int i=0;i<v;i++){
    array2[i]=findSet(array[i]);
    cout<<"parent of "<<array[i]->data<<" of rank "<<array[i]->rank<<" is "<<array2[i]->data<<" of rank "<<array2[i]->rank<<endl;
  }
}

int main(){

  int v = 5;
  int graph[V][V]={{0,1,0,0,0},
                  {1,0,1,0,0},
                  {0,1,0,1,0},
                  {0,0,1,0,1},
                  {1,0,0,1,0}};

        findCycle(graph,v);


  return 0;
}
