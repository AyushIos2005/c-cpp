#include<iostream>
 using namespace std;
 int main(){
     int a;
     cout<<"Enter the number of element : ";
     cin>>a;
     int as[a];
     cout<<"Enetre the element : ";
     for(int i = 0;i<a;i++){
        cin>>as[i];
     }
     cout<<"Postive terms  are : ";
     for(int i=0;i<a;i++){
        if(as[i]>0) cout<<as[i]<<" ";
     }
 }