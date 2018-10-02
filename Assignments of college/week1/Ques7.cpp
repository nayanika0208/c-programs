//You are given an array that represents elements of arithmetic progression in order. One
//element is missing in the progression. Find the missing number.
#include<iostream>
using namespace std;

int findMissingElement(int arr[],int low,int high,int d){

  int mid=(low+high)/2;
  if((arr[mid+1]-arr[mid])!=d){
    return (arr[mid] + d);
  }
  if (mid > 0 && arr[mid] - arr[mid-1] != d)
          return (arr[mid-1] + d);

  if (arr[mid] == arr[0] + mid*d)
        return findMissingElement(arr, mid+1, high, d);

  return findMissingElement(arr, low, mid-1, d);
}
int main() {
  int arr[6] = {2, 4, 8, 10, 12, 14};

      cout<<"The missing element is "<< findMissingElement(arr,0,5,2);
  return 0;
}
