#include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter a number of elment : ";
    cin>>n;
    int h2o[n];
    cout<<"Enter a numbers : ";
    for(int i = 0; i<n;i++){
        cin>>h2o[i];
     }
     int sum=0;
     for(int i = 0;i<n;i++){
        sum=sum+h2o[i];
     }
     cout<<"Sum of Elment are : "<<sum<<endl;
     
 }