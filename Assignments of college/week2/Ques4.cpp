#include<iostream>
using namespace std;

int QuicksortPartition(int arr[],int p,int r){
  int x=arr[r];
  int tmp;
  int i=p-1;
  int j;
  for(j=p;j<=r-1;j++){
    if(arr[j]<=x){
      i=i+1;
      tmp=arr[i];
      arr[i]=arr[j];
      arr[j]=tmp;

    }
  }
  tmp=arr[i+1];
  arr[i+1]=arr[r];
  arr[r]=tmp;
  return i+1;
}
int findkth(int arr[],int k,int p,int r){
  int j;
  if(p<r){
  if(k<j){
    j=QuicksortPartition(arr,p,j-1);
  }
  if(k=j){
    return j;
  }
  if(k<j){
    j=QuicksortPartition(arr,j+1,r);
  }
}
}

int main(){
  int arr[10]={2,4,5,6,3,1,21,5,7,8};
  int k=5;
  int ans=findkth(arr,k-1,0,9);
  cout<<"5th element is"<<arr[ans];


}
