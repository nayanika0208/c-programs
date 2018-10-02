#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void MinAndMAx(int array[],int n){
  int min,max;
  if(n%2==0){
        if(array[0]>array[1]){
          min=array[1];
          max=array[0];
        }
        else{
          min=array[0];
          max=array[1];
        }

        for(int i=2;i<n;i++){
          if(array[i]<min){
            min=array[i];
          }else if(array[i]>max){
            max=array[i];
          }

        }
  }
  if(n%2!=0){

          min=array[0];
          max=array[0];

        for(int i=1;i<n;i++){
          if(array[i]<min){
            min=array[i];
          }else if(array[i]>max){
            max=array[i];
          }
        }
  }

  cout<<"minimum "<<min<<"  maximum  "<<max<<endl;
}

void SecondMin(int array[],int n){

}

int main(){
  int array[10]={23,1,34,25,67,89,3,4,98,12};
  int n=sizeof(array)/sizeof(int);
  MinAndMAx(array,n);

  return 0;
}
