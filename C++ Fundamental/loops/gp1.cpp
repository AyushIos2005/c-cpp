#include<iostream>
#include<math.h>
 using namespace std;
 int main(){
        int n;
        cout<<"Enter any term (for GP): ";
        cin>>n;
        //gp kiyr liye 
        for(float i= 1;i<=pow(2,n-1);i=i*2){
            cout<<i<<"\t";
        }
 }