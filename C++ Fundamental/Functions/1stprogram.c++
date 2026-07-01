#include<iostream>
 using namespace std;
 int sum(int x,int y){
    
    cout<<"HELLO WORLD\n";
    return x+y;
 }
  int main(){
    int a;
     cout<<"Enter 1st number :";
     cin>>a;
     int b;
     cout<<"Enter 2nd number :";
     cin>>b;
    cout<<"Sum is : "<<sum(a,b)<<endl;
  }