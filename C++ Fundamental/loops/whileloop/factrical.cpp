#include<iostream>
using namespace std;
  int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    int n_fact = 1;
    for(int i = 1;i<=n;i++){
        n_fact=n_fact*i;
       }
    cout<<"The factrical of "<<n<<"="<<n_fact;
  }