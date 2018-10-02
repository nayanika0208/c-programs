#include<iostream>
using namespace std;
#include<tuple>
// #include<pair>

int main(){
   // pair <string,int> p1;
   // pair <string,string> p2;
   // p1=make_pair("hello",56);
   // p2=make_pair("hiiii","nayanika");
   // cout<<"p1   "<<p1.first<<" "<<p1.second<<endl;
   // cout<<"p2   "<<p2.first<<" "<<p2.second<<endl;
   tuple<string,int,int>t1;
   t1=make_tuple("nayanika",21,87);
   cout<<get <0>(t1)<<endl;
   cout<<get <1>(t1)<<endl;
   cout<<get <2>(t1)<<endl;



  return 0;
}
