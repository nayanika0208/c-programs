#include<iostream>
using namespace std;

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



int main(){
  int i;
  struct node *array[16];
  struct node *array2[16];
for(i=0;i<16;i++){
  array[i]=makeSet(i+1);
}
for( i=0;i<15;i+=2){
  Union(array[i],array[i+1]);
}
for(i=0;i<16;i++){
  array2[i]=findSet(array[i]);
  cout<<"parent of "<<array[i]->data<<" of rank "<<array[i]->rank<<" is "<<array2[i]->data<<" of rank "<<array2[i]->rank<<endl;
}
for( i=0;i<13;i+=4){
  Union(array[i],array[i+2]);
}
cout<<"\n\n\n";
for(i=0;i<16;i++){
  array2[i]=findSet(array[i]);
  cout<<"parent of "<<array[i]->data<<" of rank "<<array[i]->rank<<" is "<<array2[i]->data<<" of rank "<<array2[i]->rank<<endl;
}



  return 0;
}
