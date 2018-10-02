#include<bits/stdc++.h>

int merge(int arr[],int temp[],int left,int mid,int right){
  int i,j,k;
  int inversion =0;
  i=left;
  j=mid;
  k=left;

  while((i<=mid-1) && (k<=right) ){
    if(arr[i]<arr[j]){
      temp[k++]=arr[i++];
    }
    else{
      temp[k++]=arr[j++];
      inversion=inversion+(mid-i);
    }
  }
  while(i<=mid-1){
    temp[k++]=arr[i++];
  }
  while(j<=right){
  temp[k++]=arr[j++];
  }
  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return inversion;
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
  int mid, inv_count = 0;
  if (right > left)
  {
    /* Divide the array into two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = (right + left)/2;

    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);

    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}

int mergeSort(int arr[], int array_size)
{
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
int main(){
  int arr[] = {1, 20, 6, 4, 5};
  printf(" Number of inversions are %d \n", mergeSort(arr, 5));
  getchar();
  return 0;
}
