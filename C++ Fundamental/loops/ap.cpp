#include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter any number:";
    cin>>n;
    //1,3.5.7.9 ap..
    for(int i= 1;i<=2*n-1;i+=2){
        cout<<i<<"\t";
    }
    
 }