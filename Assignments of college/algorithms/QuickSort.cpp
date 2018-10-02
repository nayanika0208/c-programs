#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(int &p,int &q){
  int t;
  t=p;
  p=q;
  q=t;
}

int Partition(int arr[],int low,int high){
  int x,i,j;
  x=arr[high];
  i=low-1;
  for(j=low;j<=high-1;j++){
    if(arr[j]>=x){
      i=i+1;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return i+1;

}
void QuickSort(int *arr,int p,int r){

  int q,i;
  for( i=0;i<=9;i++){
   cout<<arr[i]<<"  ";
  }
  cout<<endl;
  if(p<r){
    q=Partition(arr,p,r);
    for( i=0;i<=9;i++){
     cout<<arr[i]<<"  ";
    }
    cout<<endl;
      QuickSort(arr,p,q-1);
      for( i=0;i<=9;i++){
       cout<<arr[i]<<"  ";
      }
      cout<<endl;
      QuickSort(arr,q+1,r);
      for( i=0;i<=9;i++){
       cout<<arr[i]<<"  ";
      }
      cout<<endl;

  }
}
int main(){
  int i;
  int array[10]={23,12,45,6,1,2,8,7,3,90};
  QuickSort(array,0,9);
  for(i=0;i<=9;i++){
   cout<<array[i]<<"  ";
  }
  return 0;
}
