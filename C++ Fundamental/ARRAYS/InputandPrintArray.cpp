#include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter the number of elment : ";
    cin>>n;
    int her[n];
    cout<<"Enter a numbers : ";
    for(int i = 0;i<n;i++){
        cin>>her[i];
    }
    cout<<"YOUR inputs are :- ";
    for(int i =0;i<n;i++)
    {
        cout<<her[i]<<" ";
    }


 }