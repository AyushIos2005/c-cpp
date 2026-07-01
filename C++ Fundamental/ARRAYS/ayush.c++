#include<iostream>
 using namespace std;
 int main(){
    //int x,y,u,o,g,h;---> 2,34,56,4,35 
    int arr[5]={1,23,14,56,4};
    for(int i = 0;i<5;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=4;i++){
        cout<<arr[i]<<" ";
    }

 }