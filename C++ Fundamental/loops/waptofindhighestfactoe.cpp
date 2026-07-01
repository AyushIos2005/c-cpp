#include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter any anmber:";
    cin>>n;
    int fac = 1;
     for(int i = n/2;i>=1;i--){
        if(n%i==0){
            cout<<i<<"\t";
            break;//get out the loop if while a condition full filled or not ...
            
        }
     }
    return 0;
 }