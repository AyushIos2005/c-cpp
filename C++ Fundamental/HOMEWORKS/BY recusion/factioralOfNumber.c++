#include<iostream>
 using namespace std;
  int fact(int m){
     if(m==0) return 1;
     cout<<m<<" ";
     return m*fact(m-1);
  }
 int main(){
    int n;
    cout<<"Enter a number for factorial : ";
    cin>>n;
    cout<<" i.e. "<<n<<"!"<<"= "<<fact(n)<<endl;
 }