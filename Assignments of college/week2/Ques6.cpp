#include<iostream>
using namespace std;

int swap(int &a,int &b){
    int temp;
    temp = a;
    a = b;             // a/b refer to the parameters that were passed
    b = temp;          // modifying a reference is the same as modifiying the original
}
void minHeapify(int arr[],int i,int heap_size){
  int smallest;
  int l=2*i+1;
  int r=2*i+2;
  if(l>heap_size || r>heap_size){
    return;
  }
  cout<<"inside min heapify 1"<<endl;
  if(l<=heap_size && arr[l]<arr[i]){
    smallest=l;
  }else{
    smallest=i;
  }
  cout<<"inside min heapify 2"<<endl;
  if(r<=heap_size && arr[r]<arr[i]){
    smallest=r;
  }
  if(smallest != i){
    swap(arr[i],arr[smallest]);
  }
  cout<<"inside min heapify 3"<<endl;
  minHeapify(arr,smallest,heap_size);
}

void buildHeap(int arr[],int n){
  int heapsize=n;
  for(int i=(n/2);i>0;i--){
    cout<<"here "<<i<<endl;
    minHeapify(arr,i,heapsize);
  }
}

int findkth(int arr[],int k,int n){
  buildHeap(arr,k);
  for(int i=k+1;i<=n;i++){
    if(arr[i]>arr[0]){
      cout<<"1\n";
      swap(arr[i],arr[0]);
      cout<<"2\n";
      minHeapify(arr,0,i);
    }
  }
  return arr[0];
}
int main(){
int arr[10]={2,4,1,5,6,3,9,8,7,10};
// int k=5;
// cout<<"5th smallest elemnt is "<<findkth(arr,k-1,9);
buildHeap(arr,9);
  return 0;
}
