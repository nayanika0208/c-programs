//A sorted array is rotated clockwise arbitrarily. Find the minimum element in it.
#include<iostream>
using namespace std;

int findMin(int array[],int low,int high){
  int mid;
  mid=(low+high)/2;
  if(array[mid-1]>array[mid]){
    return array[mid];
  }
  else if(array[mid]>array[mid+1]){
    return array[mid+1];
  }
  else if(array[mid]<array[high]){
  return findMin(array,low,mid-1);
}
 else {
   return findMin(array,mid+1,high);
 }
 return -1;
}
int main(){
  int a[10]={234,2345,5,6,7,8,9,21,56,78};
  int mi=findMin(a,0,9);
  cout<<"minimum is "<<mi<<endl;
  return 0;
}
