#include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter the number of elment :- ";
    cin>>n;
    int ayu[n];
    cout<<"Enter the element :- ";
    for(int i=0;i<n;i++){
        cin>>ayu[i];
    }
    cout<<"The reverse array is : ";
    //for reverse the array;
    for(int i = n-1;i>=0;i--){
        cout<<ayu[i]<<" ";
    }
    
 }