#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> arr, int low, int high, int x)
{
    if(high >= low)
    {
        int mid = low + (high - low)/2;
        if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x)
            return mid;
        else if(x > arr[mid])
            return binarySearch(arr, (mid + 1), high, x);
        else
            return binarySearch(arr, low, (mid -1), x);
    }
    return -1;
}

void answer(vector<int> ar1,int val,int n){
    int p=binarySearch(ar1,0,n-1,val);
    if(p==-1){
      std::vector<int>::iterator low1;
      low1=lower_bound(ar1.begin(), ar1.end(), val);
      cout<<"No "<<(low1-ar1.begin())+1;
    }
    else{
      cout<<"Yes "<<p+1;
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int Q;
    cin>>Q;

    for(int i=0;i<Q;i++){
        int q;
        cin>>q;
        answer(arr,q,N);
    }


    return 0;
}
