//WaP to count digits of given number.
#include<iostream>
 using namespace std;
  int main(){
    int n;
    cout<<"Enter the an  number : ";
    cin>>n;
     int count = 0;

    while(n != 0){
        n=n/10;
        count++;

    }
    cout<<count<<" digit";

  }