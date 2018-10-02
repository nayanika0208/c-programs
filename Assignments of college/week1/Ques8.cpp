// . A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a
// point strictly decreasing. A Bitonic Point is a point in bitonic sequence before which
// elements are strictly increasing and after which elements are strictly decreasing. Find
// bitonic point in a bitonic sequence.

#include<iostream>
using namespace std;

int findBitonicPoint(int arr[],int low,int high){

  int mid;
  mid=(high+low)/2;
  if( arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
    return mid;
  }
  if( arr[mid] < arr[mid+1] ){
    return findBitonicPoint(arr,mid+1,high);
  }
  return findBitonicPoint(arr,low,mid-1);

}
int main(){
  int arr[9] = {2,3,4, 8, 9,10, 7, 6,1};
  int b=findBitonicPoint(arr,0,8);
  cout<<arr[b]<<endl;
  return 0;
}
