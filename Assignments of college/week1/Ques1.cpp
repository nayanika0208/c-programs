#include<iostream>
using namespace std;


struct node{
  int min;
  int max;
};
int minm(int a,int b){
  return a>b?b:a;
}
int maxm(int a,int b){
  return a>b?a:b;
}
struct node FindMinMax(int array[],int low,int high){
  struct node minmax,mml,mmr;
  int mid;
  if(low==(high)){
    minmax.min=array[low];
    minmax.max=array[low];
    return minmax;
  }
  if(low==(high-1)){
    minmax.min=minm(array[low],array[high]);
    minmax.max=maxm(array[low],array[high]);
    return minmax;
  }
  mid=(low+high)/2;
  mml=FindMinMax(array,low,mid);
  mmr=FindMinMax(array,mid+1,high);
  minmax.min=minm(mml.min,mmr.min);
  minmax.max=maxm(mml.max,mmr.max);

  return minmax;
}
int main(){
  int arr[] = {10, 11, 445, 1, 0, 30001};
   int arr_size = 6;
   struct node minmax = FindMinMax(arr, 0, arr_size-1);
   cout<<"Minimum element is "<< minmax.min<<endl;
   cout<<"Maximun element is "<< minmax.max;
  return 0;
}
