// Apply Binary Search on 2D NxM array (A) having numbers stored in non-deceasing order
// under row-major scanning
#include<iostream>
#include <bits/stdc++.h>
#define ROWS 3
#define COLS 3
using namespace std;

void binarySearch2D(int matrix[ROWS][COLS],int key){
  int start = 0;
  int mid, row, col, value;
  int end = ROWS * COLS - 1;
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    row = mid / COLS;
    col = mid % COLS;
    value = matrix[row][col];

    if (value == key)
      {
        cout<<"key found at position a"<<row<<col<<endl;
        return;
      }
    if (value > key)
      end = mid - 1;
    else
      start = mid + 1;
  }
  cout<<"not found"<<endl;

}

int main(){
  int matrix[ROWS][COLS]={{1,2,3},
                          {5,6,7},
                          {9,10,14}};//two dimensional array
 int key=10; //search key
 int i, j; //counter variable
 int searchStatus; //1 if key is found, 0 otherwise.
 binarySearch2D(matrix,key);
return 0;
}
