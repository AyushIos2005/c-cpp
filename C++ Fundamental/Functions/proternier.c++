#include<iostream>
 using namespace std;
 int main(){
    int x=3;
    int *p;
    p=&x;
    cout<<x<<endl;
    *p=23;
    cout<<x<<endl;
 }
 