#include<iostream>
#include<array>
using namespace std;
int main(){

array <int,9> data;
array <int,9> data2;
data={4,7,8,9,9,8,7,87};
data2={1,4,5,67,5,9,0,8};
data.swap(data2);
for(int i=0;i<data.size();i++)
cout<<data.at(i)<<endl;
return 0;
}
