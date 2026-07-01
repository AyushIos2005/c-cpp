#include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter any term of AP series : ";
    cin>>n;
    for(int i= 4;i <= 3*n + 1;i+=4){
        cout<<i<<"\t";
    }

 }