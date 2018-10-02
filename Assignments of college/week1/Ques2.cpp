#include<iostream>
#include <bits/stdc++.h>
using namespace std;


void sumequalsX(int arr[],int n,int x){
  int f=0,b=n-1,found=0;
  while(f<b){
    if((arr[f]+arr[b])==x){
      cout<<"array contains elements whose sum equals "<< x <<" are "
      <<arr[f]<<" and "<<arr[b]<<" at position "<<f+1<<" and "<<b+1<<" respectively"<<endl;
      found=1;
      f++;


    }
    else if((arr[f]+arr[b])<x){
      f++;
    }
    else if((arr[f]+arr[b])>x){
      b--;
    }
  }
  if(found==0){
    cout<<"no two elements in the given array whose sum is "<<x<<endl;
  }
}

int main(){
  int sortedArray[10]={2,4,5,7,15,16,17,32,44,70};
  sumequalsX(sortedArray,10,9);

  return 0;
}
