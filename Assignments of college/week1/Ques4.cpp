//Given a sorted array and a number x, write a function that counts the occurrences of x in
//the array. Expected time complexity is O(logn).

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int first(int arr[], int low, int high, int x, int n)
{
    if(high >= low)
    {
        int mid = low + (high - low)/2;
        if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x)
            return mid;
        else if(x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        else
            return first(arr, low, (mid -1), x, n);
    }
    return -1;
}
int last(int arr[], int low, int high, int x, int n)
{
    if (high >= low)
    {
        int mid = low + (high - low)/2;
        if (( mid == n-1 || x < arr[mid+1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return last(arr, low, (mid -1), x, n);
        else
            return last(arr, (mid + 1), high, x, n);
    }
    return -1;
}

int main(){
  int array[10]={1,2,3,3,3,3,4,5,6,10};
  int key=3;
  cout<<first(array,0,9,key,10)<<endl;
  cout<<last(array,0,9,key,10);

  return 0;
}
