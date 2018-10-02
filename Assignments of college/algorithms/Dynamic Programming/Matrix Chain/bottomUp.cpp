#include<iostream>
#define INT_MAX 2147483647;
using namespace std;
int p[5]={1,2,1,4,1};
int n=4;

void printOptimalParens(int s[][n+1],int i,int j){
  if(i==j){
    cout<<"A"<<i;
  }
  else{
    cout<<"(";
    printOptimalParens(s,i,s[i][j]);
    printOptimalParens(s,s[i][j]+1,j);
    cout<<")";
  }
}

void matrixChain(int p[]){

  int i,j,k,l,q;
  int m[n+1][n+1];
  int s[n+1][n+1];
  for(i=1;i<n+1;i++){
    m[i][i]=0;
  }
  for(l=2;l<n+1;l++){
    for(i=1;i<=n-l+1;i++){
      j=i+l-1;
      m[i][j]=INT_MAX;

         for(k=i;k<=j-1;k++){
           q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
           if(q<m[i][j]){
             m[i][j]=q;
             s[i][j]=k;
           }
           }
         }
       }

    printOptimalParens(s,1,n);


}

int main(){

  matrixChain(p,4);


  return 0;
}
