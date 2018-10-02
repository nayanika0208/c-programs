#include<iostream>
using namespace std;
struct node;
struct index;

struct node{
  struct index *ind;
  int data;
  struct node * next;
};
struct index{
  struct node *head;
  struct node *tail;
};
struct index *createSet(int num){

  struct index *set=(struct index*)malloc(sizeof(struct index));
  struct node *node1=(struct node*)malloc(sizeof(struct node));
  set->head=node1;
  set->tail=node1;
  node1->ind=set;
  node1->next=NULL;
  node1->data=num;
    return set;

}

struct node * FindSet(struct node* n){
  return n->ind->head;
}

struct index *UNION(struct index *n1,struct index *n2){
  struct node *t,*r;
  t=n1->head;
  r=n2->head;
  while((t->next)!= NULL){
    t=t->next;
  }
  t->next=r;
  while(r!=NULL){
    r->ind=n1;
    r=r->next;
  }
  free(n2);
  return n1;
}


int main(){
  struct index *set1,*set2,*set3,*set4,*set5,*set6;
  struct node *rep1,*rep2,*rep3;
  set1=createSet(23);
  set2=createSet(98);
  set3=createSet(77);
  set4=createSet(75);
  set5=createSet(980);
  set6=createSet(778);

  set1=UNION(set1,set2);
  set3=UNION(set3,set1);
  set4=UNION(set4,set5);
  set4=UNION(set6,set4);

  rep1=FindSet(set3->head->next);
  rep2=FindSet(set4->head->next);
  // cout<<"representative 3 "<<rep3->data<<endl;
  cout<<"representative 1 "<<rep1->data<<"\n representative 2 "<<rep2->data<<endl;


  return 0;
}
